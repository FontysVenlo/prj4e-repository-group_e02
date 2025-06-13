#include <Arduino.h>
#include "movementLogicManager.h"
#include "distanceSensorManager.h"
#include "movementManager.h"
#include "adcManager.h"

#define VOLTAGE_LIMIT 3000
#define DETECTION_ZONE 40

bool lowBatteryMode = false;
bool obstacleFound = false;

void normalMovement(int distance, int prevDist);
bool checkLowBattery();
void lowBatteryMovement(int distance);

void startMovement(void *parameter) {
  xTaskCreate(
      startMovementManager, // Function that should be called
      "movementManager",    // Name of the task (for debugging)
      4096,                // Stack size (bytes)
      NULL,                 // Parameter to pass
      1,                    // Task priority
      NULL                  // Task handle
  );

  xTaskCreate(
      startDistanceSensor, // Function that should be called
      "distanceSensor",    // Name of the task (for debugging)
      4096,                // Stack size (bytes)
      NULL,                // Parameter to pass
      1,                   // Task priority
      NULL                 // Task handle
  );

  // task for battery load detection
  xTaskCreate(
      startAdcManager, // Task function
      "adcTask",       // Name
      2048,            // Stack size
      NULL,            // Paramater to pass
      1,               // Priority
      NULL             // Task handle
  );

  int distance = 9999;

  // Main loop
  for (;;) {
    if (checkLowBattery())
    {
      lowBatteryMode = true;
    }

    int prevDist = distance;
    distance = getDistance();

    if (lowBatteryMode)
    {
      lowBatteryMovement(distance);
    } else {
      normalMovement(distance, prevDist);
    }
  }
}

bool checkLowBattery() {
  int batteryLevel = getBatteryLevel();
  return (batteryLevel < VOLTAGE_LIMIT);
}

void normalMovement(int distance, int prevDist) {
  // Smooth transition to prevent immediate direction changes
  if ((prevDist < DETECTION_ZONE && distance >= DETECTION_ZONE) || (prevDist >= DETECTION_ZONE && distance < DETECTION_ZONE))
  {
    state = 3; //stop
    delay(350);
  }

  if (distance < DETECTION_ZONE)
  {
    state = 2; // Turn
    delay(500);
  }
  else
  {
    state = 1; // Move forward
  }
}

void lowBatteryMovement(int distance) {
  if (!obstacleFound && distance < DETECTION_ZONE)
  {
    obstacleFound = true; // Mark obstacle as found
  }

  if (obstacleFound)
  {
    state = 3;
  }
}
