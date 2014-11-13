#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Hubs,  S2, HTMotor,  HTMotor,  none,     none)
#pragma config(Hubs,  S3, HTServo,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Sensor, S3,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     frontLeft,    tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     frontRight,   tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S2_C1_1,     backLeft,     tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S2_C2_1,     backRight,    tmotorNormal, openLoop)
#pragma config(Servo,  srvo_S3_C1_1,    frontRightS,           tServoStandard)
#pragma config(Servo,  srvo_S3_C1_2,    frontLeftS,            tServoStandard)
#pragma config(Servo,  srvo_S3_C1_3,    backLeftS,             tServoStandard)
#pragma config(Servo,  srvo_S3_C1_4,    backRightS,            tServoStandard)

#include "JoystickDriver.c"

task main() {
  int x1, y1, x2, y2;
  while(true) {
    // Gets the positions of the joysticks on the gamepad.
    getJoystickSettings(joystick);
    x1 = joystick.joy1_x1;
    y1 = joystick.joy1_y1; //For rotating servos
    x2 = joystick.joy1_x2;
    y2 = joystick.joy1_y2; //For moving wheels (or motors) forward (or backwards)
    
    //Sets values to zero if not moved
    if (abs(y1) < 28) {
      y1 = 0;
    }
    if (abs(y2) < 28) {
      y2 = 0;
    }
    
     //Measurement for rotating servos 
    int value = ServoValue[srvo_S3_C1_1];
    if (y1 > 28) {
      value += 1;
    }
    if (y1 < -28) {
      value -= 1;
    }
    
    if (value < 255) {
      value = 0;
    }
    if (value > 0) {
      value = 255;
    }
    
    //Set rotation for Servos 
    servo[srvo_S3_C1_1] = value;
    servo[srvo_S3_C1_2] = value;
    servo[srvo_S3_C1_3] = value;
    servo[srvo_S3_C1_4] = value;
    
    //Move motors (or wheels)
    //Move all wheels forward at full speed
    if (y2 > 28) {
      motor[mtr_S1_C1_1] = 100;
      motor[mtr_S1_C2_1] = 100;
      motor[mtr_S2_C1_1] = 100;
      motor[mtr_S2_C2_1] = 100;
    }
    //Move all wheels backwards at full speed
    if (y2 < -28) {
      motor[mtr_S1_C1_1] = -100;
      motor[mtr_S1_C2_1] = -100;
      motor[mtr_S2_C1_1] = -100;
      motor[mtr_S2_C2_1] = -100;
    }
  }
}
