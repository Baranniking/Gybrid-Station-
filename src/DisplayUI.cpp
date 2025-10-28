#include "DisplayUI.h"
#include "grid_icon.h"
#include "house_icon.h"
#include "bat_icon.h"

//класс дисплей, метод инициализации
void DisplayUI::begin() {
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
}

//класс дисплей, метод отрисовки статус сети
void DisplayUI::statusAC(bool gridOn){
  
tft.fillRect(290, 10, 15, 15, gridOn ? TFT_GREEN : TFT_RED);

}

//класс дисплей, метод отрисовки главного меню
void DisplayUI::drawMainMenu(uint16_t colorAC, uint16_t colorBat, uint16_t colorHome) {
  tft.fillScreen(TFT_BLACK);

  tft.drawBitmap(128, 10, grid_icon, 64, 64, colorAC);
  tft.drawBitmap(256, 100, house_icon, 64, 64, colorHome);
  tft.drawBitmap(0, 100, bat_icon, 64, 64, colorBat);

  tft.setTextSize(2);
  tft.setTextColor(colorAC, TFT_BLACK);
  tft.setCursor(115, 10);
  tft.println("AC");

  tft.setTextColor(colorHome, TFT_BLACK);
  tft.setCursor(230, 90);
  tft.println("Home");

  tft.setTextColor(colorBat, TFT_BLACK);
  tft.setCursor(55, 90);
  tft.println("Bat");

  tft.setTextColor(TFT_WHITE, menuColor);
  tft.setTextSize(3);
  tft.setCursor(130, 200);
  tft.println("Menu");

}

// клас дисплей метод анимации перетока от сети к батареии
void DisplayUI::flowACtoBat(uint16_t color1, uint16_t color2, int speed) {
  unsigned long currentMillis = millis();
  if (currentMillis - lastFlowTimeACBat >= speed) {
    lastFlowTimeACBat = currentMillis;
    if (flowHeight <= (120 - 32) && !flowActoBatEnd) {
      tft.fillRect(120 - flowHeight, 32, 2, 2, color1);
      flowHeight += 6;
    } else if (flowWeight <= 50 && !flowActoBatEnd) {
      tft.fillRect(30, 32 + flowWeight, 2, 2, color1);
      flowWeight += 6;
    } else if (flowWeight >= 50 && !flowActoBatEnd) {
      flowHeight = 0;
      flowWeight = 0;
      flowActoBatEnd = true;
    } else if (flowHeight <= (120 - 32) && flowActoBatEnd) {
      tft.fillRect(120 - flowHeight, 32, 2, 2, color2);
      flowHeight += 6;
    } else if (flowWeight <= 50 && flowActoBatEnd) {
      tft.fillRect(30, 32 + flowWeight, 2, 2, color2);
      flowWeight += 6;
    } else {
      flowHeight = 0;
      flowWeight = 0;
      flowActoBatEnd = false;
    }
  }
}

// класс дисплей, метод анимация перетока от сети к дому
void DisplayUI::flowACtoHome(uint16_t color1, uint16_t color2, int speed) {
unsigned long currentMillis = millis();
  if (currentMillis - lastFlowTimeACHome >= speed) {
    lastFlowTimeACHome = currentMillis;

    if (flowHeightToHome <= 90 && !flowACtoHomeEnd) {
      tft.fillRect(196 + flowHeightToHome, 32, 2, 2, color1);
      flowHeightToHome += 6;
    } else if (flowWeightToHome <= 50 && !flowACtoHomeEnd) {
      tft.fillRect(286, 32 + flowWeightToHome, 2, 2, color1);
      flowWeightToHome += 6;
    } else if (flowWeightToHome >= 50 && !flowACtoHomeEnd) {
      flowHeightToHome = 0;
      flowWeightToHome = 0;
      flowACtoHomeEnd = true;
    } else if (flowHeightToHome <= 90 && flowACtoHomeEnd) {
      tft.fillRect(196 + flowHeightToHome, 32, 2, 2, color2);
      flowHeightToHome += 6;
    } else if (flowWeightToHome <= 50 && flowACtoHomeEnd) {
      tft.fillRect(286, 32 + flowWeightToHome, 2, 2, color2);
      flowWeightToHome += 6;
    } else {
      flowACtoHomeEnd = false;
      flowHeightToHome = 0;
      flowWeightToHome = 0;
    }
  }
}

// клас дисплея, метод анимации перетока от акб к дому
void DisplayUI::flowBatToHome(uint16_t color1, uint16_t color2, int speed) {
 unsigned long currentMillis = millis();
  if (currentMillis - lastFlowTimeBatHome >= speed) {
    lastFlowTimeBatHome = currentMillis;

    if (flowHeightBatToHome <= 182 && !flowBatToHomeEnd) {
      tft.fillRect(64 + flowHeightBatToHome, 128, 2, 2, color1);
      flowHeightBatToHome += 6;
    } else if (flowHeightBatToHome >= 182 && !flowBatToHomeEnd) {
      flowBatToHomeEnd = true;
      flowHeightBatToHome = 0;
    } else if (flowHeightBatToHome <= 182 && flowBatToHomeEnd) {
      tft.fillRect(64 + flowHeightBatToHome, 128, 2, 2, color2);
      flowHeightBatToHome += 6;
    } else {
      flowBatToHomeEnd = false;
      flowHeightBatToHome = 0;
    }
  }
}


//метод очистки перетока от сети к батареии
void DisplayUI::cleanFlowACtoBat() {
  tft.fillRect(30, 32, 98, 52, TFT_BLACK);
  flowHeight = 0;
  flowWeight = 0;
}

//метод очистки перетока от сети к дому
void DisplayUI::cleanFlowACtoHome() {
  tft.fillRect(196, 32, 90, 52, TFT_BLACK);
  flowHeightToHome = 0;
  flowWeightToHome = 0;
}

//метод очистки перетока от батареи к дому
void DisplayUI::cleanFlowBatToHome() {
  tft.fillRect(64, 128, 182, 2, TFT_BLACK);
  flowHeightBatToHome = 0;
}
