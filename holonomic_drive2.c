#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     Q1,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     Q2,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     Q3,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     Q4,            tmotorTetrix, openLoop)

#include "JoystickDriver.c"

// Copyright Stuy Fission 310
/**
 * Authored by Daniel Knopf (danielkn609@gmail.com)
 * http://310fission.com
 * This file is a teleop program for our holonomic drivetrain prototype.
 * SIMPLE version
 */

task main () {
	while(true) {
		// Update the values of the variables based on joystick positions.
    getJoystickSettings(joystick);
    int y1 = joystick.joy1_y1;
    int y2 = joystick.joy1_y2;
    int radius = 25;
    // The motors will not move unless the joystick value is above 25 o
    // below -25.
    // This assures that the motors will not turn if the joystick is
    // accidentally moved a little bit.
    if (abs(x2) > radius || abs(y2) > radius) {
      motor[Q1] = -x2 + y2;
      motor[Q2] = -x2 - y2;
      motor[Q3] =  x2 - y2;
      motor[Q4] =  x2 + y2;
		} else if (abs(x1) > radius) {
      motor[Q1] = -x1;
      motor[Q2] = -x1;
      motor[Q3] = -x1;
      motor[Q4] = -x1;
		}
    // If neither of the joysticks are pushed, the motors will go to zero power.
    else {
      motor[Q1] = 0;
      motor[Q2] = 0;
      motor[Q3] = 0;
      motor[Q4] = 0;
		}
	}
}
