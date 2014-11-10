#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     Q1,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     Q2,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     Q3,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     Q4,            tmotorTetrix, openLoop)



#include "JoystickDriver.c"
task main()
{
	motor[left] = 100;
	getJoystickSettings(joystick);
	int y1 = joystick.joy1_y1;
	int y2 = joystick.joy1_y2;
	if(y1>50) {
		motor[r1] = 100;
		motor[r2] = 100;
	}
	if(y1<-50) {
		motor[r1] = -100;
		motor[r2] = -100;
	}
	if(y2>50) {
		motor[l1] = 100;
		motor[l2] = 100;
	}
	if(y2<-50) {
		motor[l1] = -100;
		motor[l2] = -100;
	}
	else{
		motor[l1] = 100;
}
