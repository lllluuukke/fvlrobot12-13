#pragma config(Sensor, in1,    lnf_0,    sensorLineFollower)
#pragma config(Sensor, in2,    lnf_1,    sensorLineFollower)
#pragma config(Sensor, in3,    lnf_2,    sensorLineFollower)
#pragma config(Sensor, in4,    poten,    sensorPotentiometer)
#pragma config(Sensor, dgtl1,  quad_e,   sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  quad_w,   sensorQuadEncoder)
#pragma config(Sensor, dgtl6,  touch_w,  sensorTouch)
#pragma config(Sensor, dgtl7,  touch_e,  sensorTouch)
#pragma config(Sensor, dgtl8,  sonar,    sensorSONAR_inch)
#pragma config(Motor,  port1,  motor_w,  tmotorVex269,      openLoop)
#pragma config(Motor,  port10, motor_e,  tmotorVex269,      openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*****************************************************************************
 * Test 0: simple movements.
 * Go forward
 * Go backward
 * Point turn left
 * Point turn right
 * Swint turn left forward
 * Swint turn right forward
 * Swint turn left backward
 * Swint turn right backward
 ****************************************************************************/

#define TIME 132
#define POWER 63

task main() {
  //int speed = SensorValue[poten]/32;

  // Going forward for .5 sec
  motor[motor_w] = POWER;
  motor[motor_e] = POWER;
  wait10Msec(TIME);
  // Going backward for .5 sec
  motor[motor_w] = -1*POWER;
  motor[motor_e] = -1*POWER;
  wait10Msec(TIME);
  //point turn left for .5 sec
  motor[motor_w] = -1*POWER;
  motor[motor_e] = POWER;
  wait10Msec(TIME);
  //point turn right for .5 sec
  motor[motor_w] = POWER;
  motor[motor_e] = -1*POWER;
  wait10Msec(TIME);
  //swing turn left forward for .5 sec
  motor[motor_w]=0;
  motor[motor_e] = POWER;
  wait10Msec(TIME);
  //swing turn right forward for .5 sec
  motor[motor_w] = POWER;
  motor[motor_e]=0;
  wait10Msec(TIME);
  //swing turn left backward for .5 sec
  motor[motor_w]=0;
  motor[motor_e] = -1*POWER;
  wait10Msec(TIME);
  //swing turn right backward for .5 sec
  motor[motor_w] = -1*POWER;
  motor[motor_e]=0;
  wait10Msec(TIME);
}

