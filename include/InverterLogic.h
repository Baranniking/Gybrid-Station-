#pragma once
#include <Arduino.h>
#include "Hardware.h"
#include <TFT_eSPI.h>


class InverterLogic {
public:
    enum StatusInverter {
          INVERTER_OFF,
          INVERTER_WAIT,
          INVERTER_GRID_TO_HOME,
          INVERTER_GRID_TO_BAT,
          INVERTER_BAT_TO_HOME,
          INVERTER_ALARM
      };
      enum prevStatus{};
void mode();

private:
StatusInverter inverterStatus = INVERTER_OFF;
StatusInverter prevStatus;
unsigned long delayStartSSR = 100;
unsigned long lastPointTimeSSR = 0;
unsigned long now = 0;

};
