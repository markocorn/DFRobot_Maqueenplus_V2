/*!
 * @file patrol.ino
 * @brief Get the returned data of MaqueenPlus 
 * @details Serial port print the returned data of MaqueenPlus 
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
  MaqueenPlus.motorControl(MaqueenPlus.eALL, MaqueenPlus.eCW, 100);
}

void loop() {
  Serial.println("--------------------");
  Serial.print("Version:");
  Serial.println(MaqueenPlus.getVersion());
  Serial.println("--------------------");
  Serial.print("Speed_L:");
  Serial.println(MaqueenPlus.getSpeed(MaqueenPlus.eLEFT));
  Serial.print("Speed_R:");
  Serial.println(MaqueenPlus.getSpeed(MaqueenPlus.eRIGHT));
  Serial.println("--------------------");
  Serial.print("Direction_L:");
  Serial.println(MaqueenPlus.getDirection(MaqueenPlus.eLEFT));
  Serial.print("Direction_R:");
  Serial.println(MaqueenPlus.getDirection(MaqueenPlus.eRIGHT));
  Serial.println("--------------------");
  Serial.print("Distance_L:");
  Serial.println(MaqueenPlus.getDistance(MaqueenPlus.eLEFT));
  Serial.print("Distance_R:");
  Serial.println(MaqueenPlus.getDistance(MaqueenPlus.eRIGHT));
  Serial.println("--------------------");
  Serial.print("Grayscale_L1:");
  Serial.println(MaqueenPlus.getGrayscale(MaqueenPlus.eL1));
  Serial.print("Grayscale_L2:");
  Serial.println(MaqueenPlus.getGrayscale(MaqueenPlus.eL2));
  Serial.print("Grayscale_L3:");
  Serial.println(MaqueenPlus.getGrayscale(MaqueenPlus.eL3));
  Serial.print("Grayscale_R1:");
  Serial.println(MaqueenPlus.getGrayscale(MaqueenPlus.eR1));
  Serial.print("Grayscale_R2:");
  Serial.println(MaqueenPlus.getGrayscale(MaqueenPlus.eR2));
  Serial.print("Grayscale_R3:");
  Serial.println(MaqueenPlus.getGrayscale(MaqueenPlus.eR3));
  if(MaqueenPlus.getDistance(MaqueenPlus.eLEFT) >= 20 || MaqueenPlus.getDistance(MaqueenPlus.eRIGHT) >= 20){
    //clear the revolutions of wheel
    MaqueenPlus.clearDistance(MaqueenPlus.eALL);
  }
  delay(1000);
}
