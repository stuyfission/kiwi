#include "JoystickDriver.c"

task main () {

	while true ()
		getJoystickSettings(joystick);
		int y1 = joystick.joy1_y1;
		int y2 = joystick.joy1_y2;
		int x1 = joystick.joy1_x1;
		int x2 = joystick.joy1_x2;

		if (y1 > 50) {
			//right side forward
			motor [r1] = y1;
			motor [r2] = y2;
		}

		else {
			motor [r1] = 0;
			motor [r2] = 0;
		}

		if (y1 < -50) {
			//left side forward
			motor [r1] = y1;
			motor [r2] = y2;
		}

		else {
			motor [r1] = 0;
			motor [r2] = 0;
		}

}
