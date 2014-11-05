#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     Q1,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     Q2,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     Q3,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     Q4,            tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"

task main {
	while(true){
		getJoystickSettings(joystick);
	 	int x1 = joystick.joy1_x1;
		int y1 = joystick.joy1_y1;
		int x2 = joystick.joy1_x2;
	 	int y2 = joystick.joy1_y2;
 		int radius = 25;
 		x2 /= 1.7;
 		y2 /= 1.7;
   	if (abs(x1) < radius){
			x1 = 0;
		}
		if (abs(y1) < radius){
    	y1 = 0;
		}
		if (abs(x2) < radius){
			x2 = 0;
		}
		if (abs(y2) < radius){
			y2 = 0;
		}
		motor[Q1] = (  y2 - x2  ) - x1;
		motor[Q2] = ( -y2 - x2  ) - x1;
		motor[Q3] = ( -y2 + x2  ) - x1;
		motor[Q4] = (  y2 + x2  ) - x1;
	}
}
