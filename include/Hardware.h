#pragma once
#include <Arduino.h>

class Hardware {
public:
  Hardware(
       uint8_t pinGridDetect, //пин детектора напряжения 
       uint8_t pinControlSSR, //пин включения сср реле
       uint8_t pinOnOffInverter, //пин реле переключения сеть - дом - инвертор
       uint8_t pinOnOffModuleCharger //пин включения зарядной станции
  ):  pinGridDetect(pinGridDetect),
      pinControlSSR(pinControlSSR),
      pinOnOffInverter(pinOnOffInverter),
      pinOnOffModuleCharger(pinOnOffModuleCharger){}

  void begin();
  void update();

  // Пины теперь доступны только для чтения (const)
  const uint8_t pinGridDetect; //пин детектора напряжения 
  const uint8_t pinControlSSR; //пин включения сср реле
  const uint8_t pinOnOffInverter; //пин реле переключения сеть - дом - инвертор
  const uint8_t pinOnOffModuleCharger; //пин включения зарядной станции
 
  bool isGridOn() const { return gridOn; }
  

private:


  bool gridOn = false;

};
