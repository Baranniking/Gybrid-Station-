#pragma once
#include <Arduino.h>
#include <TFT_eSPI.h>

class DisplayUI {
public:
  //инициализация и отрисовка меню
  void begin();
  void drawMainMenu(uint16_t colorAC, uint16_t colorBat, uint16_t colorHome);
  void statusAC(bool gridOn);
  // анимации и очистка
  void flowACtoBat(uint16_t colo1, uint16_t color2, int speed);
  void flowACtoHome(uint16_t color1, uint16_t color2, int speed);
  void flowBatToHome(uint16_t color1, uint16_t color2,  int speed);

  void cleanFlowACtoBat();
  void cleanFlowACtoHome();
  void cleanFlowBatToHome();

  
private:
  TFT_eSPI tft;
  uint16_t menuColor = TFT_BLACK;

  // анимационные переменные (как у тебя)
  unsigned long lastFlowTimeACBat = 0;
  unsigned long lastFlowTimeACHome = 0;
  unsigned long lastFlowTimeBatHome = 0;

  int flowHeight = 0;
  int flowWeight = 0;
  int flowHeightToHome = 0;
  int flowWeightToHome = 0;
  int flowHeightBatToHome = 0;

  bool flowBatToHomeEnd = false;
  bool flowActoBatEnd = false;
  bool flowACtoHomeEnd = false;
};
