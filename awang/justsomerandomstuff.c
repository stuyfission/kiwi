#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     Q1,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     Q2,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     Q3,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     Q4,            tmotorTetrix, openLoop)


// I have no idea what I'm doing!!!!
task main()
{

			motor[motor1] = 100;
			motor[motor2] = 100;
			wait1Msec(5000);
			motor[motor1] = 100;
			motor[motor2] = 100;
			wait10Msec(1000);
			motor[motor1] = -100;
			motor[motor2] = -100;
			wait10Msec(2000);
			motor[motor1] = 0;
			motor[motor2] = 0;
		}
