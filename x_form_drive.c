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

task main() {
  while(!SensorValue[touch]) {
    // EXPERIMENTAL TWO!!!
    motor[motor_ne] =
	    (int)struggle((float)(vexRT[ch3]-vexRT[ch4])*SIN45, -1*vexRT[ch1]);
    motor[motor_se] =
	    (int)struggle((float)(vexRT[ch4]+vexRT[ch3])*SIN45, -1*vexRT[ch1]);
    motor[motor_sw] =
	    (int)struggle((float)(vexRT[ch4]-vexRT[ch3])*SIN45, -1*vexRT[ch1]);
    motor[motor_nw] =
	    (int)struggle(-1*(float)(vexRT[ch4]+vexRT[ch3])*SIN45, -1*vexRT[ch1]);
    // EXPERIMENTAL THREE!!!
    motor[motor_ne] = (int)struggle((float)(vexRT[ch3]-vexRT[ch4])*sin(atan(vexRT[ch3]/vexRT[ch4])), -1*vexRT[ch1]);
    motor[motor_se] = (int)struggle((float)(vexRT[ch4]+vexRT[ch3])*sin(atan(vexRT[ch3]/vexRT[ch4])), -1*vexRT[ch1]);
    motor[motor_sw] = (int)struggle((float)(vexRT[ch4]-vexRT[ch3])*sin(atan(vexRT[ch3]/vexRT[ch4])), -1*vexRT[ch1]);
    motor[motor_nw] = (int)struggle(-1*(float)(vexRT[ch4]+vexRT[ch3])*sin(atan(vexRT[ch3]/vexRT[ch4])), -1*vexRT[ch1]);
  }
}
