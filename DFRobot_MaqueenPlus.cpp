/*!
 * @file DFRobot_MaqueenPlus.h
 * @brief This is a library for MaqueenPlus from DFRobot
 * @details This library can be used to control the corresponding sensors on MaqueenPlus to complete different projects and functions
 * @copyright    Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @licence      The MIT License (MIT)
 * @author       [TangJie](jie.tang@dfrobot.com)
 * @version      V1.0.1
 * @eGDAte       2020-09-15
 * @url          https://github.com/DFRobot/DFRobot_MaqueenPlus
 */
#include "DFRobot_MaqueenPlus.h"
volatile uint32_t _tmp=0;
  volatile int _counter=0;
  volatile unsigned long _ts;
  volatile uint32_t _data;
uint8_t DFRobot_MaqueenPlus::begin(void)
{
  uint8_t buf[2];
  _pWire->begin(_pSDA,_pSCL);
  if(readReg(0, buf, 2) == 2){
    return 0;
  }
  return -1;
}
void DFRobot_MaqueenPlus::PIDSwitch(ePID state)
{
  uint8_t buf[1];
  buf[0] = state;
  writeReg(0X0A,buf,1);
}
void DFRobot_MaqueenPlus::motorControl(ePosition motor, eDir direction, uint8_t speed)
{
  uint8_t buf[4];
  if(speed >= 240){
  speed = 240;
  }
  switch(motor){
    case DFROBOT_MAQUEEMPLUS_LEFT:
      buf[0] = direction;
      buf[1] = speed;
      writeReg(0x00, buf, 2);
      break;
    case DFROBOT_MAQUEEMPLUS_RIGHT:
      buf[0] = direction;
      buf[1] = speed;
      writeReg(0x02, buf, 2);
      break;
    default:
      buf[0] = direction;
      buf[1] = speed;
      buf[2] = direction;
      buf[3] = speed;
      writeReg(0x00, buf, 4);
  }
}
uint8_t DFRobot_MaqueenPlus::getSpeed(ePosition motor)
{
  uint8_t buf[4],speed;
  readReg(0, buf, 4);
  switch(motor){
    case DFROBOT_MAQUEEMPLUS_LEFT:
      if(buf[1] <= 20 && buf[1] != 0){
        speed = buf[1] + 255;
      }else{
        speed = buf[1];
      }
      break;
    default:
      if(buf[3] <= 20 && buf[3] != 0){
        speed = buf[3] + 255;
      }else{
        speed = buf[3];
      }
  }
  return speed;
}
uint8_t DFRobot_MaqueenPlus::getDirection(ePosition motor)
{
  uint8_t buf[4],dir;
  readReg(0, buf, 4);
  switch(motor){
    case DFROBOT_MAQUEEMPLUS_LEFT:
      dir = buf[0];
      break;
    default:
      dir = buf[2];
  }
  return dir;
}
float DFRobot_MaqueenPlus::getDistance(ePosition motor)
{
  uint8_t buf[4];
  float dis;
  readReg(4, buf, 4);
  switch(motor){
    case DFROBOT_MAQUEEMPLUS_LEFT:
      dis = (float)(((buf[0]<<8)|buf[1]) * 10)/900;
      break;
    default:
      dis = (float)(((buf[2]<<8)|buf[3]) * 10)/900;
  }
  //DBG(dis);
  return dis;
}
void DFRobot_MaqueenPlus::clearDistance(ePosition motor)
{
  
  switch(motor){
    case DFROBOT_MAQUEEMPLUS_LEFT:
    uint8_t buf[2];
    buf[0] = 0;
    buf[1] = 0;
    writeReg(0x04, buf, 2);
    break;
    case DFROBOT_MAQUEEMPLUS_RIGHT:
    uint8_t buf1[2];
    buf1[0] = 0;
    buf1[1] = 0;
    writeReg(0x06, buf1, 2);
    default:
    uint8_t buf2[4];
    buf2[0] = 0;
    buf2[1] = 0;
    buf2[2] = 0;
    buf2[3] = 0;
    writeReg(0x04, buf2, 4);
  }
}
uint8_t DFRobot_MaqueenPlus::getPatrol(ePatrol sensor)
{
  uint8_t buf[1],state;
  readReg(0x1D, buf, 1);
  switch(sensor){
    case DFROBOT_MAQUEEMPLUS_L1: 
      state = (buf[0] & 0x04) == 0x04 ? 1 : 0;
      break;
    case DFROBOT_MAQUEEMPLUS_L2:
      state = (buf[0] & 0x02) == 0x02 ? 1 : 0;
      break;
    case DFROBOT_MAQUEEMPLUS_R1:
      state = (buf[0] & 0x08) == 0x08 ? 1 : 0;
      break;
    case DFROBOT_MAQUEEMPLUS_R2:
      state = (buf[0] & 0x10) == 0x10 ? 1 : 0;
      break;
    case DFROBOT_MAQUEEMPLUS_L3:
      state = (buf[0] & 0x01) == 0x01 ? 1 : 0;
      break;
    case DFROBOT_MAQUEEMPLUS_R3:
      state = (buf[0] & 0x20) == 0x20 ? 1 : 0;
      break;
    default:
      state = -1;
  }
  return state;
}
uint16_t DFRobot_MaqueenPlus::getGrayscale(ePatrol senser)
{
  uint8_t buf[12],patrol_AD;
  readReg(0x1E, buf, 12);
  switch(senser){
    case DFROBOT_MAQUEEMPLUS_L1: 
      patrol_AD = (buf[4]<<8)|buf[5];
      break;
    case DFROBOT_MAQUEEMPLUS_L2:
      patrol_AD = (buf[2]<<8)|buf[3];
      break;
    case DFROBOT_MAQUEEMPLUS_R1:
      patrol_AD = (buf[6]<<8)|buf[7];
      break;
    case DFROBOT_MAQUEEMPLUS_R2:
      patrol_AD = (buf[8]<<8)|buf[9];
      break;
    case DFROBOT_MAQUEEMPLUS_L3:
      patrol_AD = (buf[0]<<8)|buf[1];
      break;
    case DFROBOT_MAQUEEMPLUS_R3:
      patrol_AD = (buf[10]<<8)|buf[11];
      break;
    default:
      patrol_AD = -1;
  }
  return patrol_AD;
} 
void DFRobot_MaqueenPlus::setRGB(ePosition light, eColor color)
{
  uint8_t buf[2];
  switch(light){
    case DFROBOT_MAQUEEMPLUS_LEFT:
      buf[0] = color;
      writeReg(0x0B, buf, 1);
      break;
    case DFROBOT_MAQUEEMPLUS_RIGHT:
      buf[0] = color;
      writeReg(0x0C, buf, 1);
      break;
    default:
      buf[0] = color;
      buf[1] = color;
      writeReg(0x0B, buf, 2);
  }
}
void DFRobot_MaqueenPlus::servoControl(eServo servo, uint8_t angle)
{
  uint8_t buf[1];
  switch(servo){
    case DFROBOT_MAQUEEMPLUS_S1:
      buf[0] = angle;
      writeReg(0x14, buf, 1);
      break;
    case DFROBOT_MAQUEEMPLUS_S2:
      buf[0] = angle;
      writeReg(0x15, buf, 1);
      break;
    default:
      buf[0] = angle;
      writeReg(0x16, buf, 1);
  }
}
uint8_t DFRobot_MaqueenPlus::ultraSonic(ePin trig, ePin echo)
{
  uint16_t d=0;
	_echoPin = echo;
	_trlgPin = trig;
	pinMode(_echoPin, INPUT);
	pinMode(_trlgPin, OUTPUT);
	if(digitalRead(_echoPin) == LOW){
		digitalWrite(_trlgPin, HIGH);
		digitalWrite(_trlgPin, LOW);
		_duration = myPulseIn(_echoPin, HIGH);
	}else{
		digitalWrite(_trlgPin, LOW);
		digitalWrite(_trlgPin, HIGH);
		_duration = myPulseIn(_echoPin, LOW);
	}
  d = _duration/59;
	if(d <= 0||d > 500){
		return 0;
	}else if(d>30){
    return d-=2;
  }
  delay(20);
	return d;
}
uint64_t DFRobot_MaqueenPlus::myPulseIn(uint32_t pin, uint32_t value, long maxDuration)
{
  int pulse = value == HIGH ? 1 : 0;
  uint64_t tick =  micros();
  uint64_t maxd = (uint64_t)maxDuration;
  while(digitalRead(pin) != pulse) {
    if(micros() - tick > maxd)
      return 0;
  }
  uint64_t start =  micros();
  while(digitalRead(pin) == pulse) {
    if(micros() - tick > maxd)
      return 0;
    }
  uint64_t end =  micros();
  return end - start;
}
void IR_INT() 
{
  unsigned long long x = micros();
  unsigned long interval = x - _ts;
  _ts = x;
  if(interval > 3000){
    _counter = 0;
    _tmp = 0;
    return;
  }
  if((interval > 2000) && (interval<2500)){
    _tmp <<= 1;
    _tmp |=  1;
  }else{
    _tmp <<= 1;
  }
  _counter++;
  if(_counter == 32){
    _data = (_tmp)&0xffffffff;
    _counter = 0;
  }
}
uint32_t DFRobot_MaqueenPlus::getIR(void)
{
  pinMode(DFROBOT_MAQUEEMPLUS_IRPIN,INPUT);
  attachInterrupt(DFROBOT_MAQUEEMPLUS_IRPIN,IR_INT,RISING);
  return _data;
}
String DFRobot_MaqueenPlus::getVersion(void)
{
  uint8_t versionLen,buf[20];
  readReg(0x32, buf, 1);
  versionLen = buf[0];
  readReg(0x33, buf, versionLen);
  return (char*)buf;
}
void DFRobot_MaqueenPlus::writeReg(uint8_t reg, void *pBuf, size_t size)
{
  uint8_t *_pBuf = (uint8_t*)pBuf;
  _pWire->beginTransmission(_address);
  _pWire->write(reg);

  for(size_t i = 0; i < size; i++){
    _pWire->write(_pBuf[i]);
  }
  _pWire->endTransmission();
}
uint8_t DFRobot_MaqueenPlus::readReg(uint8_t reg, void *pBuf, size_t size)
{
  if(pBuf == NULL){
    return 0;
  }
  uint8_t *_pBuf = (uint8_t*)pBuf;
  _pWire->beginTransmission(_address);
  _pWire->write(reg);
  if(_pWire->endTransmission() != 0) {
    return 0;
  }
  delay(10);
  _pWire->requestFrom(_address, size);
  for(size_t i = 0; i < size; i++){
    _pBuf[i] = _pWire->read();
  }
  return size;
}