#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     motor1,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motor2,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     motor3,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motor4,        tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard            !!*//

#include "JoystickDriver.c"

task main() {
	while(true){
		getJoystickSettings(joystick);
		int y1 = joystick.joy1_y1;
		int y2 = joystick.joy1_y2;
		int x1 = joystick.joy1_x1;
		int x2 = joystick.joy1_x2;


		if (abs(x1) > 0 || abs(y1) > 0) {
	}

			//movement
		if (abs(y1) > 50) {
			motor[motor1] = y1;
			motor[motor2] = y1;
			motor[motor3] = -y1;
			motor[motor4] = -y1;
		}
		if (abs(x1) > 50){
			motor[motor1] = x1;
			motor[motor2] = -x1;
			motor[motor3] = -x1;
			motor[motor4] = x1;
		}
			//rotation
		if (abs(x2) > 50) {
			motor[motor1] = x2;
			motor[motor2] = -x2;
			motor[motor3] = x2;
			motor[motor4] = -x2;
		}
		else if (abs(x2) = 0 && abs(x2) = 0) {
			motor[motor1] = 0
			motor[motor2] = 0
			motor[motor3] = 0
			motor[motor4] = 0
		}

	}
}