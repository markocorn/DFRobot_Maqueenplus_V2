/*!
 * @file patrol.ino
 * @brief MaqueenPlus avoid obstacles
 * @details When the distance between MaqueenPlus and obstacle ahead is less than 20cm, MaqueenPlus draws back to avoid it
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
  //Receive the distance returned by ultrasoinc sensor
  uint8_t distance  = MaqueenPlus.ultraSonic(MaqueenPlus.eP0, MaqueenPlus.eP1);

  if(distance < 20 && distance != 0){
    MaqueenPlus.motorControl(MaqueenPlus.eLEFT, MaqueenPlus.eCCW, 160);
    MaqueenPlus.motorControl(MaqueenPlus.eRIGHT, MaqueenPlus.eCCW, 50);
    delay(500);
  }else{
    MaqueenPlus.motorControl(MaqueenPlus.eALL, MaqueenPlus.eCW, 50);
  }
}