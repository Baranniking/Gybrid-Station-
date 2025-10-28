#include "InverterLogic.h"



void InverterLogic::mode(){
  now = millis();

switch (inverterStatus){
  case INVERTER_OFF:
  //логика отключение инвертора (выключает есп)

  break;

  case (INVERTER_WAIT):
  //логика работы инвертора в режиме ожидания (включает есп, мониторит батарею, сеть, но ничего пока не включает)
  digitalWrite(pinControlSSR, LOW);
  digitalWrite(pinOnOffInverter, LOW);
  break;

  case (INVERTER_GRID_TO_HOME):
  //логика работы инвертора от сети в дом (включает сср в дом)
  if(digitalRead(pinControlSSR) == LOW){ //если выход к нагрузке выключен
  digitalWrite(pinOnOffInverter, LOW); //переключаем реле в состояие сеть - дом
   if(now - lastPointTimeSSR > delayStartSSR){ // ждем время
  digitalWrite(pinControlSSR, HIGH); // включаем сср на нагрузку 
  lastPointTimeSSR = now;
  }
  }
  break;

  case (INVERTER_GRID_TO_BAT):
  //логика работы инвертора зарядки батареи от сети (включает бп)
  digitalWrite(pinControlSSR, LOW);
  digitalWrite(pinOnOffInverter, LOW);

    break; 

  case (INVERTER_BAT_TO_HOME):
  //логика работы инвертора от батареи в сеть (отключает сеть, включает инвертор, и сср в дом)
  break;

  case (INVERTER_ALARM):
  //логика работы инверора в случае ошибки (ошикба на дисплее, все отключает)
  break;
}
}