#include "Hardware.h"

void Hardware::begin() {
  pinMode(pinGridDetect, INPUT_PULLUP);
}

void Hardware::update() {
  // LOW — сеть есть (как в твоём коде)
  gridOn = (digitalRead(pinGridDetect) == LOW);
}
