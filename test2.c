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
#include"point_turn.c"

/******************************************************************************
 * Test 2: Sonar-controlled robot that never run into the wall.
 *****************************************************************************/
#define POWER 63
#define TRACK 5.5
#define WHEEL_SIZE 1.75

void run(int dir, int power) {
  // Run until 20cm away from obsticle.
  while(SensorValue(sonar) >= 30 || SensorValue(sonar) == -1) {
    motor[motor_w] = power;
    motor[motor_e] = power;
  }
  
  // Point-turn to left/right.
  swing_turn(dir, power, TRACK, WHEEL_SIZE);

  // Keep going.
  run(dir, power);
}

task main() {
  run(1, POWER);
}

