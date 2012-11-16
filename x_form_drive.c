#pragma config(Sensor, dgtl1,  touch,    sensorTouch)
#pragma config(Motor,  port2,  motor_ne, tmotorVex269, openLoop, reversed)
#pragma config(Motor,  port3,  motor_se, tmotorVex269, openLoop, reversed)
#pragma config(Motor,  port4,  motor_sw, tmotorVex269, openLoop, reversed)
#pragma config(Motor,  port5,  motor_nw, tmotorVex269, openLoop, reversed)

//#include "x_form_test.c"
/******************************************************************************
 * EXPERIMENTAL!!!
 * This file enables remote control of a holonomic x-formed robot base.
 *****************************************************************************/
#define SIN45 .8509
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
#define PW2(x) ((x)*(x))

int struggle(int a, int b) {
  if(abs(a*b) != a*b || a*b == 0)
    return a+b;
  else if(a == b)
    return a;
  else {
    if(a > 0)
	  return MAX(a, b);
    return MIN(a, b);
  }
}

int sign(float v) {
  if(v > 0)
    return 1;
  else if(v < 0)
    return -1;
}

// Determine the direction based on wheel orientation and control input
int cal(int quad) {
  float tmp = 0;
  switch(quad) {
	// Motor_NE, Quadrant I
    case 1:
	  tmp = sin(atan(vexRT[Ch3]/vexRT[Ch4])-PI/4);
	  return sign(tmp);
	  break;
	// Motor_NW, Quadrant II
    case 2:
	  tmp = cos(atan(vexRT[Ch3]/vexRT[Ch4])+3*PI/4);
	  return sign(tmp);
	  break;
	// Motor_SW, Quadrant III
    case 3:
	  tmp = cos(atan(vexRT[Ch3]/vexRT[Ch4])+I/4);
	  return sign(tmp);
	  break;
	// Motor_SE, Quadrant IV
    case 4:
	  tmp = sin(atan(vexRT[Ch3]/vexRT[Ch4])+PI/4);
	  return sign(tmp);
	  break;
  }
}

task main() {
  while(!SensorValue[touch]) {
    if(vexRT[Btn5U] || vexRT[Btn5D] || vexRT[Btn6U] || vexRT[Btn6D] ||
      vexRT[Btn7U] || vexRT[Btn7R] || vexRT[Btn7D] || vexRT[Btn7L] ||
      vexRT[Btn8U] || vexRT[Btn8R] || vexRT[Btn8D] || vexRT[Btn8L]) {
      motor[motor_ne] = 0;
      motor[motor_ne] = 0;
      motor[motor_ne] = 0;
      motor[motor_ne] = 0;
   }
   else {
     // EXPERIMENT TWO!!!
     motor[motor_ne] =
	   struggle((int)(((float)(vexRT[Ch3]-vexRT[Ch4]))*SIN45),
	   -1*vexRT[Ch1]/2);
     motor[motor_se] =
	   struggle((int)(((float)(vexRT[Ch4]+vexRT[Ch3]))*SIN45),
	   -1*vexRT[Ch1]/2);
     motor[motor_sw] =
	   struggle((int)(((float)(vexRT[Ch4]-vexRT[Ch3]))*SIN45),
	   -1*vexRT[Ch1]/2);
     motor[motor_nw] =
	   struggle((int)(((float)-1*(vexRT[Ch4]+vexRT[Ch3]))*SIN45),
	   -1*vexRT[Ch1]/2);
     // EXPERIMENT FOUR!!!
     motor[motor_ne] =
	   struggle(cal(1)*(int)sqrt(PW2(vexRT[Ch3])+PW2(vexRT[Ch4])),
	   -1*vexRT[Ch1]/2);
     motor[motor_se] =
	   struggle(cal(4)*(int)sqrt(PW2(vexRT[Ch3])+PW2(vexRT[Ch4])),
	   -1*vexRT[Ch1]/2);
     motor[motor_sw] =
	   struggle(cal(3)*(int)sqrt(PW2(vexRT[Ch3])+PW2(vexRT[Ch4])),
	   -1*vexRT[Ch1]/2);
     motor[motor_nw] =
	   struggle(cal(2)*(int)sqrt(PW2(vexRT[Ch3])+PW2(vexRT[Ch4])),
	   -1*vexRT[Ch1]/2);
	 }
  }
}
