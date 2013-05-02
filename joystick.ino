#include <Servo.h>

const int clawPin = 4;     // the number of the pushbutton pin
const int joyStickXPin = A1;
const int joyStickYPin = A2;

const int turnServoPin =  9;      // the number of the LED pin
const int liftServoPin=10;
const int clawServoPin=11;

const int clawClosedAngle = 110;
const int clawOpenedAngle =70;

const int armLowAngle=20;
const int armHiAngle=80;

//const int baseClockWiseAngle=20;
//const int baseCClockWiseAngle=180;

const int baseClockWiseAngle=100+20;
const int baseCClockWiseAngle=100-30;

const int joyStickMinValue=380;
const int joyStickRange=1023-joyStickMinValue;

// variables will change:

Servo turnServo;  // create servo object to control a servo 
Servo liftServo;  // create servo object to control a servo 
Servo clawServo;  // create servo object to control a servo 
// a maximum of eight servo objects can be created 


void setup() {

  Serial.begin(9600);
  // initialize the pushbutton pin as an input:
  pinMode(clawPin, INPUT);
  digitalWrite(clawPin, HIGH); // turn on pullup resistors
  turnServo.attach(turnServoPin);  // attaches the servo on pin to the servo object 
  liftServo.attach(liftServoPin);  // attaches the servo on pin to the servo object 
  clawServo.attach(clawServoPin);  // attaches the servo on pin to the servo object 
  //Auto
  turnServo.write((baseClockWiseAngle+baseCClockWiseAngle)/2);
  clawServo.write(clawOpenedAngle);
  liftServo.write(armHiAngle);
  delay(500);
  clawServo.write(clawOpenedAngle);
  liftServo.write(armLowAngle);
  delay(500);
  clawServo.write(clawClosedAngle);
  delay(500);
  liftServo.write(armHiAngle);
  delay(1000);
  turnServo.write(120);
  clawServo.write(clawOpenedAngle);
  liftServo.write(armHiAngle);
  delay(500);
  clawServo.write(clawOpenedAngle);
  liftServo.write(armLowAngle);
  delay(500);
  
  delay(5000);
  
}




void loop(){
  long turnAngle = baseCClockWiseAngle+(long)(analogRead(joyStickXPin)-joyStickMinValue)*(baseClockWiseAngle-baseCClockWiseAngle)/joyStickRange;
  long liftAngle = armHiAngle+(long)(analogRead(joyStickYPin)-joyStickMinValue)*(armLowAngle-armHiAngle)/joyStickRange;
  if (liftAngle<armLowAngle) {
    liftAngle=armLowAngle;
  }
  int clawPinState=digitalRead(clawPin);
  
  Serial.println(liftAngle+","+turnAngle);
  
  turnServo.write(turnAngle);
  liftServo.write(liftAngle);
   
   if (clawPinState==HIGH) {     
     clawServo.write(clawOpenedAngle);//released
   } else {
     clawServo.write(clawClosedAngle); 
   }
  delay(10); //Millsecounds!!!!
}


