#include "Hardware.h"

void Hardware::begin() {
  pinMode(pinGridDetect, INPUT_PULLUP);
  pinMode(pinControlSSR, OUTPUT);
  pinMode(pinOnOffInverter, OUTPUT);
  pinMode(pinOnOffModuleCharger, OUTPUT);
  
  digitalWrite(pinOnOffModuleCharger, LOW);
  digitalWrite(pinControlSSR, LOW);
  digitalWrite(pinOnOffInverter, LOW);
}

void Hardware::update() {
  // LOW — сеть есть (как в твоём коде)
  gridOn = (digitalRead(pinGridDetect) == LOW);
}
