#include <Arduino.h>
#include "adcManager.h"

#define potPin 34

volatile int currentBatteryLevel = 4095; // max starting value

void startAdcManager(void * parameter){
    pinMode(potPin, INPUT);
    
    for(;;){
        int potValue = analogRead(potPin);
        currentBatteryLevel = potValue;
        
        Serial.print("ADC value: ");
        Serial.println(potValue);
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }

    vTaskDelete(NULL);
}

int getBatteryLevel(){
    return currentBatteryLevel;
}