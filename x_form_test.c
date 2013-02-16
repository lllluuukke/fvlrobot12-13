#pragma config(Sensor, dgtl1,  touch,    sensorTouch)
#pragma config(Motor,  port2,  motor_ne, tmotorVex269, openLoop, reversed)
#pragma config(Motor,  port3,  motor_se, tmotorVex269, openLoop, reversed)
#pragma config(Motor,  port4,  motor_sw, tmotorVex269, openLoop, reversed)
#pragma config(Motor,  port5,  motor_nw, tmotorVex269, openLoop, reversed)

/******************************************************************************
 * EXPERIMENTAL!!!
 * This file controls a holonomic x-formed robot base.
 *****************************************************************************/
#define POWER 63
#define TIME 2

void move(int dir) {
  // 0 Forward, 1 Backward, 2 Left, 3 Roght
  motor[motor_ne] = ((dir*dir+2)%3-1)*POWER;
  motor[motor_se] = (1-2*(dir&1))*POWER;
  motor[motor_sw] = (1-(dir*dir+2)%3)*POWER;
  motor[motor_nw] = (2*(dir&1)-1)*POWER;
  wait10Msec(100*TIME);
}

void forward() {
  move(0);
}

void backward() {
  move(1);
}

void move_left() {
  move(2);
}

void move_right() {
  move(3);
}

void turn(int dir) {
  int pwr = dir?-1:1;
  motor[motor_ne] = pwr*POWER;
  motor[motor_se] = pwr*POWER;
  motor[motor_sw] = pwr*POWER;
  motor[motor_nw] = pwr*POWER;
  wait10Msec(100*TIME);
}

void turn_left() {
  turn(0);
}

void turn_right() {
  turn(1);
}

void _stop() {
  motor[motor_ne] = 0;
  motor[motor_se] = 0;
  motor[motor_sw] = 0;
  motor[motor_nw] = 0;
  motor[motor_shoulder_e] = 0;
  motor[motor_shoulder_w] = 0;
  motor[motor_elbow] = 0;
}

task main() {
  while(1) {
    if(SensorValue[touch]) {
      forward();
      backward();
      move_left();
      move_right();
      turn_left();
      turn_right();
      _stop();
    }
  }
}

/*task main() {
  int pw=20;
  while(!SensorValue[touch]) {
    motor[motor_ne] = pw;
    motor[motor_se] = pw;
    motor[motor_sw] = pw;
    motor[motor_nw] = pw;
    wait10Msec(TIME*200);
    motor[motor_ne] = 0;
    pw-=1;
  }
  motor[motor_ne] = pw;
  motor[motor_se] = pw;
  motor[motor_sw] = pw;
  motor[motor_nw] = pw;
}*/

// Lowest idle level: 10
// Lowest empty level: 12
// Lowest full-load level: 18
