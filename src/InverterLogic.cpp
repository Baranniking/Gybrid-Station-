#include "InverterLogic.h"

void InverterLogic::begin() {
  acOn = false;
  homeMode = 0;
  batFlow = false;
}

void InverterLogic::update(const Hardware &hw) {
  // Если сеть пропала — делаем сброс
  if (!hw.isGridOn()) {
    acOn = false;
    homeMode = 0;
    batFlow = false;
  }
  // здесь можно добавить дополнительные проверки и переходы
}
