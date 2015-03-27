#pragma config(Sensor, dgtl1,  Rightlim,       sensorTouch)
#pragma config(Sensor, dgtl2,  Leftlim,        sensorTouch)
#pragma config(Sensor, dgtl3,  Toplim,         sensorTouch)
#pragma config(Motor,  port1,           Intake1,       tmotorVex269, openLoop, reversed)
#pragma config(Motor,  port2,           RRight,        tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port3,           FRight,        tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port4,           RLeft,         tmotorVex393, openLoop)
#pragma config(Motor,  port5,           FLeft,         tmotorVex393, openLoop)
#pragma config(Motor,  port6,           ArmRight,      tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port7,           ArmLeft,       tmotorVex393, openLoop)
#pragma config(Motor,  port8,           ArmRight2,     tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port9,           ArmLeft2,      tmotorVex393, openLoop)
#pragma config(Motor,  port10,          Intake2,       tmotorVex269, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	int X2 = 0, Y1 = 0, X1 = 0, thresh = 25;
		while(1==1)
		{
		if(abs(vexRT[Ch3]) > thresh)
				Y1 = vexRT[Ch3];
		else
				Y1 = 0;
		//Create "deadzone" for X1/Ch4
		if(abs(vexRT[Ch4]) > thresh)
				X1 = vexRT[Ch4];
		else
				X1 = 0;
		//Create "deadzone" for X2/Ch1
		if(abs(vexRT[Ch1]) > thresh)
				X2 = vexRT[Ch1];
		else
				X2 = 0;
		//Remote Control Commands
		motor[FRight] = Y1 - X2 - X1;
		motor[RRight] =  Y1 - X2 + X1;
		motor[FLeft] = Y1 + X2 + X1;
		motor[RLeft] =  Y1 + X2 - X1;
		if(abs(vexRT [Ch3Xmtr2]) > thresh)
		{
			motor[ArmRight] = vexRT[Ch3Xmtr2];
			motor[ArmLeft] = vexRT[Ch3Xmtr2];

		}
		else if(abs(vexRT[Ch3Xmtr2]) <=thresh)
		{
			motor[ArmRight] = 0;
			motor[ArmLeft] = 0;

		}
		if(vexRT [Ch2Xmtr2] > thresh&&!SensorValue[Toplim})
		{
			motor[ArmRight2] = -vexRT[Ch2Xmtr2];
			motor[ArmLeft2] = -vexRT[Ch2Xmtr2];

		}
		else if(vexRT[Ch2Xmtr2] < -thresh)
		{
			motor[ArmRight2] = -vexRT[Ch2Xmtr2];
			motor[ArmLeft2] = -vexRT[Ch2Xmtr2];
		}
		else if(abs(vexRT[Ch2Xmtr2]) <=thresh||SensorValue[Toplim])
		{
			motor[ArmRight2] = 0;
			motor[ArmLeft2] = 0;
		}
		if(vexRT[Btn5UXmtr2])
		{
			motor[Intake1] = 100;
			motor[Intake2] = 100;

		}
		else if(vexRT[Btn5DXmtr2])
		{
			motor[Intake1] = -100;
			motor[Intake2] = -100;
		}
		else
		{
			motor[Intake1] = 0;
			motor[Intake2] = 0;
		}

	}


}
