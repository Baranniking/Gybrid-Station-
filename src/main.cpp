#include <Arduino.h>
#include "Hardware.h"
#include "DisplayUI.h"
#include "TouchInput.h"
#include "InverterLogic.h"
#include "grid_icon.h"
#include "house_icon.h"
#include "bat_icon.h"

// CS пин для тача
#define TOUCH_CS 33

// объекты
Hardware hw;
DisplayUI ui;
TouchInput touch(TOUCH_CS);
InverterLogic inverter;

uint8_t iconHomeX = 0;
uint8_t iconHomeY = 0;
uint8_t iconGridX = 128;
uint8_t iconGridY = 10;
uint8_t iconW = 64;
uint8_t iconH = 64;
uint8_t iconBattX = 0;
uint8_t iconBattY = 0;

void setup() {
  Serial.begin(115200);

  // init modules
  hw.begin();
  ui.begin();
  touch.begin();
  inverter.begin();

  // первичная отрисовка
  ui.drawMainMenu(inverter.getACColor(), inverter.getBatColor(), inverter.getHomeColor());
}

void loop() {
inverter.mode();
hw.update();
ui.statusAC(hw.isGridOn());
if(touch.detectTouch()){
  TouchPoint p = touch.getLastTouch();
  if(p.x >= iconGridX && p.x <= (iconGridX + iconW) && //если было нажатие на кнопку "сеть"
     p.y >= iconGridY && p.y <= (iconGridY + iconH)){
      inverter.setStatus(InverterLogic::INVERTER_WAIT));
     }
  }


ui.flowACtoBat(TFT_BLUE, TFT_RED, 100);
ui.flowACtoHome(TFT_BLUE, TFT_RED, 100);
ui.flowBatToHome(TFT_BLUE, TFT_GREEN, 100);

}
