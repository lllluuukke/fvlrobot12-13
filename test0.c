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

