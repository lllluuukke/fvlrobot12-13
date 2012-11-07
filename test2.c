/******************************************************************************
 * Test 2: Sonar-controlled robot that never run into the wall.
 *****************************************************************************/

void turn() {
  // Stop motors.
  motor[motor_w] = 0;
  motor[motor_e] = 0;
  // Clear sensors.
  SensorValue[quad_w] = 0;
  SensorValue[quad_e] = 0;

  while(SensorValue[quad_e] <= 500)
    motor[motor_e] = POWER;
    motor[motor_e] = 0;
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
