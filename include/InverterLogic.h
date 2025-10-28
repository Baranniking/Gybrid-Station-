#pragma once
#include <Arduino.h>
#include "Hardware.h"
#include <TFT_eSPI.h>


class InverterLogic {
private:
  bool acOn = false;
  uint8_t homeMode = 0; // 0..2
  bool batFlow = false;

public:
  void begin();
  void update(const Hardware &hw);

  void toggleAC() { acOn = !acOn; }
  void cycleHomeMode() { homeMode = (homeMode + 1) % 3; }
  void toggleBatFlow() { batFlow = !batFlow; }

  // getters для UI
  bool isACOn() const { return acOn; }
  uint16_t getACColor() const { return acOn ? TFT_BLUE : TFT_RED; }
  uint16_t getBatColor() const { return TFT_GREEN; }
  uint16_t getHomeColor() const { return TFT_GOLD; }

  // состояния потоков (для вызова анимаций)
  bool isFlowACtoBat() const { return (acOn && homeMode == 2); }
  bool isFlowACtoHome() const { return (acOn && homeMode == 1); }
  bool isFlowBatToHome() const { return batFlow; }

  // скорости и цвета анимаций
  int acToBatSpeed() const { return 80; }
  int acToHomeSpeed() const { return 60; }
  int batToHomeSpeed() const { return 38; }

  uint16_t acFlowColor() const { return TFT_RED; }
  uint16_t batFlowColor() const { return TFT_GREEN; }
};
