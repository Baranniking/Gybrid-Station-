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
hw.update();
ui.statusAC(hw.isGridOn());

ui.flowACtoBat(TFT_BLUE, TFT_RED, 100);
ui.flowACtoHome(TFT_BLUE, TFT_RED, 100);
ui.flowBatToHome(TFT_BLUE, TFT_GREEN, 100);

}
