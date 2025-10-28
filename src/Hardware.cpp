#include "Hardware.h"

void Hardware::begin() {
  pinMode(pinGridDetect, INPUT_PULLUP);
  pinMode(pinControlSSR, OUTPUT);
  pinMode(pinOnOffInverter, OUTPUT);
  pinControlSSR = LOW;
  pinOnOffInverter = LOW;
}

void Hardware::update() {
  // LOW — сеть есть (как в твоём коде)
  gridOn = (digitalRead(pinGridDetect) == LOW);
}
