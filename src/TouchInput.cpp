#include "TouchInput.h"
#include <XPT2046_Touchscreen.h>

TouchInput::TouchInput(uint8_t csPin) : ts(csPin) {}

// Реализация скрытого класса Impl
void TouchInput::begin() {
ts.begin();
ts.setRotation(1);
}

//проверка было ли косание
bool TouchInput::detectTouch(){
if(!ts.touched()) return false;
TS_Point p = ts.getPoint();
 if (p.z > 200) {
    lastTouch.x = map(p.x, 3600, 500, 0, 320);
    lastTouch.y = map(p.y, 3500, 500, 0, 240);
    lastTouch.z = p.z;
    now  = millis();
    if(now - lastTouchTime < debounceDelay) return false;
    lastTouchTime = now;
    return true;
}
return false;
}

TouchPoint TouchInput::getLastTouch() const {
  return lastTouch;
}


