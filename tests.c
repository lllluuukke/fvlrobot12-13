#pragma config(Sensor, in1,    lnf_0,    sensorLineFollower)
#pragma config(Sensor, in2,    lnf_1,    sensorLineFollower)
#pragma config(Sensor, in3,    lnf_2,    sensorLineFollower)
#pragma config(Sensor, in4,    poten,    sensorPotentiometer)
#pragma config(Sensor, dgtl1,  quad_e,   sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  quad_w,   sensorQuadEncoder)
#pragma config(Sensor, dgtl6,  touch_w,  sensorTouch)
#pragma config(Sensor, dgtl7,  touch_e,  sensorTouch)
#pragma config(Sensor, dgtl8,  sonar,    sensorSONAR_mm)
#pragma config(Motor,  port2,  motor_w,  tmotorVex393,      openLoop)
#pragma config(Motor,  port3,  motor_e,  tmotorVex393,      openLoop, reversed)

//#include "point_turn.c"
//#include "swing_turn.c"

#define TIME 132
#define POWER 63
#define TRACK 5.5
#define WHEEL_SIZE 1.75

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

void test0() {
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

/*****************************************************************************
 * Test 1: Quadrature-controlled movements.
 * Go forward 1 wheel turn
 ****************************************************************************/

void test1() {
  int rev = 1;
  int angel = rev*360;

  // Clear sensors.
  SensorValue[quad_w] = 0;
  SensorValue[quad_e] = 0;

  while(SensorValue[quad_e] <= angel && SensorValue[quad_w] <= angel) {
    motor[motor_w] = POWER;
	motor[motor_e] = POWER;
  }
}

/******************************************************************************
 * Test 2: Sonar-controlled robot that never run into the wall.
 *****************************************************************************/

void turn() {
  // Backup for 1 sec.
  motor[motor_w] = -1*POWER;
  motor[motor_e] = -1*POWER;
  wait10Msec(100);
  // Clear sensors.
  SensorValue[quad_w] = 0;
  SensorValue[quad_e] = 0;

  while(SensorValue[quad_e] <= 150)
    motor[motor_e] = POWER;
    motor[motor_w] = 0;
}

void run() {
    motor[motor_w] = POWER;
    motor[motor_e] = POWER;
}

void test2() {
  // Clear sensors.
  SensorValue[quad_w] = 0;
  SensorValue[quad_e] = 0;

  while(1) {
    // Run until 750 mm away from obsticle.
    if(SensorValue(sonar) >= 750 || SensorValue(sonar) == -1) {
      run();
    }
    else
      turn();
  }
}

// EXPERIMENTAL!!! The real algorithm should base on results of test1.

/******************************************************************************
 * From previous observation, motors move in different rate when same speed
 * is set.
 * This function is designed to syncronize 2 moters in order for the robot to
 * move straight.
 *
 * Set a original power level, run both motor for a while. Then compare the
 * quadurater sensor values. If one is greater than the other, reduce its
 * coresponding motor's power level(by 1?).
 * This percedure should be executed recursively until an balance is reached.
 *****************************************************************************/

void motor_sync(int power_w, int power_e) {
  int sen_w, sen_e;

  while(1) {
    // Clear sensors.
    SensorValue[quad_w] = 0;
    SensorValue[quad_e] = 0;

    // Run 1 sec.
    motor[motor_w] = power_w;
    motor[motor_e] = power_e;
    wait10Msec(100);

    // Compare sensor values and make change if differnet greater than 1%.
    sen_w = abs(SensorValue[quad_w]);
    sen_e = abs(SensorValue[quad_e]);
    if(abs(sen_w - sen_e) > 4) {
	  power_e = sen_w > sen_e ? power_e + 1 : power_e - 1;
      motor_sync(power_w, power_e)
    }
    // Then run for 10 sec.
    else {
      motor[motor_w] = -1*power_w;
      motor[motor_e] = -1*power_e;
      wait10Msec(1000);
    }
  }
}

task main() {
  // Clear sensors.
  SensorValue[quad_w] = 0;
  SensorValue[quad_e] = 0;

 // declare power vars for each motor.
  int power_w = POWER;
  int power_e = POWER;

  while(1)
    motor_sync(power_w, power_e);
}
