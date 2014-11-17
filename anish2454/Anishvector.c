// Copyright Stuy Fission 310
/**
 * Authored by Alvin Lin (alvin.lin@stuypulse.com)
 * http://omgimanerd.github.io
 * http://310fission.com
 * Basic template for our vector drive.
 */
#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Hubs,  S2, HTMotor,  HTMotor,  none,     none)
#pragma config(Hubs,  S3, HTServo,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Sensor, S3,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     frontLeft,    tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     frontRight,   tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S2_C1_1,     backLeft,     tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S2_C2_1,     backRight,    tmotorNormal, openLoop)
#pragma config(Servo,  srvo_S3_C1_1,    frontRightS,           tServoStandard)
#pragma config(Servo,  srvo_S3_C1_2,    frontLeftS,            tServoStandard)
#pragma config(Servo,  srvo_S3_C1_3,    backLeftS,             tServoStandard)
#pragma config(Servo,  srvo_S3_C1_4,    backRightS,            tServoStandard)

#include "JoystickDriver.c"

task main() {
  int x1, y1, x2, y2;
  while(true) {
    // Gets the positions of the joysticks on the gamepad.
    getJoystickSettings(joystick);
    x1 = joystick.joy1_x1;
    y1 = joystick.joy1_y1;
    x2 = joystick.joy1_x2;
    y2 = joystick.joy1_y2;

    if(y1 > 50 || y1 < -50) {
    	servo[frontRights] = 0;
    	servo[frontLefts] = 0;
    	servo[backLefts] = 0;
    	servo[backRights] = 0;
    	motor[frontRight] = -y1;
    	motor[frontLeft] = y1;
    	motor[backRight] = -y1;
    	motor[backLeft] = y1;
  }
    else if(
  //CODE NOT FINISHED
}
