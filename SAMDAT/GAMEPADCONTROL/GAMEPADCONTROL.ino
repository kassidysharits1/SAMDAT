#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>


char data;

// Back motors
int motor1pin1 = 24;
int motor1pin2 = 26;
int motor2pin1 = 28;
int motor2pin2 = 30;

int ENA1 = 6;
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
int turnLen = 680;
int stopLen = 1000;


void setup() {
  Serial.begin(9600);
  Serial3.begin(9600);
  Dabble.begin(Serial3);
  
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
  // put your main code here, to run repeatedly:   
  Dabble.processInput();  // This line is crucial in grabbing our data  
  
  while (GamePad.isUpPressed()) {
    Serial.println("Forward");
    analogWrite(ENA1, inside);
    analogWrite(ENB1, inside);
    analogWrite(ENA2, inside);
    analogWrite(ENB2, inside);
  
    digitalWrite(motor1pin1, HIGH);
    digitalWrite(motor1pin2, LOW);
    digitalWrite(motor3pin1, HIGH);
    digitalWrite(motor3pin2, LOW);
  
    digitalWrite(motor2pin1, HIGH);
    digitalWrite(motor2pin2, LOW);
    digitalWrite(motor4pin1, HIGH);
    digitalWrite(motor4pin2, LOW);

    Dabble.processInput();
  }
  
  while (GamePad.isDownPressed()) {
    Serial.println("Backwards");
    analogWrite(ENA1, inside);
    analogWrite(ENB1, inside);
    analogWrite(ENA2, inside);
    analogWrite(ENB2, inside);
    
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, HIGH);
    digitalWrite(motor3pin1, LOW);
    digitalWrite(motor3pin2, HIGH);
  
    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, HIGH);
    digitalWrite(motor4pin1, LOW);
    digitalWrite(motor4pin2, HIGH);

    Dabble.processInput();
  }

  while (GamePad.isLeftPressed())
  {
    Serial.print("Left");
    analogWrite(ENA1, insideTurn);
    analogWrite(ENB1, insideTurn);
    analogWrite(ENA2, insideTurn);
    analogWrite(ENB2, insideTurn);
    
    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, HIGH);
    
    digitalWrite(motor3pin1, HIGH);
    digitalWrite(motor3pin2, LOW);
    digitalWrite(motor4pin1, LOW);
    digitalWrite(motor4pin2, HIGH);

    Dabble.processInput();
  }

  while (GamePad.isRightPressed())
  {
    Serial.print("Right");
    analogWrite(ENA1, insideTurn);
    analogWrite(ENB1, insideTurn);
    analogWrite(ENA2, insideTurn);
    analogWrite(ENB2, insideTurn);
    
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, HIGH);
    
    digitalWrite(motor3pin1, LOW);
    digitalWrite(motor3pin2, HIGH);
    digitalWrite(motor4pin1, HIGH);
    digitalWrite(motor4pin2, LOW);

    Dabble.processInput();
  }

  while (GamePad.isSquarePressed())
  {
    Serial.println("Square");
  }

  while (GamePad.isCirclePressed())
  {
    Serial.println("Circle");
    Dabble.processInput();
  }

  while (GamePad.isCrossPressed())
  {
    Serial.print("Cross");
  }

  while (GamePad.isTrianglePressed())
  {
    Serial.print("Triangle");
  }

  while (GamePad.isSelectPressed())
  {
    Serial.print("Start");
  }

  if (GamePad.isStartPressed())
  {
    Serial.println("Select");
    Serial.println("Starting Suvey");
    
    int i = 0;
    while (i < 4) {
      //Forward
      Serial.println("i");
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

      i = i+1;
    }


  
    Dabble.processInput();
  }
  else {
    Serial.println("Stop");
    
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, LOW);
    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, LOW);
    
    digitalWrite(motor3pin1, LOW);
    digitalWrite(motor3pin2, LOW);
    digitalWrite(motor4pin1, LOW);
    digitalWrite(motor4pin2, LOW);
  }
}


void Survey(int i) {
  for (int i = 0; i++; i<4) {
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
}
