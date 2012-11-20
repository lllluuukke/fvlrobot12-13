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

float _atan(float x) {
  float tn = atan(x)+PI/2;
  return vexRT[Ch3] > 0 ? tn : tn+PI;
}

task main() {
  int left = 0, right = 0, ratio = 0;
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
	  right = -vexRT[Ch1]/2;
      // EXPERIMENT TWO
      motor[motor_ne] =
	   struggle((int)(((float)(vexRT[Ch3]-vexRT[Ch4]))*SIN45), right);
      motor[motor_se] =
	   struggle((int)(((float)(vexRT[Ch4]+vexRT[Ch3]))*SIN45), right);
      motor[motor_sw] =
	   struggle((int)(((float)(vexRT[Ch4]-vexRT[Ch3]))*SIN45), right);
      motor[motor_nw] =
	   struggle((int)(((float)-1*(vexRT[Ch4]+vexRT[Ch3]))*SIN45), right);
	  // EXPERIMENT FIVE
	  ratio = abs(sin(_atan(vexRT[Ch3]/vexRT[Ch4])));
      motor[motor_ne] =
	   struggle((int)(((float)(vexRT[Ch3]-vexRT[Ch4]))*ratio), right);
      motor[motor_se] =
	   struggle((int)(((float)(vexRT[Ch4]+vexRT[Ch3]))*ratio), right);
      motor[motor_sw] =
	   struggle((int)(((float)(vexRT[Ch4]-vexRT[Ch3]))*ratio), right);
      motor[motor_nw] =
	   struggle((int)(((float)-1*(vexRT[Ch4]+vexRT[Ch3]))*ratio), right);
	}
  }
}
