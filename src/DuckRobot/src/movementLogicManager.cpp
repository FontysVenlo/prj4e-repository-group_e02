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

      //task for battery load detection

      int distance = 9999;
      //logic for steering...
      for(;;){
        int prevDist = distance;
        distance = getDistance();
        // so the motors dont go from 100% in one direction to 100% in the other direction immediatly
        if (prevDist < 30 && distance >= 30 || prevDist >= 30 && distance < 30){
          state = 3;
          delay(1000);
        }
        if (distance < 30){
          state = 2; //turn
        }else{
          state = 1;//move
        }
      }
      vTaskDelete(NULL);
  }
    
