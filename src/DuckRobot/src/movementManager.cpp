#include <Arduino.h>
#include "movementManager.h"
#include "distanceSensorManager.h"

void startMovement(void * parameter){
    xTaskCreate(
        startDistanceSensor, // Function that should be called
        "distanceSensor", // Name of the task (for debugging)
        2000, // Stack size (bytes)
        NULL, // Parameter to pass
        1, // Task priority
        NULL // Task handle
      );

    for(;;){
        Serial.println(getDistance());
        delay(500);
    }
}