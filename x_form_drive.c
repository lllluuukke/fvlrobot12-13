#pragma config(Sensor, dgtl1,  touch,    sensorTouch)
#pragma config(Motor,  port2,  motor_ne, tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port3,  motor_se, tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port4,  motor_sw, tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port5,  motor_nw, tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port6,  motor_shoulder_e, tmotorVex393, openLoop)
#pragma config(Motor,  port7,  motor_shoulder_w, tmotorVex393, openLoop)
#pragma config(Motor,  port8,  motor_elbow, tmotorVex393, openLoop)

#define SIN45 .8509
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))

int struggle(int a, int b) {
  if(abs(a*b) != a*b || a*b == 0)
    return a+b;
  else if(a == b)
    return a;
  else {
    if(a > 0)
	  return MAX(a, b);
    return MIN(a, b);
  }
}

float _atan(float x) {
  float tn = atan(x)+PI/2;
  return vexRT[Ch3] > 0 ? tn : tn+PI;
}

int arm(int a, int b) {
  if(a == 1 && b == 0)
    return 1;
  else if(a == 0 && b == 1)
    return -1;
  return 0;
}

int hand(int a, int b, int state) {
  if(a == 1 && b == 1)
    return state;
  return arm(a,b);
}

void drop_bag() {
  motor[motor_elbow] = 127;
  wait10Msec(100);
}

task main() {
  int right = 0;
  int arm_state, hand_state = 0;
  while(1) {
	right = -vexRT[Ch1]/2;
    motor[motor_ne] =
	 struggle((int)(((float)(vexRT[Ch3]-vexRT[Ch4]))*SIN45), right);
    motor[motor_se] =
	 struggle((int)(((float)(vexRT[Ch4]+vexRT[Ch3]))*SIN45), right);
    motor[motor_sw] =
	 struggle((int)(((float)(vexRT[Ch4]-vexRT[Ch3]))*SIN45), right);
    motor[motor_nw] =
	 struggle((int)(((float)-1*(vexRT[Ch4]+vexRT[Ch3]))*SIN45), right);

    arm_state = 127*arm(vexRT[Btn5U], vexRT[Btn5D]);
	motor[motor_shoulder_e] = arm_state;
	motor[motor_shoulder_w] = arm_state;

    hand_state = 63*hand(vexRT[Btn6U], vexRT[Btn6D], hand_state);
	motor[motor_elbow] = hand_state;
	motor[motor_elbow] = hand_state;
  }
}
