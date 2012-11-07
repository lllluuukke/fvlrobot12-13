#pragma config(Motor,  port1,  motor_ne,  tmotorVex269,  openLoop)
#pragma config(Motor,  port2,  motor_se,  tmotorVex269,  openLoop)
#pragma config(Motor,  port3,  motor_sw,  tmotorVex269,  openLoop, reversed)
#pragma config(Motor,  port4,  motor_nw,  tmotorVex269,  openLoop, reversed)

/*****************************************************************************
 * EXPERIMENTAL!!!
 * This file controls a holonomic x-formed robot base.
 ****************************************************************************/
#define POWER 63
#define TIME 2

void move(int dir) {
  motor[motor_ne] = ((dir*dir+2)%3-1)*POWER;
  motor[motor_se] = (1-2*(dir&1))*POWER;
  motor[motor_sw] = (1-(dir*dir+2)%3)*POWER;
  motor[motor_nw] = (2*(dir&1)-1)*POWER;
  wait10Msec(100*TIME);

}

void forward(int time) {
  move(0);
}

void backward(int time) {
  move(1);
}

void move_left(int time) {
  move(2);
}

void move_right(int time) {
  move(3);
}

