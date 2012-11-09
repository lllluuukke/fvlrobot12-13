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

int max(int left, int right) {
  if(left > right)
    return left;
  else
    return right;
}

int min(int left, int right) {
  if(left > right)
    return right;
  else
    return left;
}

int struggle(int left, int right) {
  if(abs(left*right) != left*right || left*right == 0)
    return left+right;
  else if(left == right)
    return left;
  else {
    if(left > 0)
	  return max(left, right);
	else
	  return min(left, right);
  }
}

task main() {
  while(1) {
    motor[motor_ne] = (int)((float)(vexRT[ch3]-vexRT[ch4])*SIN45);
    motor[motor_se] = (int)((float)(vexRT[ch4]+vexRT[ch3])*SIN45);
    motor[motor_sw] = (int)((float)(vexRT[ch4]-vexRT[ch3])*SIN45);
    motor[motor_nw] = (int)(-1*(float)(vexRT[ch4]+vexRT[ch3])*SIN45);
    // EXPERIMENTAL!!!
    motor[motor_ne] =
	    (int)((float)(vexRT[ch3]-struggle(vexRT[ch4], vexRT[ch1]))*SIN45);
    motor[motor_se] =
	    (int)((float)(struggle(vexRT[ch4], vexRT[ch1])+vexRT[ch3])*SIN45);
    motor[motor_sw] =
	    (int)((float)(struggle(vexRT[ch4], vexRT[ch1])-vexRT[ch3])*SIN45);
    motor[motor_nw] =
	    (int)(-1*(float)(struggle(vexRT[ch4], vexRT[ch1])+vexRT[ch3])*SIN45);
  }
}
