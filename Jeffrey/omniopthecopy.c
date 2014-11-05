#include "JoystickDriver.c"

task main {
	while (true){
		getJoystickSettings(joystick);
		int y1 = joystick.joy1_y1;
		int y2 = joystick.joy1-y2;
		int x1 = joystick.joy1_x1;
		int x2 = joystick.joy2_x2;
		int radius = 25;
		
		if (y1 > radius){
			motor[Q1] = 100;
			motor[Q2] = 100;
		}
		if (y1 > radius){
			motor[Q3] = 100;
			motor[Q4] = 100;
		}
	
}