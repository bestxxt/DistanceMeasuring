#include <DistanceMeasure.h>


U8G2_SSD1306_128X64_NONAME_F_HW_I2C Disp(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
UltraSonicDistanceSensor distanceSensor(18, 17);  // Initialize sensor that uses digital pins 13 and 12.
BluetoothSerial SerialBT;

void setup(void) {
  Serial.begin(115200);//串口初始化

  Disp.begin();  
  Disp.clearBuffer();					// clear the internal memory
  Disp.sendBuffer();					// transfer internal memory to the display
  
  //蓝牙初始化
  BLE_Init();
  shellInit();

}

void loop(void) 
{
  double distance=0;
  distance = distanceSensor.measureDistanceCm();

  Data_Printf(distance);
  Disp.clearBuffer();	 
  Data_Printf(distance);
  Disp.setCursor(0, 21);
  Disp.setFont(u8g2_font_logisoso20_tr);
  Disp.printf("%.01fcm",distance);
  Disp.sendBuffer();
  ShellLoop();
  
}

