/*!
 * @file patrol.ino
 * @brief Control servo via the servo port on MaqueenPlus 
 * @details Servo connected to port S1 of MaqueenPlus rotates from 0 to 180 degrees, and then back to 0. 
 * @copyright    Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license      The MIT License (MIT)
 * @author       [TangJie](jie.tang@dfrobot.com)
 * @version      V1.0.1
 * @date         2021-09-27
 * @url         https://github.com/DFRobot/DFRobot_MaqueenPlus
 */

#include <DFRobot_MaqueenPlus.h>

DFRobot_MaqueenPlus  MaqueenPlus;

void setup() { 
  //Initi serial print
  Serial.begin(9600);
  //Init I2C until success
  while(MaqueenPlus.begin() != 0){
    Serial.println("I2C initialization failed");
  }
  Serial.println("I2C initialization success");
  //Set RGB led color of MaqueenPlus 
  MaqueenPlus.setRGB(MaqueenPlus.eALL, MaqueenPlus.eYELLOW);
}

void loop() {
  for(uint8_t i=0; i<180; i++){
    MaqueenPlus.servoControl(MaqueenPlus.eS1, i);
    delay(100);
  }
  for(uint8_t i=180; i>0; i--){
    MaqueenPlus.servoControl(MaqueenPlus.eS1, i);
    delay(100);
  }
}