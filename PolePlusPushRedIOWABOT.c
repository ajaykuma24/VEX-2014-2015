#pragma config(Motor,  port2,           FRight,        tmotorVex393, openLoop, reversed) // Front Right Drive
#pragma config(Motor,  port3,           RRight,        tmotorVex393, openLoop, reversed) // Rear RIght Drive
#pragma config(Motor,  port4,           BRight,        tmotorVex393, openLoop, reversed) // Bottom Right Arm
#pragma config(Motor,  port5,           TRight,        tmotorVex393, openLoop, reversed) // Top Right Arm
#pragma config(Motor,  port6,           TLeft,         tmotorVex393, openLoop) // Top Left Arm
#pragma config(Motor,  port7,           BLeft,         tmotorVex393, openLoop) // Bottom Left Arm
#pragma config(Motor,  port8,           FLeft,         tmotorVex393, openLoop) // Front Left Drive
#pragma config(Motor,  port9,           RLeft,         tmotorVex393, openLoop) // Rear Left Drive
#pragma config(Motor,  port1,           RIntake,       tmotorVex393, openLoop, reversed) // Right Intake
#pragma config(Motor,  port10,          LIntake,       tmotorVex393, openLoop) // Left Intake
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
//#pragma autonomousDuration(20)
//#pragma userControlDuration(120)


#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////
int G_time=0;
int G_speed=0;
int G_encodercounts = 0;
void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
  // Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;
  	//Clear the encoders before using them

		nMotorEncoder[BLeft] = 0;
		nMotorEncoder[BRight] = 0;


	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}
void drive(int time, int speed)
{


	//While both of the encoders are less than the specified amount
	//while(nMotorEncoder[RRight] < encoderCounts)
	//{
		//If the two encoder values are equal
		//if(abs(nMotorEncoder[RRight]) == abs(nMotorEncoder[RLeft]))
		//{
			//Move the robot forward at the specified speed
			motor[RRight] = speed;
			motor[FRight] = speed;
			motor[RLeft] = speed;
			motor[FLeft] = speed;
			wait1Msec(time);
		//}



	//Stop the robot
	motor[RRight] = 0;
	motor[FRight] = 0;
	motor[RLeft] = 0;
	motor[FLeft] = 0;
}



//Turn the robot left for the specified encoder counts
//at a specified speed
void turnLeft(int time, int speed)
{
	//Clear the encoders before using them
	//While the absolute value of the right motor's encoder is less
	//than the specified amount

		//Turn the robot to the left at the specified speed
	motor[RRight] = speed;
	motor[FRight] = speed;
	motor[RLeft] = -speed;
	motor[FLeft] = -speed;
	wait1Msec(time);

	//Stop the robot
	motor[RRight] = 0;
	motor[FRight] = 0;
	motor[RLeft] = 0;
	motor[FLeft] = 0;
}

//Turn the robot left for the specified encoder counts
//at a specified speed
void turnRight(int time, int speed)
{
	//Clear the encoders


	//While the absolute value of the left motor's encoder is less
	//than the specified amount

		//Turn the robot to the right at the specified speed
	motor[RRight] = -speed;
	motor[FRight] = -speed;
	motor[RLeft] = speed;
	motor[FLeft] = speed;
	wait1Msec(time);

	//Stop the robot
	motor[RRight] = 0;
	motor[FRight] = 0;
	motor[RLeft] = 0;
	motor[FLeft] = 0;
}


void arm (int time, int speed)
{
	motor[BRight] = speed;
	motor[BLeft] = speed;

			//Move the robot forward at the specified speed
	motor[TRight] = speed;
	motor[TLeft] = speed;
	wait1Msec(time);

	motor[BRight] = 0;
	motor[BLeft] = 0;
	motor[TRight] = 0;
	motor[TLeft] = 0;
}


void conveyor (int time, int speed)
{
	motor[RIntake] = speed;
	motor[LIntake] = speed;

	wait1Msec(time);

	motor[RIntake] = 0;
	motor[LIntake] = 0;

}


