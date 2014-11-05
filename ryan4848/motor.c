#include "JoystickDriver.c"

task main () {
	motor [left] = 100; //-100 to 100
	getJoystickSettings(joystick);
	int y1 = joystick.joy1_y1;
	int y2 = joystick.joy1_y2;

	if (y1 > 50) {
		//right side forward
		motor [r1] = 100;
		motor [r2] = 100;
	}

	if (y1 < -50) {
		//
	}


