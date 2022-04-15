#include <DistanceMeasure.h>


U8G2_SSD1306_128X64_NONAME_F_HW_I2C Disp(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
UltraSonicDistanceSensor distanceSensor(18, 17);  // Initialize sensor that uses digital pins 13 and 12.


void setup(void) {
  Serial.begin(115200);

  Disp.begin();  
  Disp.clearBuffer();					// clear the internal memory
  Disp.setFont(u8g2_font_helvR10_tr);	// choose a suitable font
  // u8g2.drawStr(0,12,"DistanceMeasure");	// write something to the internal memory
  // u8g2.sendBuffer();					// transfer internal memory to the display
  shellInit();

  
}

void loop(void) 
{
  double distance=0;
  distance = distanceSensor.measureDistanceCm();
  
  Disp.clearBuffer();	 
  // Serial.println(distance);
  Disp.setFont(u8g2_font_freedoomr25_mn);
  Disp.setCursor(0, 26);
  Disp.printf("%.01fcm",distance);
  Disp.sendBuffer();
  ShellLoop();
  
}

