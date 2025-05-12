  #include <Arduino.h>
  #include "movementLogicManager.h"
  #include "distanceSensorManager.h"
  #include "movementManager.h"

  void startMovement(void * parameter){

    xTaskCreate(
        startMovementManager, // Function that should be called
        "movementManager", // Name of the task (for debugging)
        4096, // Stack size (bytes)
        NULL, // Parameter to pass
        1, // Task priority
        NULL // Task handle
      );

      xTaskCreate(
          startDistanceSensor, // Function that should be called
          "distanceSensor", // Name of the task (for debugging)
          4096, // Stack size (bytes)
          NULL, // Parameter to pass
          1, // Task priority
          NULL // Task handle
      );

      vTaskDelete(NULL);
  }
    
