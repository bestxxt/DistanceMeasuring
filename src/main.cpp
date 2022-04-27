#include <DistanceMeasure.h>


U8G2_SSD1306_128X64_NONAME_F_HW_I2C Disp(U8G2_R2, /* reset=*/ U8X8_PIN_NONE);
UltraSonicDistanceSensor distanceSensor(23, 19);  // Initialize sensor that uses digital pins 13 and 12.
BluetoothSerial SerialBT;
OneButton KeyUP = OneButton(KEY_UP,true,true);
OneButton KeyDown = OneButton(KEY_DOWM,true,true);
OneButton KEYOk = OneButton(KEY_OK,true,true);
OneButton KeyCancel = OneButton(KEY_CANCEL,true,true);

uint8_t Volume = true;
bool BtOutput = false;
bool AlarmOut = false;
bool Work = false;

void AlarmLoop(int16_t nub)
{
  static uint32_t LastTime = 0;
  if(AlarmOut)
  {
    if(nub<30 && nub >=15)
    {
      if(millis()-LastTime>500)
      {
        Draw_Slow_Bitmap(103, 0, alarm_photo, 24, 24);
        SetSound(alarm1);
        LastTime=millis();
      }
    }
    else if(nub<15 && nub>=0)
    {
      if(millis()-LastTime>200)
      {
        Draw_Slow_Bitmap(103, 0, stop_photo, 24, 24);
        SetSound(alarm2);
        LastTime=millis();
      }
    }
    else if(nub>0)
    {
      if(millis()-LastTime>1000)
      {
        SetSound(alarm0);
        LastTime=millis();
      }
    }
  }
  if(nub<30 && nub >=15)
  {  
    Draw_Slow_Bitmap(103, 0, alarm_photo, 24, 24);
  }
  else if(nub<15 && nub>=0)
  {
    Draw_Slow_Bitmap(103, 0, stop_photo, 24, 24);
  }

}

void setup(void) {
  Serial.begin(115200);//串口初始化

  Disp.begin();  
  Disp.clearBuffer();					// clear the internal memory
  Disp.sendBuffer();					// transfer internal memory to the display
  
  //蓝牙初始化
  BLE_Init();
  shellInit();
  BeepInit();   //蜂鸣器
  Key_Init(); //键盘初始化

}

void loop(void)  
{
  double distance=0;
  KeyLoop();
  ShellLoop();
  PlaySoundLoop();
  if(Work)
  {
    distance = distanceSensor.measureDistanceCm();
    Data_Printf(distance);
    Disp.clearBuffer();	 
    Disp.setCursor(0, 63);
    Disp.setFont(u8g2_font_logisoso24_tr);
    Disp.printf("%.01fcm",distance);
    if (BtOutput){Draw_Slow_Bitmap(0, 0, IMG_BLE_S, 9, 11);}  
    AlarmLoop(int16_t(distance));
    
    Disp.sendBuffer();
  }
  else
  {
    AlarmOut=false;
    Disp.clearBuffer();	
    Disp.sendBuffer();
  }
  
}

