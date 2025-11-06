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
          INVERTER_BAT_TO_HOME,
          INVERTER_ALARM
      };
void handleGridToBatOn();
void handleGridToBatOff();
void InfoChargMode();
void mode();
void setStatus(StatusInverter newStatus){
    inverterStatus  = newStatus;
    StatusInverter getStatus()const{
        return inverterStatus;
    }
    bool modeWait = false;
    bool modeBatToHome = false;
    bool modeGridToHome = false;
    bool modeGridToBat = false;
}
private:
StatusInverter inverterStatus = INVERTER_OFF;
StatusInverter prevStatus = INVERTER_OFF;
unsigned long delayStartSSR = 100;
unsigned long lastPointTimeSSR = 0;
unsigned long now = 0;

};