/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous()
{
  // .....................................................................................
//drive(250, -50);

drive(630,-100);
arm(3000, 100);
arm(1500, -50);
conveyor(500, -50);
arm(1500, -50);
drive(1500, -100);
turnRight(250, 100);
drive(2250, 100);
drive(1500, -100);



// .....................................................................................



//turnLeft(100,100);
//drive(100,-100);
//StartTask(arm);
//StartTask(conveyor);


// .....................................................................................


}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol()
{
		int thresh = 25;
	nMotorEncoder[BLeft] = 0;
	nMotorEncoder[BRight] = 0;

	while(1)
	{
		if(abs(vexRT[Ch3])>thresh)
		{


				motor[FLeft] = vexRT[Ch3];
				motor[RLeft] =  vexRT[Ch3];

		}
		else if(abs(vexRT[Ch3])<=thresh)
		{
				motor[FLeft] = 0;
				motor[RLeft] =  0;
		}
		if(abs(vexRT[Ch2])>thresh)
		{
				motor[FRight] = vexRT[Ch2];
				motor[RRight] =  vexRT[Ch2];
		}
		else if(abs(vexRT[Ch2])<=thresh)
		{
				motor[FRight] = 0;
				motor[RRight] =  0;
		}


		if(vexRT[Ch2Xmtr2]>thresh&&(!vexRT[Btn5DXmtr2]&&!vexRT[Btn6DXmtr2]&&!vexRT[Btn5UXmtr2]&&!vexRT[Btn6UXmtr2]))
		{
				if(abs(nMotorEncoder[BLeft]) == abs(nMotorEncoder[BRight]))
				{
					motor[TLeft] =  vexRT[Ch2Xmtr2] ;
					motor[BLeft] =  vexRT[Ch2Xmtr2] ;
					motor[TRight] =  vexRT[Ch2Xmtr2];
					motor[BRight] =  vexRT[Ch2Xmtr2] ;
				}

				else if(abs(nMotorEncoder[BLeft]) < abs(nMotorEncoder[BRight]))
				{
					motor[TLeft] =  vexRT[Ch2Xmtr2] +10;
					motor[BLeft] =  vexRT[Ch2Xmtr2] +10;
					motor[TRight] =  vexRT[Ch2Xmtr2];
					motor[BRight] =  vexRT[Ch2Xmtr2];
				}
				else if((abs(nMotorEncoder[BLeft])) > abs(nMotorEncoder[BRight]))
				{
					motor[TLeft] =  vexRT[Ch2Xmtr2];
					motor[BLeft] =  vexRT[Ch2Xmtr2];
					motor[TRight] =  vexRT[Ch2Xmtr2]+10;
					motor[BRight] =  vexRT[Ch2Xmtr2]+10;
				}

		}
		else if(vexRT[Ch2Xmtr2]<-thresh&&(!vexRT[Btn5DXmtr2]&&!vexRT[Btn6DXmtr2]&&!vexRT[Btn5UXmtr2]&&!vexRT[Btn6UXmtr2]))
		{
				if(abs(nMotorEncoder[BLeft]) == abs(nMotorEncoder[BRight]))
				{
					motor[TLeft] =  vexRT[Ch2Xmtr2];
					motor[BLeft] =  vexRT[Ch2Xmtr2];
					motor[TRight] =  vexRT[Ch2Xmtr2];
					motor[BRight] =  vexRT[Ch2Xmtr2];
				}
				else if(abs(nMotorEncoder[BLeft]) < abs(nMotorEncoder[BRight]))
				{
					motor[TLeft] =  vexRT[Ch2Xmtr2] +5;
					motor[BLeft] =  vexRT[Ch2Xmtr2] +5;
					motor[TRight] =  vexRT[Ch2Xmtr2];
					motor[BRight] =  vexRT[Ch2Xmtr2];
				}
				else if(abs(nMotorEncoder[BLeft]) > abs(nMotorEncoder[BRight]))
				{
					motor[TLeft] =  vexRT[Ch2Xmtr2];
					motor[BLeft] =  vexRT[Ch2Xmtr2];
					motor[TRight] =  vexRT[Ch2Xmtr2]+5;
					motor[BRight] =  vexRT[Ch2Xmtr2]+5;
				}
		}

		else if(vexRT[Btn6UXmtr2]&&abs(vexRT[Ch2Xmtr2])<thresh)
		{
				motor[TLeft] =  70;
				motor[BLeft] =  70;
		}
		else if(vexRT[Btn6DXmtr2]&&abs(vexRT[Ch2Xmtr2])<thresh)
		{
				motor[TLeft] =  -70;
				motor[BLeft] =  -70;
		}
		else if(vexRT[Btn5UXmtr2]&&abs(vexRT[Ch2Xmtr2])<thresh)
		{
				motor[TRight] =  70;
				motor[BRight] =  70;
		}
		else if(vexRT[Btn5DXmtr2]&&abs(vexRT[Ch2Xmtr2])<thresh)
		{
				motor[TRight] =  -70;
				motor[BRight] =  -70;
		}
		else if(abs(vexRT[Ch2Xmtr2])<=thresh&&(!vexRT[Btn5DXmtr2]&&!vexRT[Btn6DXmtr2]&&!vexRT[Btn5UXmtr2]&&!vexRT[Btn6UXmtr2]))
		{
				motor[TLeft] = 0;
				motor[BLeft] = 0;
				motor[TRight] = 0;
				motor[BRight] = 0;
		}

		if(vexRT[Btn6U]||(vexRT[Ch3Xmtr2]>thresh&&!vexRT[Btn6U]&&!vexRT[Btn6D]))
		{
				motor[RIntake] = 100;
				motor[LIntake] =  100;
		}
			else if(vexRT[Btn6D]||(vexRT[Ch3Xmtr2]<-thresh&&!vexRT[Btn6U]&&!vexRT[Btn6D]))
		{
				motor[RIntake] = -100;
				motor[LIntake] = -100;
		}
		else
		{
				motor[RIntake] = 0;
				motor[LIntake] = 0;
		}
		if(vexRT[Btn5U])
		{


	}
	wait1Msec(30);
}
}
