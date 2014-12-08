#pragma config(Hubs,  S1, HTMotor,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     driveR,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     driveL,        tmotorTetrix, openLoop)

#include "JoystickDriver.c"

// Copyright Stuy Fission 310
/**
 * Authored by Alvin Lin (alvin.lin@stuypulse.com)
 * http://omgimanerd.github.io
 * http://310fission.com
 * This file is a basic teleop program for a drivetrain.
 */

task main() {
  int y1, y2;
  while (true) {
    // Update the values of the variables storing the joystick positions.
    getJoystickSettings(joystick);
    y1 = joystick.joy1_y1;
    y2 = joystick.joy1_y2;

    if (abs(y1) < 25) {
      y1 = 0;
    }
    if (abs(y2) < 25) {
      y2 = 0;
    }

    motor[driveL] = y1;
    motor[driveR] = y2;
  }
}
