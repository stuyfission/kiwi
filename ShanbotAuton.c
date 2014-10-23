#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  HTMotor)
#pragma config(Motor,  mtr_S1_C1_1,     backLeft,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     backRight,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     frontLeft,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     frontRight,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     donutLift,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     supportMotor,  tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C3_1,    servo1,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_6,    servo6,               tServoNone)

#include "joystickdriver.c";

void initializeRobot() {
}
task main()
{
	initializeRobot();

	//waitForStart();

	motor[backLeft] = -100;
	motor[frontLeft] = -100;
	motor[backRight] = 100;
	motor[frontRight] = 100;
	wait1Msec(3500);

	motor[backLeft] = 100;
	motor[frontLeft] = 100;
	motor[backRight] = 100;
	motor[frontRight] = 100;
	wait1Msec(400);

	motor[backLeft] = -100;
	motor[frontLeft] = -100;
	motor[backRight] = 100;
	motor[frontRight] = 100;
	wait1Msec(3500);

	while (true) {
	motor[backLeft] = 100;
	motor[frontLeft] = 100;
	motor[backRight] = -100;
	motor[frontRight] = -100;
	wait1Msec(3000);
  motor[backLeft] = -100;
	motor[frontLeft] = -100;
	motor[backRight] = 100;
	motor[frontRight] = 100;
	wait1Msec(3000);
}


	motor[backLeft] = 0;
	motor[frontLeft] = 0;
	motor[backRight] = 0;
	motor[frontRight] = 0;


	while (true)
	{
	}


}
