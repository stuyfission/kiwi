// Copyright Stuy Fission 310
/**
 * Authored by Daniel Knopf (danielkn609@gmail.com)
 * http://310fission.com
 * This file is a teleop program for our holonomic drivetrain prototype.
 */
#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     Q1,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     Q2,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     Q3,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     Q4,            tmotorTetrix, openLoop)

#include "JoystickDriver.c"

task main () {
	while(true) {
		// Update the values of the variables based on joystick positions.
    getJoystickSettings(joystick);
    int x1 = joystick.joy1_x1;
    int y1 = joystick.joy1_y1;
    int x2 = joystick.joy1_x2;
    int y2 = joystick.joy1_y2;
    int radius = 25;
    // The motors will not move unless the joystick value is above 25 o
    // below -25.
    // This assures that the motors will not turn if the joystick is
    // accidentally moved a little bit.
    if (y1 > radius || y1 < radius * -1){
      motor[Q1] = y1;
      motor[Q2] = -y1;
      motor[Q3] = -y1;
      motor[Q4] = y1;
		} else if (y2 > radius || y2 < radius * -1) {
      motor[Q1] = y2;
      motor[Q2] = 0;
      motor[Q3] = 0;
      motor[Q4] = y2;
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
