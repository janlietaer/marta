#include <esp_now.h>
#include <WiFi.h>
#include <Wire.h>
#include <TFT_eSPI.h>
#include <Button2.h>
#include "TTGO_T_Display.h"

const uint8_t Waitsendms = 10;
#define CHANNEL 3
#define PRINTSCANRESULTS 0
#define DELETEBEFOREPAIR 0
#ifndef TFT_DISPOFF
#define TFT_DISPOFF 0x28
#endif

#ifndef TFT_SLPIN
#define TFT_SLPIN 0x10
#endif

#define TFT_MOSI 19
#define TFT_SCLK 18
#define TFT_CS 5
#define TFT_DC 16
#define TFT_RST 23

#define TFT_BL 4 // Display backlight control pin
#define ADC_EN 14
#define ADC_PIN 34
#define BUTTON_1 35
#define BUTTON_2 0

#define ledpin 32
#define ledpin1 27
#define ledpin2 26
#define ledpin3 25

TFT_eSPI tft = TFT_eSPI(135, 240); // Invoke custom library

void setup()
{
  Wire.begin();
  Serial.begin(115200);
  //Set device in STA mode to begin with
  WiFi.mode(WIFI_MODE_STA);
  Serial.println("ESPNow/Basic/Master Example");
  // This is the mac address of the Master in Station Mode
  Serial.print("STA MAC: ");
  Serial.println(WiFi.macAddress());
  // Init ESPNow with a fallback logic

  // Once ESPNow is successfully Init, we will register for Send CB to
  // get the status of Trasnmitted packet

  Serial.println("Start");
  tft.init();
  tft.setRotation(0);
  tft.fillScreen(TFT_BLACK);
  tft.setTextSize(2);
  tft.setTextColor(TFT_WHITE);
  tft.setCursor(0, 0);
  tft.setTextDatum(MC_DATUM);
  tft.setTextSize(1);

  if (TFT_BL > 0)
  {                                         // TFT_BL has been set in the TFT_eSPI library in the User Setup file TTGO_T_Display.h
    pinMode(TFT_BL, OUTPUT);                // Set backlight pin to output mode
    digitalWrite(TFT_BL, TFT_BACKLIGHT_ON); // Turn backlight on. TFT_BACKLIGHT_ON has been set in the TFT_eSPI library in the User Setup file TTGO_T_Display.h
  }
  tft.setSwapBytes(true);
  delay(100);
  tft.setRotation(0);
  int i = 3;
  while (i--)
  {
    tft.fillScreen(TFT_RED);
    delay(100);
    tft.fillScreen(TFT_BLUE);
    delay(100);
    tft.fillScreen(TFT_GREEN);
    delay(100);
  }

  tft.fillScreen(TFT_BLACK);

  tft.setRotation(1);

  tft.setTextDatum(MC_DATUM);
}

void loop()
{

    tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_BLUE, TFT_BLACK);
  tft.drawString("Marta Automaat", 10, 10, 4);

  delay(1000);
  tft.setTextColor(TFT_RED, TFT_BLACK);
  tft.drawString("Marta Automaat", 10, 10, 4);
  delay(1000);

  tft.fillRect(tft.width() - 55, 10, 20, 20, TFT_BLUE);
  delay(1000);
  tft.fillRect(tft.width() - 55, 30, 20, 20, TFT_RED);
  delay(1000);
  tft.drawCircle(tft.width() - 55, 30, 50, TFT_GREEN);
  delay(1000);

  tft.fillScreen(TFT_BLACK);
  delay(1000);

  tft.setTextColor(TFT_RED, TFT_BLACK);
  tft.drawString("Cookie1", 20, 80, 1);

  delay(1000);

  tft.setTextColor(TFT_RED, TFT_BLACK);
  tft.drawString("Cookie2", 20, 80, 2);

  delay(1000);

  tft.setTextColor(TFT_RED, TFT_BLACK);
  tft.drawString("Cookie4", 20, 60, 4);
  delay(1000);

  tft.setTextColor(TFT_GREENYELLOW, TFT_BLACK);
  tft.drawString("Cookie4", 20, 60, 4);
  delay(1000);

  tft.fillRect(25, 30, 80, 80, TFT_RED);

  //tft.drawString("JES", 10, 60, 6);
  delay(1000);
  tft.fillScreen(TFT_BLACK);

  tft.setTextColor(TFT_RED, TFT_BLACK);
  tft.drawString("EN NU ZELF ", 1, 10, 4);
  tft.drawString("PROGRAMMEREN", 1, 50, 4);
  tft.drawString("MET PETER JAN !!", 1, 90, 4);
  delay(5000);
}