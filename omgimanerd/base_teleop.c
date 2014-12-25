#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     driveL,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     driveR,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     liftL,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     liftR,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     acquirer,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     blank,         tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C4_1,    goalClamp,            tServoNone)
#pragma config(Servo,  srvo_S1_C4_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"

// Copyright Stuy Fission 310
/**
 * Authored by Alvin Lin (alvin.lin@stuypulse.com)
 * http://omgimanerd.github.io
 * http://310fission.com
 * This file is a basic teleop program for a tankdrive.
 */

bool clampDown = false;
bool controlDriveMode = false;
bool acquirerActive = false;

task trackToggles() {
	while	(true) {
	  if (joy1Btn(6)) {
	 		clampDown = false;
	 	}
	  if (joy1Btn(8)) {
			clampDown = true;
		}

		if (joy1Btn(9)) {
			controlDriveMode = false;
		}
		if (joy1Btn(10)) {
			controlDriveMode = true;
		}

		if (joy1Btn(3)) {
			acquirerActive = false;
		}
		if (joy1Btn(2)) {
			acquirerActive = true;
		}
	}
}

task main() {
	int x1, y1, x2, y2;
	StartTask(trackToggles);
	while (true) {
		// Update the values of the variables storing the joystick positions.
		getJoystickSettings(joystick);
		x1 = joystick.joy1_x1;
	 	y1 = joystick.joy1_y1;
	 	x2 = joystick.joy1_x2;
	 	y2 = joystick.joy1_y2;

    if (abs(y1) < 25) {
      y1 = 0;
    }
    if (abs(y2) < 25) {
      y2 = 0;
    }

	 	if (clampDown) {
	 		servo[goalClamp] = 0;
	 	} else {
	 		servo[goalClamp] = 255;
	 	}

		if (acquirerActive) {
			motor[acquirer] = -100;
		} else {
			motor[acquirer] = 0;
		}

	  if (controlDriveMode) {
			motor[driveL] = 30 * -(y1 / abs(y1));
			motor[driveR] = 30 * -(y2 / abs(y2));
		} else {
		 	motor[driveL] = -y1;
		 	motor[driveR] = -y2;
		}

	 	eraseDisplay();
		nxtDisplayString(2, "X2: %i", x2);
		nxtDisplayString(3, "Y2: %i", y2);
		nxtDisplayString(4, "X1: %i", x1);
		nxtDisplayString(5, "Y1: %i", y1);
	}
}
