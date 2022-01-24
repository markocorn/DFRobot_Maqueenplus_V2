/*!
 * @file patrol.ino
 * @brief Complete the line-tracking using the MaqueenPlus line-tracking sensor 
 * @details Maqueen Plus follows the black lines on the map
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
  if(MaqueenPlus.getPatrol(MaqueenPlus.eL2) == 0 &&  MaqueenPlus.getPatrol(MaqueenPlus.eL1) == 1 && MaqueenPlus.getPatrol(MaqueenPlus.eR1) == 1 && MaqueenPlus.getPatrol(MaqueenPlus.eR2) == 0){
    MaqueenPlus.motorControl(MaqueenPlus.eALL, MaqueenPlus.eCW, 50); 
  }else{
    if(MaqueenPlus.getPatrol(MaqueenPlus.eL2) == 0 &&  MaqueenPlus.getPatrol(MaqueenPlus.eL1) == 0 && MaqueenPlus.getPatrol(MaqueenPlus.eR1) == 1 && MaqueenPlus.getPatrol(MaqueenPlus.eR2) == 1){
      MaqueenPlus.motorControl(MaqueenPlus.eLEFT, MaqueenPlus.eCW, 160);
      MaqueenPlus.motorControl(MaqueenPlus.eRIGHT, MaqueenPlus.eCW, 50);
    }else if(MaqueenPlus.getPatrol(MaqueenPlus.eL2) == 0 &&  MaqueenPlus.getPatrol(MaqueenPlus.eL1) == 0 && MaqueenPlus.getPatrol(MaqueenPlus.eR1) == 0 && MaqueenPlus.getPatrol(MaqueenPlus.eR2) == 1){
      MaqueenPlus.motorControl(MaqueenPlus.eLEFT, MaqueenPlus.eCW, 200);
      MaqueenPlus.motorControl(MaqueenPlus.eRIGHT, MaqueenPlus.eCW, 50);
    }if(MaqueenPlus.getPatrol(MaqueenPlus.eL2) == 1 &&  MaqueenPlus.getPatrol(MaqueenPlus.eL1) == 1 && MaqueenPlus.getPatrol(MaqueenPlus.eR1) == 0 && MaqueenPlus.getPatrol(MaqueenPlus.eR2) == 0){
      MaqueenPlus.motorControl(MaqueenPlus.eLEFT, MaqueenPlus.eCW, 50);
      MaqueenPlus.motorControl(MaqueenPlus.eRIGHT, MaqueenPlus.eCW, 160);
    }else if(MaqueenPlus.getPatrol(MaqueenPlus.eL2) == 1 &&  MaqueenPlus.getPatrol(MaqueenPlus.eL1) == 0 && MaqueenPlus.getPatrol(MaqueenPlus.eR1) == 0 && MaqueenPlus.getPatrol(MaqueenPlus.eR2) == 0){
      MaqueenPlus.motorControl(MaqueenPlus.eLEFT, MaqueenPlus.eCW, 50);
      MaqueenPlus.motorControl(MaqueenPlus.eRIGHT, MaqueenPlus.eCW, 200);
    }
  }
}