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
  // declare power vars for each motor.
  int power_w = POWER;
  int power_e = POWER;
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

