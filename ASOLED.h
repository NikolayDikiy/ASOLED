/*
  ASOLED.h - 0.96' I2C 128x64 OLED Driver Library
  ver. 0.2a

  2015 Copyright (c) Sergey Andrianov

  Please, do not distribute this library. 
  It is not ready yet. Work is not complete. 
  It is a preliminary variant exceptionally for testing.
*/

#ifndef ASOLED_data_H
#define ASOLED_data_H

#include <Arduino.h>

#define ASOLED_Max_X				128	//128 Pixels
#define ASOLED_Max_Y				64	//64  Pixels

#define OLED_ADDRESS				0x3C // 0x78
#define I2C_400KHZ					1	// 0 to use default 100Khz, 1 for 400Khz

#define Font_6x8            1
#define Font_12x16          2

#define NORMAL              1
#define INVERTED            2


class ASOLED {

public:
  void init();
  void setFont(const char font); // set current font size (CurrFont) [Font_6x8 | Font_12x16]
  void printString(const char *String, byte X=255, byte Y=255, const char inverted=NORMAL);  // Print inverted or normal string with current font
	void printString_6x8(const char *String, byte X=255, byte Y=255, const char inverted=NORMAL);  //  font 6x8, switch CurrFont to Font_6x8
  void printString_12x16(const char *String, byte X=255, byte Y=255, const char inverted=NORMAL);  // font 12x16, switch CurrFont to Font_12x16

	byte printNumber(long n, byte X=255, byte Y=255); // current font
	byte printNumber(float float_num, byte prec=6, byte Y=255, byte numChar=255); // current font
	void drawBitmap(const byte *bitmaparray, byte X, byte Y, byte width, byte height); // X - in 1 pixel, Y - in 8 pixels
  void drawBitmap(const byte *bitmaparray, byte X, byte Y); // X - in 1 pixel, Y - in 8 pixels unit

	void VertBar(int Num, int Val, int MinVal, int MaxVal); // draw vertical line from bottom, h ~ (Val - MinVal)/(MaxVal - MinVal)

	void clearDisplay();
	
	void setNormalDisplay();
	void setInverseDisplay();
	void setBrightness(byte Brightness);

  void setCursorXY(byte Column, byte Row); // X * 1 pixels, Y * 8 pixels
  byte GetCurrentX();  // get current X position in 1-pixel unit (from 9 to 127)
  byte GetCurrentY();  // get current Y position in 8-pixel unit (from 0 to 7)
private:
  void sendCommand(byte command);
  void sendData(byte Data);

  void printChar(char c);
  void setPowerOff();
  void setPowerOn();
  void setPageMode();
  void setHorizontalMode();

  byte addressingMode;

  char CurrFont = 1; // font size  [Font_6x8 | Font_12x16]
  char NumberString[16]; // 4 print numbers
  char CurrColor = 1; // normal or inverted font
  byte LenString = 0;   // current length of NumberString
  byte CurrX = 0;   // current position
  byte CurrY = 0;
};

extern ASOLED LD;  // ASOLED object 

#endif

