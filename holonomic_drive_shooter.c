#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     Q1,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     Q2,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     Q3,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     Q4,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     shooter1,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     shooter2,      tmotorTetrix, openLoop)

// Copyright Stuy Fission 310
/**
 * Authored by Alvin Lin (alvin.lin@stuypulse.com)
 * http://omgimanerd.github.io
 * http://310fission.com
 * This file is teleop program for our holonomic drivetrain prototype
 * with the ball shooter attachment.
 */

#include "JoystickDriver.c"

const int MIN_JOYSTICK_RADIUS = 25;

task main {
  int x1, x2, y2;

  bool shooterState;
  bool lastShooterState;

  while (true) {
    // Update the values of the variables storing the joystick positions.
    getJoystickSettings(joystick);
    x1 = joystick.joy1_x1;
    x2 = joystick.joy1_x2;
    y2 = joystick.joy1_y2;

    // The motors will not move if the joystick has not been pushed a
    // a sufficient distance.
    if (abs(x1) < MIN_JOYSTICK_RADIUS) {
      x1 = 0;
    }
    if (abs(x2) < MIN_JOYSTICK_RADIUS) {
      x2 = 0;
    }
    if (abs(y2) < MIN_JOYSTICK_RADIUS) {
      y2 = 0;
    }

    // Compounds the powers of the motors according to the joysticks.
    /*  forward/back     l/r        rotation
     * Q1:  y2           -x2           -x1
     * Q2: -y2           -x2           -x1
     * Q3: -y2            x2           -x1
     * Q4:  y2            x2           -x1
     */
    motor[Q1] = ( y2 - x2) - x1;
    motor[Q2] = (-y2 - x2) - x1;
    motor[Q3] = (-y2 + x2) - x1;
    motor[Q4] = ( y2 + x2) - x1;

    // Toggles the shooter.
    if ((joy1Btn(2) == 1 || nNxtButtonPressed == 3) && !lastShooterState) {
    	shooterState = !shooterState;
    }
    lastShooterState = (joy1Btn(2) == 1 || nNxtButtonPressed == 3);

    if (shooterState) {
    	motor[shooter1] = -100;
    	motor[shooter2] = -100;
    } else {
    	motor[shooter1] = 0;
    	motor[shooter2] = 0;
    }

    // Outputs the joystick values to the screen.
    eraseDisplay();
    nxtDisplayString(2, "X2: %i", x2);
    nxtDisplayString(3, "Y2: %i", y2);
    nxtDisplayString(4, "X1: %i", x1);
    nxtDisplayString(5, "%f", joy1Btn(2));

    // Looping delay
    wait1Msec(10);
  }
}
