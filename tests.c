#pragma config(Sensor, in1,    lnf_0,    sensorLineFollower)
#pragma config(Sensor, in2,    lnf_1,    sensorLineFollower)
#pragma config(Sensor, in3,    lnf_2,    sensorLineFollower)
#pragma config(Sensor, in4,    poten,    sensorPotentiometer)
#pragma config(Sensor, dgtl1,  quad_e,   sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  quad_w,   sensorQuadEncoder)
#pragma config(Sensor, dgtl6,  touch_w,  sensorTouch)
#pragma config(Sensor, dgtl7,  touch_e,  sensorTouch)
#pragma config(Sensor, dgtl8,  sonar,    sensorSONAR_inch)
#pragma config(Motor,  port2,  motor_w,  tmotorVex393,      openLoop)
#pragma config(Motor,  port3,  motor_e,  tmotorVex393,      openLoop, reversed)

#include"test0.c"
#include"test1.c"
#include"test2.c"
#include"motor_sync.c"
#include"point_turn.c"
#include"swing_turn.c"

#define TIME 132
#define POWER 63
#define TRACK 5.5
#define WHEEL_SIZE 1.75

task main() {
  test0();
  test1();
  test2();
  motor_sync()
}
