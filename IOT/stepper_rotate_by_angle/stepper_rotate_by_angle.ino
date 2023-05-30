
/**
 * Stepper Motor rotate by angle in degree
 *
 * This program drives a stepper motor.
 * The motor is attached to digital pins 8 - 11 of the Arduino.
 *
 * The motor should rotate nearly x degree.
 */

#include <Stepper.h>

/* The number of steps per revolution, set this as per the motor you have */
const int stepsPerRevolution = 200;

/* initialize the stepper library on pins 8 through 11 */
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

void setup() {
  /* The speed at 60 rpm */
  myStepper.setSpeed(60);
  
  /* initializing the serial port */
  Serial.begin(9600);
}

/* rotate stepper motor to certain angle */
void rotateByAngle(int angle){
  int steps=(stepsPerRevolution*angle)/360;
  myStepper.step(steps);
}
void loop() {
  rotateByAngle(45);
  delay(100);
}
