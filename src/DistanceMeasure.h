#ifndef DISTANCEMEASURE_H
#define DISTANCEMEASURE_H

#include <Arduino.h>
#include <U8g2lib.h>
#include <HCSR04.h>
#include <MyShell.h>
#include <WiFi.h>
#include <SPI.h>
#include <Wire.h>
#include <MyDistance.h>
#include "Beep.h"
#include "BLE.h"
#include "BluetoothSerial.h"
#include "OneButton.h"
#include "Key.h"
#include "ExternDraw.h"
#include "Bitmap.h"

extern bool BtOutput;
extern uint8_t Volume;
extern bool AlarmOut;
extern bool Work;

extern BluetoothSerial SerialBT; 
extern OneButton KeyUP;
extern OneButton KeyDown;
extern OneButton KEYOk;
extern OneButton KeyCancel;
extern UltraSonicDistanceSensor distanceSensor;
extern U8G2_SSD1306_128X64_NONAME_F_HW_I2C Disp;

//引脚定义
#define BEEP_PIN 4

#define KEY_UP  18
#define KEY_DOWM  5
#define KEY_OK  17
#define KEY_CANCEL  16



 
#endif