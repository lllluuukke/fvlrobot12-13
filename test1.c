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

