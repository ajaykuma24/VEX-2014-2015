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


task main()
{
	int thresh = 25;
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
		if(abs(vexRT[Ch2Xmtr2])>thresh&&(!vexRT[Btn5DXmtr2]&&!vexRT[Btn6DXmtr2]&&!vexRT[Btn5UXmtr2]&&!vexRT[Btn6UXmtr2]))
		{
				motor[TLeft] =  vexRT[Ch2Xmtr2];
				motor[BLeft] =  vexRT[Ch2Xmtr2];
				motor[TRight] =  vexRT[Ch2Xmtr2];
				motor[BRight] =  vexRT[Ch2Xmtr2];
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
