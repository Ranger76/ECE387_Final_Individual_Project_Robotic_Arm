/*
 * This script was written by Takdanai Tantiyartyanontha.
 */

// .writeMicroseconds(1510) makes the 
// continuous servo 1 stop
// values above 1510 = ccw
// values below 1510 = cw
// servo 1 was used as the base_0 servo
//
// .writeMicroseconds(1400) as initial position
// for base_1 servo. 
// value higher angle limit = 500
// value lower angle limit = 1600
//
// .writeMicroseconds(950) as initial position
// for arm servo. 
// value higher angle limit = 1400
// value lower angle limit = 900
//
// .writeMicroseconds(650) for the
// gripper servo to clamp
// values above 650 = unclamp

// Calling the Arduino Servo Library
#include <Servo.h>;

// Declaring and/or initializing variable to be used 
// as pin assignments and values written to the 
// assigned pins.
int flexPin0 = 0;
int flexPin1 = 1;
int flexPin2 = 2;
int flexPin3 = 3;
int flexPin4 = 4;
int flexPin5 = 5;
int flexRead0;
int flexRead1;
int flexRead2;
int flexRead3;
int flexRead4;
int flexRead5;
//
// Declaring and initializing servo signals.
int angle_base_0 = 1510;
int angle_base_1 = 1400;
int angle_arm = 950;
int angle_gripper = 950;
Servo base_0; // base servo to rotate platform
Servo base_1; // base servo to rotate arm
Servo arm; // arm servo to adjust second arm angle
Servo gripper; // servo used to contorl gripping

void setup(void)
{
  // put your setup code here, to run once:
  // Setting the baud rate.
  Serial.begin(9600);
  
  // Set up servo pins for each component.
  base_0.attach(6);
  base_1.attach(9);
  arm.attach(10);
  gripper.attach(11);
}

void loop()
{

  // put your main code here, to run repeatedly:
  // Assigning the registered input values from 
  // pin A0 and A1 to repective variables.

  // Reading input values from the flex sensors.
  flexRead0 = analogRead(flexPin0);
  flexRead1 = analogRead(flexPin1);
  flexRead2 = analogRead(flexPin2);
  flexRead3 = analogRead(flexPin3);
  flexRead4 = analogRead(flexPin4);
  flexRead5 = analogRead(flexPin5);
  
  // Checking the variables with the input values.
  Serial.println("flexRead0:");
  Serial.println(flexRead0);
  Serial.println("flexRead1:");
  Serial.println(flexRead1);
  Serial.println("flexRead2:");
  Serial.println(flexRead2);
  Serial.println("flexRead3:");
  Serial.println(flexRead3);
  Serial.println("flexRead4:");
  Serial.println(flexRead4);
  Serial.println("flexRead5:");
  Serial.println(flexRead5);

  // testing angle control
//  angle_base_0 = 1510;
//  angle_gripper = 750;
//  angle_gripper = 950;

  // Checking angle signal outputs.
  base_0.writeMicroseconds(angle_base_0);
  Serial.println("angle_base_0:");
  Serial.println(angle_base_0);
  base_1.writeMicroseconds(angle_base_1);
  Serial.println("angle_base_1:");
  Serial.println(angle_base_1);
  arm.writeMicroseconds(angle_arm);
  Serial.println("angle_arm:");
  Serial.println(angle_arm);
  gripper.writeMicroseconds(angle_gripper);
  Serial.println("angle_gripper:");
  Serial.println(angle_gripper);
  
  // Mapping base_0 motor: angle_base_0 
  // for flexSensor 5.
  if (flexRead5 >= 550 && flexRead2 >= 550) {
    angle_base_0 = 1545;
  }
  else if (flexRead5 >= 500 && flexRead2 >= 550) {
    angle_base_0 = 1535;
  }
  else if (flexRead5 >= 550 && flexRead2 < 550) {
    angle_base_0 = 1475;
  }
  else if (flexRead5 >= 500 && flexRead2 < 550) {
    angle_base_0 = 1485;
  }
  else if (flexRead5 < 500) {
    angle_base_0 = 1510;
  }
  else {
  }

  // Mapping arm motor: angle_base_1
  // for flexSensor 1.
  if (flexRead1 >= 600 && flexRead2 >= 550) {
    angle_base_1 = angle_base_1 + 100;
  }
  else if (flexRead1 >= 500 && flexRead2 >= 550) {
    angle_base_1 = angle_base_1 + 50;
  }
  else if (flexRead1 >= 600 && flexRead2 < 550) {
    angle_base_1 = angle_base_1 - 100;
  }
  else if (flexRead1 >= 500 && flexRead2 < 550) {
    angle_base_1 = angle_base_1 - 50;
  }
  else {
  }

  // Preventing arm from rotating pass 180 degrees
  // for arm motor
  if (angle_base_1 >= 1400) {
    angle_base_1 = 1400;
  }
  else if (angle_base_1 <= 900) {
    angle_base_1 = 900;
  }
  else {
  }

  // Mapping arm motor: angle_arm 
  // for flexSensor 3.
  if (flexRead3 >= 600 && flexRead2 >= 550) {
    angle_arm = angle_arm - 100;
  }
  else if (flexRead3 >= 500 && flexRead2 >= 550) {
    angle_arm = angle_arm - 50;
  }
  else if (flexRead3 >= 600 && flexRead2 < 550) {
    angle_arm = angle_arm + 100;
  }
  else if (flexRead3 >= 500 && flexRead2 < 550) {
    angle_arm = angle_arm + 50;
  }
  else {
  }

  // Preventing arm from rotating pass 180 degrees
  // for arm motor
  if (angle_arm >= 1600) {
    angle_arm = 1600;
  }
  else if (angle_arm <= 500) {
    angle_arm = 500;
  }
  else {
  }

  // Mapping gripper motor: angle_base_0 
  // for flexSensor 4.
  if (flexRead4 >= 500 && flexRead2 >= 550) {
    angle_gripper = 950;
  }
  else if (flexRead4 >= 500 && flexRead2 < 550) {
      angle_gripper = 650;
  }
  else {
  }
  
}







