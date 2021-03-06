#pragma config(Hubs,  S2, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S1,     gyro,                sensorI2CCustom9V)
#pragma config(Motor,  mtr_S2_C1_1,     left_M1,       tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S2_C1_2,     left_M2,       tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S2_C2_1,     right_M1,      tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S2_C2_2,     right_M2,      tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S2_C3_1,     arm_rotationMotor, tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S2_C3_2,     motorI,        tmotorNormal, openLoop)
#pragma config(Servo,  srvo_S2_C4_1,    plow_1,               tServoStandard)
#pragma config(Servo,  srvo_S2_C4_2,    plow_2,               tServoStandard)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include <JoystickDriver.c>

void initializeRobot();

task main() {

  initializeRobot();
  waitForStart();
  int servoVal = 255;

  while(true) {
    getJoystickSettings(joystick);
    int leftDrive = -1 * joystick.joy1_y1;
    int rightDrive = joystick.joy1_y2;

    motor[left_M1] = leftDrive;
    motor[left_M2] = leftDrive;
    motor[right_M1] = rightDrive;
    motor[right_M2] = rightDrive;

    if (joy1Btn(2)) {
      servoVal -= 1;
    }
    if (joy1Btn(4)) {
      servoVal += 1;
    }
/*    else {
      if (joy1Btn(4)) {
        servoVal += 1;
      }
    } */
    if (servoVal < 0) {
      servoVal = 0;}

    if (servoVal > 255) {
      servoVal = 255;}
   }


   servo[plow_1] = servoVal;
   servo[plow_2] = 255 - servoVal;

   if (joy1Btn(1)) {
     motor[motorA] = 100;
   }
   else {
     if (joy1Btn(3)) {
       motor[motorA] = -100;
     }
     else {
       motor[motorA] = 0;
     }
   }
}

void initializeRobot() {
  servo[plow_1] = 127;
  servo[plow_2] = 128;
  return;
}
