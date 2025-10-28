#pragma once
#include <Arduino.h>

class Hardware {
public:
  void begin();
  void update();
  bool isGridOn() const { return gridOn; }

private:
  const uint8_t pinGridDetect = 27; //пин детектора напряжения 
  const uint8_t pinControlSSR = 26; //пин включения сср реле
  const u_int8_t pinOnOffInverter = 25; //пин реле переключения сеть - дом - инвертор

  bool gridOn = false;

};
