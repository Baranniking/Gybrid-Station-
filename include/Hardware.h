#pragma once
#include <Arduino.h>

class Hardware {
public:
  void begin();
  void update();
  bool isGridOn() const { return gridOn; }

private:
  const uint8_t pinGridDetect = 27;
  bool gridOn = false;

};
