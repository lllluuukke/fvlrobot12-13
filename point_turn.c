// EXPERIMENTAL!!! The real algorithm should base on results of test1.

/****************************************************************************
 * A function that turns wheels in opposite directions on opposite sides
 * besed on direction(0 for left, 1 for right), power level, axle track(L),
 * and wheel size(r).
 * 
 * Each wheel travels 2*pi*(L/2)/4 = L*pi/4
 * For each revolution the wheel moves 2*pi*r
 * Thus it needs n revolutions for the robot to turn in place such that
 * L*pi*4 = 2*pi*r*n
 * n = L*pi*4/2/pi/r = L/(8*r)
 ***************************************************************************/

void point_turn(int dir, int power, float track, float wheel_size) {
  float rev = track/(8*wheel_size);
  int angle = 360*rev;

  // Clear sensors.
  SensorValue[quad_w] = 0;
  SensorValue[quad_e] = 0;

  // Left
  if(!dir) {
    while(SensorValue(quad_e) <= angle && SensorValue(quad_w) >= -1*angle) {
      motor_w(-1*power);
	  motor_e(power);
    }
  }
  // Right
  else {
    while(SensorValue[quad_e] >= -1*angle && SensorValue[quad_w] <= angle) {
	  motor_w(power);
	  motor_e(-1*power);
	}
  }
}

