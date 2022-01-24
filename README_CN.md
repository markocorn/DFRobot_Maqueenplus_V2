# DFRobot_MaqueenPlus

* [English Version](./README.md)

Maqueen plus是一个STEM教育机器人。优化了更好的电源管理和更大容量的电源供应，它可以完全兼容哈士奇AI视觉传感器。
   
   ![Product Image](./resources/images/MBT0021.png)

## 产品链接(https://www.dfrobot.com/product-2026.html)
    SKU: MBT0021-EN

## 目录

  * [概述](#概述)
  * [库安装](#库安装)
  * [方法](#方法)
  * [兼容性](#兼容性)
  * [历史](#历史)
  * [创作者](#创作者)

## 概述

库中包含了麦昆Plus基本使用方法的用例，如红外、巡线传感器、RGB灯、超声波、舵机使用用例。

## 库安装

使用此库前，请首先下载库文件，将其粘贴到\Arduino\libraries目录中，然后打开examples文件夹并在该文件夹中运行演示。

## 方法

```C++
 /**
  * @fn begin
  * @brief 初始化I2C
  * @return uint8_t类型，表示返回初始化状态
  * @retval 0 初始化成功
  * @retval -1 初始化失败
  */
  uint8_t begin(void);

 /**
  * @fn PIDSwitch
  * @brief PID 操作控制
  * @param state PID状态选择
  * @return None
  */
  void PIDSwitch(ePID state);

 /**
  * @fn motorControl
  * @brief 麦昆plus电机控制
  * @param motor 电机选择
  * @param direction 旋转方向 
  * @param speed 电机速度(范围:0~255)
  * @return None
  */
  void motorControl(ePosition motor, eDir direction, uint8_t speed);

 /**
  * @fn getSpeed
  * @brief 获取速度
  * @param motor 电机选择
  * @return 返回选择电机旋转速度
  */
  uint8_t getSpeed(ePosition motor);

 /**
  * @fn getDirection
  * @brief 获取旋转方向
  * @param motor 电机选择 
  * @return  0: 停止 1: 前进 2: 后退
  */
  uint8_t getDirection(ePosition motor);

 /**
  * @fn getDistance
  * @brief  获取车轮旋转圈数
  * @param motor 电机选择
  * @return 返回车轮圈数
  */
  float getDistance(ePosition motor);

 /**
  * @fn clearDistance
  * @brief 清除车轮圈速
  * @param motor 电机选择
  * @return None
  */
  void clearDistance(ePosition motor);

 /**
  * @fn getPatrol
  * @brief  获取巡线传感器状态
  * @param senser 巡线传感器选择 
  * @return 返回巡线传感器状态
  */
  uint8_t getPatrol(ePatrol senser);

 /**
  * @fn getGrayscale
  * @brief 获取巡线传感器灰度值
  * @param senser 巡线传感器选择
  * @return  返回巡线传感器返回的灰度值
  */
  uint16_t getGrayscale(ePatrol senser);

 /**
  * @fn setRGB
  * @brief 设置RGB灯颜色
  * @param colour 颜色选择
  */
  void setRGB(ePosition light,eColor color);

 /**
  * @fn servoControl
  * @brief 舵机控制
  * @param servo 舵机选择
  * @param angle 控制舵机角度(范围:0°~180°)
  * @return None
  */
  void servoControl(eServo servo, uint8_t angle);

/**
 * @fn ultraSonic
 * @brief 获取超声波距离
 * @param trig   TRIG 引脚
 * @param echo   ECHO 引脚
 * @return  返回超声波测试距离
 */
  uint8_t ultraSonic(ePin trig, ePin echo);

 /**
  * @fn getIR
  * @brief 获取红外键值
  * @return  返回红外键值
  */
 uint32_t getIR(void);

 /**
  * @fn getVersion
  * @brief  获取版本信息
  * @return  返回版本信息
  */
  String getVersion(void); 
```

## 兼容性

主板               |     通过     |    未通过    |    未测试   |   备注   |
------------------ | :----------: | :----------: | :---------: | :-----: |
micro:bit          |      √       |              |             |         |

## 历史

- 2020/09/15 - 1.0.0 版本
- 2021/09/27 - 1.0.1版本


## 创作者

Written by TangJie(jie.tang@dfrobot.com), 2020. (Welcome to our [website](https://www.dfrobot.com/))





