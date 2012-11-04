// EXPERIMENTAL!!! The real algorithm should base on results of test1.

/******************************************************************************
 * A function that turns the robot 90 degrees by turning the wheels of only one
 * side based on direction(0 for left, 1 for right), power level, axle
 * track(L), and wheel size(r).
 *
 * The turning wheel travels 2*pi*L/4 = pi*L/2
 * For each revolution the wheel moves 2*pi*r
 * Thus it needs n revolutions for the robot to turn in place such that
 * pi*L/2 = 2*pi*r*n
 * n = pi*L/2/2/pi/r = L/(4*r)
 *****************************************************************************/

void swing_turn(int dir, int power, float track, float wheel_size) {
  float rev = track/(4*wheel_size);
  int angle = 360*rev;

  // Clear sensors.
  SensorValue[quad_w] = 0;
  SensorValue[quad_e] = 0;

  // Left
  if(!dir) {
    while(SensorValue[quad_e] <= angle)
	  motor[motor_e] = power;
  }
  // Right
  else if(dir) {
    while(SensorValue[quad_w] <= angle)
	  motor[motor_w] = power;
  }
}

