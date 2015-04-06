#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, I2C_1,  RRight,         sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_2,  RLeft,          sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_3,  BLeft,         sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_4,  BRight,         sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_5,  FLeft,          sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_6,  FRight,          sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port1,           RIntake,       tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port2,           FRight,        tmotorVex393, openLoop, reversed, encoder, encoderPort, I2C_6, 1000)
#pragma config(Motor,  port3,           RRight,        tmotorVex393, openLoop, reversed, encoder, encoderPort, I2C_1, 1000)
#pragma config(Motor,  port4,           BRight,        tmotorVex393, openLoop, reversed, encoder, encoderPort, I2C_4, 1000)
#pragma config(Motor,  port5,           TRight,        tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port6,           TLeft,         tmotorVex393, openLoop)
#pragma config(Motor,  port7,           BLeft,         tmotorVex393, openLoop, encoder, encoderPort, I2C_3, 1000)
#pragma config(Motor,  port8,           FLeft,         tmotorVex393, openLoop, encoder, encoderPort, I2C_5, 1000)
#pragma config(Motor,  port9,           RLeft,         tmotorVex393, openLoop, encoder, encoderPort, I2C_2, 1000)
#pragma config(Motor,  port10,          LIntake,       tmotorVex393, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settingsx
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
		nMotorEncoder[RRight] = 0;
		nMotorEncoder[RLeft] = 0;
		nMotorEncoder[FRight] = 0;
		nMotorEncoder[FLeft] = 0;



	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}
void drive(int encoderCounts, int speed)
{


	//While both of the encoders are less than the specified amount
	while(nMotorEncoder[RRight] < encoderCounts)
	{
		//If the two encoder values are equal
		if(abs(nMotorEncoder[RRight]) == abs(nMotorEncoder[RLeft]))
		{
			//Move the robot forward at the specified speed
			motor[RRight] = speed;
			motor[FRight] = speed;
			motor[RLeft] = speed;
			motor[FLeft] = speed;

		}
		if(abs(nMotorEncoder[RRight]) < abs(nMotorEncoder[RLeft]))
		{
			//Move the robot forward at the specified speed
			motor[RRight] = speed;
			motor[FRight] = speed;
			motor[RLeft] = speed+10;
			motor[FLeft] = speed+10;

		}
		else if(abs(nMotorEncoder[RRight]) > abs(nMotorEncoder[RLeft]))
		{
			//Move the robot forward at the specified speed
			motor[RRight] = speed+10;
			motor[FRight] = speed+10;
			motor[RLeft] = speed;
			motor[FLeft] = speed;

		}
	}
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


void arm(int encodercounts, int speed)
{

	while(abs(nMotorEncoder[BRight]) < encodercounts)
	{
		//If the two encoder values are equal
		if(abs(nMotorEncoder[BLeft]) == abs(nMotorEncoder[BRight]))
		{
			//Move the robot forward at the specified speed
			motor[TLeft] = speed;
			motor[BLeft] = speed;
			motor[TRight] = speed;
			motor[BRight] = speed;

		}
		else if(abs(nMotorEncoder[BLeft]) < abs(nMotorEncoder[BRight]))
		{
			//Move the robot forward at the specified speed
			motor[TLeft] = speed;
			motor[BLeft] = speed;
			motor[TRight] = speed + 10;
			motor[BRight] = speed + 10;

		}
		else if(nMotorEncoder[BLeft] > abs(nMotorEncoder[BRight]))
		{
			//Move the robot forward at the specified speed
			motor[TLeft] = speed + 10;
			motor[BLeft] = speed + 10;
			motor[TRight] = speed;
			motor[BRight] = speed;

		}
	}

	motor[BRight] = 0;
	motor[BLeft] = 0;
	motor[TRight] = 0;
	motor[TLeft] = 0;
}



void conveyor (int G_time, int G_speed)
{
	motor[RIntake] = G_speed;
	motor[LIntake] = G_speed;

	wait1Msec(G_time);

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



//move forward
//stop
//conveyor goes up
//move forward (a lot)
//stop
//arm up
//conveyor goes down
//move back


// .....................................................................................
/*


turnLeft(100,100);
move(100,-100);
arm(100,100);
conveyor(100,-100);
*/


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
				if(-nMotorEncoder[BLeft] == nMotorEncoder[BRight])
				{
					motor[TLeft] =  vexRT[Ch2Xmtr2] ;
					motor[BLeft] =  vexRT[Ch2Xmtr2] ;
					motor[TRight] =  vexRT[Ch2Xmtr2];
					motor[BRight] =  vexRT[Ch2Xmtr2] ;
				}

				else if((-nMotorEncoder[BLeft]) < nMotorEncoder[BRight])
				{
					motor[TLeft] =  vexRT[Ch2Xmtr2] ;
					motor[BLeft] =  vexRT[Ch2Xmtr2] ;
					motor[TRight] =  vexRT[Ch2Xmtr2]+10;
					motor[BRight] =  vexRT[Ch2Xmtr2]+10;
				}
				else if((-nMotorEncoder[BLeft]) > nMotorEncoder[BRight])
				{
					motor[TLeft] =  vexRT[Ch2Xmtr2]+10;
					motor[BLeft] =  vexRT[Ch2Xmtr2]+10;
					motor[TRight] =  vexRT[Ch2Xmtr2];
					motor[BRight] =  vexRT[Ch2Xmtr2];
				}

		}
		else if(vexRT[Ch2Xmtr2]<-thresh&&(!vexRT[Btn5DXmtr2]&&!vexRT[Btn6DXmtr2]&&!vexRT[Btn5UXmtr2]&&!vexRT[Btn6UXmtr2]))
		{
				if(-nMotorEncoder[BLeft] == nMotorEncoder[BRight])
				{
					motor[TLeft] =  vexRT[Ch2Xmtr2];
					motor[BLeft] =  vexRT[Ch2Xmtr2];
					motor[TRight] =  vexRT[Ch2Xmtr2];
					motor[BRight] =  vexRT[Ch2Xmtr2];
				}
				else if(-nMotorEncoder[BLeft] < nMotorEncoder[BRight])
				{
					motor[TLeft] =  vexRT[Ch2Xmtr2] ;
					motor[BLeft] =  vexRT[Ch2Xmtr2] ;
					motor[TRight] =  vexRT[Ch2Xmtr2]-5;
					motor[BRight] =  vexRT[Ch2Xmtr2]-5;
				}
				else if(-nMotorEncoder[BLeft] > nMotorEncoder[BRight])
				{
					motor[TLeft] =  vexRT[Ch2Xmtr2]-5;
					motor[BLeft] =  vexRT[Ch2Xmtr2]-5;
					motor[TRight] =  vexRT[Ch2Xmtr2];
					motor[BRight] =  vexRT[Ch2Xmtr2];
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
		wait1Msec(30);
	}
}
