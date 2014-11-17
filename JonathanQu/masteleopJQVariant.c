#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     Q1,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     Q2,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     Q3,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     Q4,            tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"

//totally not a ripoff
//Brian Kwong, Allan Wang, Jonathan Quang, some parts of Alvin Lin's

task main {
	int x1, y1, x2, y2, fine_adjustment;
	while (true){
		// Update the values of the variables storing the joystick positions.
		getJoystickSettings(joystick);
	 	x1 = joystick.joy1_x1;
		y1 = joystick.joy1_y1;
		x2 = joystick.joy1_x2;
	 	y2 = joystick.joy1_y2;

	 //filter
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

   if (y1 > 0 && abs(y2) > 0 && abs(x2) >0) {
	fine_adjustment = 1 / (y1+1);
	}
	else {
	fine_adjustment = 0;
	}


   //direct movement, Alvin's code is too good
	  motor[Q1] = ( y2 - x2 ) *fine_adjustment;
	 motor[Q2] = ( -y2 - x2  ) * fine_adjustment;
	 motor[Q3] = ( -y2 + x2  )* fine_adjustment ;
	 motor[Q4] = (  y2 + x2  ) * fine_adjustment;

	 //rotate
	 if (x1>50 && x2==0 && y2==0) {
	 motor[Q1] = (  100 )* fine_adjustment ;
	 motor[Q2] = ( 100 ) * fine_adjustment;
	 motor[Q3] = ( 100 )* fine_adjustment ;
	 motor[Q4] = (  100)* fine_adjustment ;
   }

	 if (x1<-50 && x2==0 && y2==0) {
	 motor[Q1] = (  -100 )* fine_adjustment ;
	 motor[Q2] = ( -100 ) * fine_adjustment;
	 motor[Q3] = ( -100 ) * fine_adjustment;
	 motor[Q4] = (  -100  ) * fine_adjustment;
   }
	}