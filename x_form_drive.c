#pragma config(Sensor, dgtl1,  touch,          sensorTouch)
#pragma config(Motor,  port2,           motor_ne,      tmotorVex269, openLoop, reversed)
#pragma config(Motor,  port3,           motor_se,      tmotorVex269, openLoop, reversed)
#pragma config(Motor,  port4,           motor_sw,      tmotorVex269, openLoop, reversed)
#pragma config(Motor,  port5,           motor_nw,      tmotorVex269, openLoop, reversed)

//#include "x_form_test.c"
/******************************************************************************
 * EXPERIMENTAL!!!
 * This file enables remote control of a holonomic x-formed robot base.
 *****************************************************************************/

task main() {
  while(1) {
    motor[motor_ne] = (vexRT[ch3]-vexRT[ch4])/sinDegrees(45)/2;
    motor[motor_se] = (vexRT[ch4]+vexRT[ch3])/sinDegrees(45)/2;
    motor[motor_sw] = (vexRT[ch4]-vexRT[ch3])/sinDegrees(45)/2;
    motor[motor_nw] = -1*(vexRT[ch4]+vexRT[ch3])/sinDegrees(45)/2;
  }
}
