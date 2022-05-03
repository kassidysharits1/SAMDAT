// Back motors
int motor1pin1 = 24;
int motor1pin2 = 26;
int motor2pin1 = 28;
int motor2pin2 = 30;

int ENA1 = 3;
int ENB1 = 5;


// Back motors
int motor3pin1 = 32;
int motor3pin2 = 34;
int motor4pin1 = 36;
int motor4pin2 = 38;

int ENA2 = 10;
int ENB2 = 9;


//Speed
int grass = 100;
int grassTurn = 250;
int inside = 40;
int insideTurn = 250;

int lineLen = 5000;
int turnLen = 650;
int stopLen = 1000;

void setup() {
  // put your setup code here, to run once:
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);

  pinMode(motor3pin1, OUTPUT);
  pinMode(motor3pin2, OUTPUT);
  pinMode(motor4pin1, OUTPUT);
  pinMode(motor4pin2, OUTPUT);
  
  pinMode(ENA1, OUTPUT); 
  pinMode(ENB1, OUTPUT);
  pinMode(ENA2, OUTPUT); 
  pinMode(ENB2, OUTPUT);
}

void loop() {
  //Forward
  analogWrite(ENA1, inside); //ENA pin
  analogWrite(ENB1, inside); //ENB pin
  analogWrite(ENA2, inside); //ENA pin
  analogWrite(ENB2, inside); //ENB pin
  delay(stopLen);
  
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor3pin1, HIGH);
  digitalWrite(motor3pin2, LOW);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  digitalWrite(motor4pin1, HIGH);
  digitalWrite(motor4pin2, LOW);
  delay(lineLen);
  
  //Stop
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor3pin1, LOW);
  digitalWrite(motor3pin2, LOW);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);
  digitalWrite(motor4pin1, LOW);
  digitalWrite(motor4pin2, LOW);
  delay(stopLen);
  
  //Turn left
  analogWrite(ENA1, insideTurn); //ENA pin
  analogWrite(ENB1, insideTurn); //ENB pin
  analogWrite(ENA2, insideTurn); //ENA pin
  analogWrite(ENB2, insideTurn); //ENB pin
  delay(stopLen);
  
  //digitalWrite(motor1pin1, HIGH);
  //digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
  
  digitalWrite(motor3pin1, HIGH);
  digitalWrite(motor3pin2, LOW);
  digitalWrite(motor4pin1, LOW);
  digitalWrite(motor4pin2, HIGH);
  delay(turnLen);

  //Stop
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor3pin1, LOW);
  digitalWrite(motor3pin2, LOW);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);
  digitalWrite(motor4pin1, LOW);
  digitalWrite(motor4pin2, LOW);
  delay(stopLen);
}
