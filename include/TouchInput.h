#pragma once
#include <Arduino.h>
#include <XPT2046_Touchscreen.h>


struct TouchPoint {
  int x;
  int y;
  int z;
};

class TouchInput {
public:
  TouchInput(uint8_t csPin);     // Конструктор
  void begin();
  TouchPoint getLastTouch() const;
  bool detectTouch();



private:
  XPT2046_Touchscreen ts;        // Объект тачскрина
  TouchPoint lastTouch;
  const unsigned long debounceDelay = 250;
  unsigned long lastTouchTime = 0;
  unsigned long now = 0;
  };
