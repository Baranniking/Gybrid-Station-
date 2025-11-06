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

uint8_t iconHomeX = 256;
uint8_t iconHomeY = 100;
uint8_t iconGridX = 128;
uint8_t iconGridY = 10;
uint8_t iconW = 64;
uint8_t iconH = 64;
uint8_t iconBattX = 0;
uint8_t iconBattY = 100;

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
hw.update(); // обновление статуса сети
inverter.mode(); // режими инвертора 
ui.statusAC(hw.isGridOn()); //визиуальный статус внешней сети
inverter.InfoChargMode(); //управление зарядкой

if(touch.detectTouch()){
  TouchPoint p = touch.getLastTouch();
  if(p.x >= iconGridX && p.x <= (iconGridX + iconW) && //если было нажатие на кнопку "сеть"
     p.y >= iconGridY && p.y <= (iconGridY + iconH)){
      if(!modeWait && hw.isGridOn()){
      inverter.setStatus(InverterLogic::INVERTER_WAIT);
        tft.drawBitmap(128, 10, grid_icon, 64, 64, TFT_GREEN);
        modeWait = true;
      }
      else{
        inverter.setStatus(InverterLogic::INVERTER_OFF)
        tft.drawBitmap(128, 10, grid_icon, 64, 64, TFT_RED);
        modeWait = false;

      }
     }
     else if(p.x >= iconHomeX && p.x <= (iconHomeX + iconW) && //если было нажатие на кнопку "дом"
     p.y >= iconHomeY && p.y <= (iconHomeY + iconH)){
      if(madeWait && hw.isGridOn(){
      inverter.setStatus(InverterLogic::INVERTER_GRID_TO_HOME);
      ui.flowACtoHome(TFT_BLUE, TFT_RED, 100);
        modeGridToHome = true;
      }
      else {
        inverter.setStatus(InverterLogic::INVERTER_BAT_TO_HOME);
        ui.flowBatToHome(TFT_BLUE, TFT_RED, 100);
        modeBatToHome = true;
      }
     }
     else if(p.x >= iconBattX && p.x <= (iconBattX + iconW) && //если было нажатие на кнопку "батарея"
     p.y >= iconBattY && p.x <= (iconBattY + iconH)){
      if(!modeGridToBat && hw.isGridOn()){
        modeGridToBat = true;
      }
      else {
        ui.cleanFlowACtoBat();
        modeGridToBat = false;

      }
     }
  }



}
