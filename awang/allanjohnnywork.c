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
}
