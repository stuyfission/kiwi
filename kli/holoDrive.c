#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     Q1,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     Q2,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     Q3,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     Q4,            tmotorTetrix, openLoop)

#include "JoystickDriver.c"

// Copyright Stuy Fission 310
/**
 * Authored by Kenneth Li (kenneth.li@stuypulse.com
 * http://310fission.com
 * This file is teleop program for our holonomic drivetrain prototype.
 */

task main {
	int x1, x2, y2;
	while (true) {
    
		// Update the values of the variables storing the joystick positions.
		getJoystickSettings(joystick);
	 	x1 = joystick.joy1_x1;
		x2 = joystick.joy1_x2;
	 	y2 = joystick.joy1_y2;

 		if (abs(x1) < radius)
            x1 = 0;
        if (abs(x2) < radius)
            x2 = 0;
        if (abs(y2) < radius)
            y2 = 0;
            
        /*
        Assuming counterclockwise (when looking at wheel) is negative, clockwise is positive
        Assuming motors are aligned as follows:
        
        (direction of positive power indicated)
               |
        >^ Q2/_|_\Q1 <^   forward    ^
        _____|   |_____  direction  
             |___|                  
        <^ Q3\ | /Q4 >^
               |
               
        x2 > 0:
            direction = >
        x2 < 0:
            direction = <
        y2 > 0:
            direction = ^
        y2 < 0:
            direction = v
        */
         
        motor[Q1] = -x2 + y2 - x1;
        motor[Q2] =  x2 + y2 + x1;
        motor[Q3] = -x2 + y2 + x1;
        motor[Q4] =  x2 + y2 - x1;
        
        }    
}
