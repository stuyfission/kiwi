#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     Q1,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     Q2,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     Q3,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     Q4,            tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"

//please check this for me lol
//I think this is wrong

task main() {
	int x1, y1, x2, y2;
	while (true){
		// Update the values of the variables storing the joystick positions.
		getJoystickSettings(joystick);
	 	x1 = joystick.joy1_x1;
		y1 = joystick.joy1_y1;
		x2 = joystick.joy1_x2;
	 	y2 = joystick.joy1_y2;

	 	if (abs(x1)> -28 ) {
	 		x1 = 0;
	}
		if (abs(y1)> -28 ) {
			y1 = 0;
	}
		if (abs(x2)> -28) {
			x2 = 0;
	}
		if (abs(y2)> -28	{
			y2 = 0;
	}

	//scaling here
	if (x1 > -28) {
		x1 = x1 - 28;
	}
	if (x1 < 28) {
		x1 = x1 + 28;
	}
	if (y1 < 28) {
		y1 = y1 + 28;
	}
	if (x2 > -28){
		x2 = x2 - 28;
	}
	if (y2 > -28){
		y2 = y2 - 28;
	}
	if (y2 < -28){
		y2 = y2 + 28;
	if (y1 > -28) {
		y1 = y1 - 28;
	}
	}







