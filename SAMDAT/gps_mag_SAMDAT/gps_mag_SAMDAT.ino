#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <SD.h>

static const int RXPin = 11, TXPin = 9;
static const uint32_t GPSBaud = 9600;

const int dataPin = A0, chipSelect = 53;
float V_out = 0, R1 = 100, B = 0;

float latt = 0, lon = 0; 
int mm = 0, dd = 0, yy = 0, h = 0, m = 0, s = 0, cs = 0, ii;


// The TinyGPS++ object
TinyGPSPlus gps;

// The serial connection to the GPS device
SoftwareSerial ss(RXPin, TXPin);


// Set-up
void setup()
{
  // Initialize serial monitor
  Serial.begin(9600); 
  
  // Initialize serial conneciton to GPS
  ss.begin(GPSBaud);

  // Initialize SD card
  Serial.println("Initializing SD card...");
  pinMode(chipSelect, HIGH);
  
  // check that the memory card exists and is usable
  if (!SD.begin(chipSelect))
  {
    Serial.println("Card failed, or not present");
    // stop sketch
    return;
  }
  Serial.println("memory card is ready");
  if (SD.exists("mag.TXT")) 
  {
    SD.remove("mag.TXT");
  }


  Serial.println(F("Sats HDOP Latitude   Longitude   Fix  Date       Time     Date Alt    Course Speed Card  Distance Course Card  Chars Sentences Checksum"));
  Serial.println(F("          (deg)      (deg)       Age                      Age  (m)    --- from GPS ----  ---- to London  ----  RX    RX        Fail"));
  Serial.println(F("---------------------------------------------------------------------------------------------------------------------------------------"));
  
  File dataFile = SD.open("mag.TXT", FILE_WRITE);

  if (dataFile) {
    dataFile.println(F("FieldStrength(nT), Satellites, HDOP, Latitude(deg), Longitude(deg), Fix, Altitude(m), Hour, Minute, Second, Centisecond, day, month, year"));
    dataFile.println(F("----------------------------------------------------------------------------------------------------------------------------------------------"));
    dataFile.close();
  }
}


// Methods for magnetometer and GPS
float getMag()
{
  V_out = analogRead(dataPin);   // read the input pin
  B = V_out / (8*12.2*R1); // mT
  B = B*pow(10,6);

  return B;
}

static void smartDelay(unsigned long ms)
{
  unsigned long start = millis();
  do 
  {
    while (ss.available())
      gps.encode(ss.read());
  } while (millis() - start < ms);
}

static void printInt(unsigned long val, bool valid, int len)
{
  char sz[32] = "*****************";
  if (valid)
    sprintf(sz, "%ld", val);
  sz[len] = 0;
  for (int i=strlen(sz); i<len; ++i)
    sz[i] = ' ';
  if (len > 0) 
    sz[len-1] = ' ';
  Serial.print(sz);
  smartDelay(0);
}

static void printFloat(float val, bool valid, int len, int prec)
{
  if (!valid)
  {
    while (len-- > 1)
      Serial.print('*');
    Serial.print(' ');
  }
  else
  {
    Serial.print(val, prec);
    int vi = abs((int)val);
    int flen = prec + (val < 0.0 ? 2 : 1); // . and -
    flen += vi >= 1000 ? 4 : vi >= 100 ? 3 : vi >= 10 ? 2 : 1;
    for (int i=flen; i<len; ++i)
      Serial.print(' ');
  }
  smartDelay(0);
}

static void printDateTime(TinyGPSDate &d, TinyGPSTime &t)
{
  if (!d.isValid())
  {
    Serial.print(F("********** "));
  }
  else
  {
    char sz[32];
    sprintf(sz, "%02d/%02d/%02d ", d.month(), d.day(), d.year());
    Serial.print(sz);
  }
  
  if (!t.isValid())
  {
    Serial.print(F("******** "));
  }
  else
  {
    char sz[32];
    sprintf(sz, "%02d:%02d:%02d ", t.hour(), t.minute(), t.second());
    Serial.print(sz);
  }

  printInt(d.age(), d.isValid(), 5);
  smartDelay(0);
}

static void printStr(const char *str, int len)
{
  int slen = strlen(str);
  for (int i=0; i<len; ++i)
    Serial.print(i<slen ? str[i] : ' ');
  smartDelay(0);
}

/////////////////////////////////////////////////////////
void loop()
{
  static const double LONDON_LAT = 51.508131, LONDON_LON = -0.128002;

  printInt(gps.satellites.value(), gps.satellites.isValid(), 5);
  printInt(gps.hdop.value(), gps.hdop.isValid(), 5);
  printFloat(gps.location.lat(), gps.location.isValid(), 11, 6);
  printFloat(gps.location.lng(), gps.location.isValid(), 12, 6);
  printInt(gps.location.age(), gps.location.isValid(), 5);
  printDateTime(gps.date, gps.time);
  printFloat(gps.altitude.meters(), gps.altitude.isValid(), 7, 2);
  printFloat(gps.course.deg(), gps.course.isValid(), 7, 2);
  printFloat(gps.speed.kmph(), gps.speed.isValid(), 6, 2);
  printStr(gps.course.isValid() ? TinyGPSPlus::cardinal(gps.course.value()) : "*** ", 6);

  unsigned long distanceKmToLondon =
    (unsigned long)TinyGPSPlus::distanceBetween(
      gps.location.lat(),
      gps.location.lng(),
      LONDON_LAT, 
      LONDON_LON) / 1000;
  printInt(distanceKmToLondon, gps.location.isValid(), 9);

  double courseToLondon =
    TinyGPSPlus::courseTo(
      gps.location.lat(),
      gps.location.lng(),
      LONDON_LAT, 
      LONDON_LON);

  printFloat(courseToLondon, gps.location.isValid(), 7, 2);

  const char *cardinalToLondon = TinyGPSPlus::cardinal(courseToLondon);
  
  printStr(gps.location.isValid() ? cardinalToLondon : "*** ", 6);
  
  printInt(gps.charsProcessed(), true, 6);
  printInt(gps.sentencesWithFix(), true, 10);
  printInt(gps.failedChecksum(), true, 9);
  Serial.println();
    
  File dataFile = SD.open("MAG.TXT", FILE_WRITE);
  
  if (dataFile) 
  {
      dataFile.print(getMag());
      dataFile.print(F(","));
      dataFile.print(gps.satellites.value());
      dataFile.print(F(","));
      dataFile.print(gps.hdop.value());
      dataFile.print(F(","));
      dataFile.print(gps.location.lat());
      dataFile.print(F(","));
      dataFile.print(gps.location.lng());
      dataFile.print(F(","));
      dataFile.print(gps.location.age());
      dataFile.print(F(","));
      dataFile.print(gps.altitude.meters());
      dataFile.print(F(","));
      dataFile.print(gps.time.hour());
      dataFile.print(F(","));
      dataFile.print(gps.time.minute());
      dataFile.print(F(","));
      dataFile.print(gps.time.second());
      dataFile.print(F(","));
      dataFile.print(gps.time.centisecond());
      dataFile.print(F(","));
      dataFile.print(gps.date.day());
      dataFile.print(F(","));
      dataFile.print(gps.date.month());
      dataFile.print(F(","));
      dataFile.print(gps.date.year());
      dataFile.println();
      dataFile.close();
  }

  smartDelay(250);

  if (millis() > 5000 && gps.charsProcessed() < 10) {
    Serial.println(F("No GPS data received: check wiring"));
  }
    
}
