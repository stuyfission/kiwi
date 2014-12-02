#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Hubs,  S2, HTMotor,  HTMotor,  none,     none)
#pragma config(Hubs,  S3, HTServo,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Sensor, S3,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     frontL,    tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     frontR,   tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S2_C1_1,     backL,     tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S2_C2_1,     backR,    tmotorNormal, openLoop)
#pragma config(Servo,  srvo_S3_C1_1,    frontRS,           tServoStandard)
#pragma config(Servo,  srvo_S3_C1_2,    frontLS,            tServoStandard)
#pragma config(Servo,  srvo_S3_C1_3,    backLS,             tServoStandard)
#pragma config(Servo,  srvo_S3_C1_4,    backRS,            tServoStandard)

#include "JoystickDriver.c"

task main() {
  int x1, y1, x2, y2;
  float wheel_turning, xy_ratios, hypotenus_power, trig_servo, final_servo;
  while(true) {

    getJoystickSettings(joystick);
    x1 = joystick.joy1_x1;
    y1 = joystick.joy1_y1;
    x2 = joystick.joy1_x2;
    y2 = joystick.joy1_y2;

	if (abs(x1)< 28) {
	   x1=0;
	 }
	 if (abs(y1)< 28) {
	   y1=0;
	 }
	 if (abs(x2)< 28) {
	   x2=0;
	 }
	 if (abs(y1)< 28) {
	   y2=0;
	 }

	 //scaling it down
	 if (x1 < -28) {
	 		x1 = x1 + 28;
   }
   if (x1 > 28) {
      x1 = x1 - 28;
   }

   if (x2 < -28) {
      x2 = x2 + 28;
   }
   if (x2 > 28) {
      x2 = x2 - 28;
   }

   if (y1 < -28) {
		y1 = y1 + 28;
   }
   if (y1 > 28) {
      y1 = y1 - 28;
   }

   if (y2 < -28) {
      y2 = y2 + 28;
   }
   if (y2 > 28) {
      y2 = y2 - 28;
   }
   
   if (y1 == 0) {
	   y1 = 1)
	}

   //Trig calculating
   xy_ratios = abs(x1) / (y1);
   wheel_turning = atan(xy_ratios) * 180/PI ;
   hypotenus_power = sqrt( x1 * x1 + y1 * y1);
   trig_servo = 255 / 360;
   if ( x1 > 0 && y1 > 0) {
   final_servo = wheel_turning * trig_servo;
   }
   if ( x1 > 0 && y1 < 0) {
   final_servo = wheel_turning * trig_servo + 90 * trig_servo;
   hypotenus_power = hypotenus_power * -1;
   }
   if ( x1 < 0 && y1 < 0) {
   final_servo = wheel_turning * trig_servo + trig_servo;
   hypotenus_power = hypotenus_power * -1;
   }
   if ( x1 < 0 && y1 > 0) {
   final_servo = wheel_turning * trig_servo + 90 * trig_servo;
   }

  servo[frontLS] = final_servo;
	servo[frontRS] = final_servo;
	servo[backLS] = final_servo;
	servo[backRS] = final_servo;
	motor[frontL] = hypotenus_power;
	motor[frontR] = hypotenus_power;
	motor[backL] = hypotenus_power;
	motor[backR] = hypotenus_power;
	}
}
