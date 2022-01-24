/*!
 * @file patrol.ino
 * @brief MaqueenPlus RGB LEDs light up in different colors
 * @details MaqueenPlus RGB LEDs light up in differernt colors repeatedly
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
}

void loop() {
  MaqueenPlus.setRGB(MaqueenPlus.eALL, MaqueenPlus.eRED);
  delay(100);
  MaqueenPlus.setRGB(MaqueenPlus.eALL, MaqueenPlus.eGREEN);
  delay(100);
  MaqueenPlus.setRGB(MaqueenPlus.eALL, MaqueenPlus.eBLUE);
  delay(100);
  MaqueenPlus.setRGB(MaqueenPlus.eALL, MaqueenPlus.eYELLOW);
  delay(100);
  MaqueenPlus.setRGB(MaqueenPlus.eALL, MaqueenPlus.ePINK);
  delay(100);
  MaqueenPlus.setRGB(MaqueenPlus.eALL, MaqueenPlus.eCYAN);
  delay(100);
  MaqueenPlus.setRGB(MaqueenPlus.eALL, MaqueenPlus.eWHITH);
  delay(100);
  MaqueenPlus.setRGB(MaqueenPlus.eALL, MaqueenPlus.ePUT);
  delay(100);
}