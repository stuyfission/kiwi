#include "JoystickDriver.c"

task main {
 getJoystickSettings(joystick);
 int y1 = joystick.joy1_y1;
 int y2 = joystick.joy1_y2;
 
 if (y1 > 50) {
 motor[Q1] = 100;
 motor[Q2] = 100;
 }
 else
 {
 motor[Q1] = 0
 motor[Q2] = 0
 }
 
 if (y2 > 50) {
 motor[Q3] = 100
 motor[Q4] = 100
 }
 else 
 {
 motor[Q3] = 0
 motor[Q4] = 0
 }