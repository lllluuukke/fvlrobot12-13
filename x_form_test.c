#pragma config(Motor,  port2,  motor_ne,  tmotorVex269,  openLoop)
#pragma config(Motor,  port3,  motor_se,  tmotorVex269,  openLoop)
#pragma config(Motor,  port4,  motor_sw,  tmotorVex269,  openLoop)
#pragma config(Motor,  port5,  motor_nw,  tmotorVex269,  openLoop)

/******************************************************************************
 * EXPERIMENTAL!!!
 * This file controls a holonomic x-formed robot base.
 *****************************************************************************/
#define POWER 63
#define TIME 2

void move(int dir) {
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
  pwr = dir?-1:1;
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

task main() {
  forward();
  backward();
  move_left();
  move_right();
  turn_left();
  turn_right();
}
