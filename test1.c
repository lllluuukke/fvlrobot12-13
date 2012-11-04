#include"point_turn.c"
#pragma config(Sensor, in1,    lnf_0,    sensorLineFollower)
#pragma config(Sensor, in2,    lnf_1,    sensorLineFollower)
#pragma config(Sensor, in3,    lnf_2,    sensorLineFollower)
#pragma config(Sensor, in4,    poten,    sensorPotentiometer)
#pragma config(Sensor, dgtl1,  quad_e,   sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  quad_w,   sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  touch_w,  sensorTouch)
#pragma config(Sensor, dgtl6,  touch_e,  sensorTouch)
#pragma config(Sensor, dgtl7,  sonar,    sensorSONAR_inch)
#pragma config(Motor,  port1,  motor_w,  tmotorVex269,      openLoop)
#pragma config(Motor,  port10, motor_e,  tmotorVex269,      openLoop, reversed)

/*****************************************************************************
 * This file is intend to test basic sensor-controlled movements.
 *
 * Test 1: Quadrature-controlled movements.
 * Go forward 1 wheel turn
 ****************************************************************************/
#define POWER 63

task main() {
  int rev = 1;
  int angel = rev*360;

  // Clear sensors.
  SensorValue(quad_w) = 0;
  SensorValue(quad_e) = 0;

  while(SensorValue(quad_e) <= angel && SensorValue(quad_w) >= -1*angel) {
    motor[motor_w] = POWER;
	motor[motor_e] = POWER;
  }
}

