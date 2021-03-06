#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     charge,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     shoot,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     right,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     left,          tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C3_1,    hi,                   tServoNone)
#pragma config(Servo,  srvo_S1_C3_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                           Tele-Operation Mode Code Template
//
// This file contains a template for simplified creation of an tele-op program for an FTC
// competition.
//
// You need to customize two functions with code unique to your specific robot.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.


/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                    initializeRobot
//
// Prior to the start of tele-op mode, you may want to perform some initialization on your robot
// and the variables within your program.
//
// In most cases, you may not have to add any code to this function and it will remain "empty".
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

void initializeRobot()
{
  // Place code here to sinitialize servos to starting positions.
  // Sensors are automatically configured and setup by ROBOTC. They may need a brief time to stabilize.

  return;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                         Main Task
//
// The following is the main code for the tele-op robot operation. Customize as appropriate for
// your specific robot.
//
// Game controller / joystick information is sent periodically (about every 50 milliseconds) from
// the FMS (Field Management System) to the robot. Most tele-op programs will follow the following
// logic:
//   1. Loop forever repeating the following actions:
//   2. Get the latest game controller / joystick settings that have been received from the PC.
//   3. Perform appropriate actions based on the joystick + buttons settings. This is usually a
//      simple action:
//      *  Joystick values are usually directly translated into power levels for a motor or
//         position of a servo.
//      *  Buttons are usually used to start/stop a motor or cause a servo to move to a specific
//         position.
//   4. Repeat the loop.
//
// Your program needs to continuously loop because you need to continuously respond to changes in
// the game controller settings.
//
// At the end of the tele-op period, the FMS will autonmatically abort (stop) execution of the program.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

task main()
{
  initializeRobot();

  int servoPosition = 125;

  while (true)
  {

    getJoystickSettings(joystick);
 		motor[left] = -joystick.joy1_y1 / 2;
 		motor[right] = joystick.joy1_y2 / 2;

 		if (joy1Btn(8)) {
 			motor[charge] = 100;
 		}
 		else {
 			motor[charge] = 0;
 		}

 		if (joy1Btn(6)) {
 			motor[shoot] = 100;
 		}
 		else {
 			motor[shoot] = 0;
 		}

 		if (joy1Btn(5) && servoPosition <= 255) {
 			servoPosition += 1;
 			wait1Msec(10);
 		}
 		if (joy1Btn(7) && servoPosition >= 0) {
 			servoPosition -= 1;
 			wait1Msec(10);
 		}
 		servo[hi] = servoPosition;
  }
}
