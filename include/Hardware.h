#pragma once
#include <Arduino.h>

class Hardware {
public:
  void begin();
  void update();

  const uint8_t pinGridDetect; //пин детектора напряжения 
  const uint8_t pinControlSSR; //пин включения сср реле
  const uint8_t pinOnOffInverter; //пин реле переключения сеть - дом - инвертор
  const uint8_t pinOnOffModuleCharger; //пин включения зарядной станции
 
  bool isGridOn() const { return gridOn; }
  

private:


  bool gridOn = false;

};
