#include "InverterLogic.h"



void InverterLogic::mode(){
 now = millis();

 if(inverterStatus != prevStatus){
    Serial.print("Переход в режим: ");
    Serial.println(inverterStatus);

    lastPointTimeSSR = now;
    prevStatus = inverterStatus;
 
 }

switch (inverterStatus){
  case INVERTER_OFF: handleOff(); break;
  case INVERTER_WAIT: handleWait(); break;
  case INVERTER_GRID_TO_HOME: handleGridToHome(); break;
  case INVERTER_GRID_TO_BAT: handleGridToBat(); break;
  case INVERTER_BAT_TO_HOME: handleBatToHome(); break;
  case INVERTER_ALARM: handleALARM(); break;
}
}

 void InverterLogic::handleOff(){
 }

 void InverterLogic::handleWait(){
  digitalWrite(pinControlSSR, LOW);
  digitalWrite(pinOnOffModuleCharger, LOW);
  digitalWrite(pinOnOffInverter, LOW);
 }


 void InverterLogic::handleGridToHome(){
  //логика включения инвертора от сети в дом (включает сср в дом)
    if(digitalRead(pinControlSSR) == HIGH){
      digitalWrite(pinControlSSR, LOW);
      delay(10);
    }
      digitalWrite(pinOnOffInverter, LOW);
  if(now - lastPointTimeSSR > delayStartSSR){
    digitalWrite(pinControlSSR, HIGH);
    
   Serial.println("Режим GRID->HOME активен");
  }
  }

  void InverterLogic::handleGridToBat(){
    //логика включения режима зарядки
   if(digitalRead(pinOnOffInverter) == LOW){
    digitalWrite(pinOnOffModuleCharger, HIGH);
    Serial.println("Режим сеть - BAT активен");

   }
  }

   void InverterLogic::handleBatToHome(){
    //логика включения инвертора в сеть
    if(digitalRead(pinControlSSR) == HIGH)){
      digitalWrite(pinControlSSR, LOW);
      delay(10);
    }
    digitalWrite(pinOnOffInverter, HIGH);
    if(now - lastPointTimeSSR > delayStartSSR){
    digitalWrite(pinControlSSR, HIGH);
    Serial.println("Режим BAT->HOME активен");
    

   }

  }
  

  
