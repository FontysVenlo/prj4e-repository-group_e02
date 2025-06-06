
#include <Arduino.h>
#include "soundManager.h"
#include "movementLogicManager.h"
#include "compassManager.h"
  #include "pwmEyesManager.h"

#define LED 25

void heartbeat(void * parameter);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED, OUTPUT);

  //hearthbeat thread
  xTaskCreate(
    heartbeat, // Function that should be called
    "heartbeat", // Name of the task (for debugging)
    4096, // Stack size (bytes)
    (void *) LED, // Parameter to pass
    1, // Task priority
    NULL // Task handle
  );
  //soundManager thread
  xTaskCreate(
    start, // Function that should be called
    "soundTask", // Name of the task (for debugging)
    4096, // Stack size (bytes)
    NULL, // Parameter to pass
    1, // Task priority
    NULL // Task handle
  );
  

  //movementLogicManager thread
  xTaskCreate(
    startMovement, // Function that should be called
    "movementTask", // Name of the task (for debugging)
    4096, // Stack size (bytes)
    NULL, // Parameter to pass
    1, // Task priority
    NULL // Task handle
  );

  //compassManager thread 
  xTaskCreate(
    startCompass,     // Function that should be called
    "compassTask",    // Name of the task
    4096,             // Stack size (bytes)
    NULL,             // Parameter
    1,                // Task priority
    NULL              // Task handle
  );

  xTaskCreate(
    setupPWM, // Function that should be called
    "pwmEyes", // Name of the task (for debugging)
    4096, // Stack size (bytes)
    NULL, // Parameter to pass
    1, // Task priority
    NULL // Task handle
  );
  
  //threads to be added...
}

void loop() {

}


void heartbeat(void * parameter){
  // use internal (onboard) led as heartbeat monitor
  int led;
  led = (int) parameter;
  for(;;){ // infinite loop
  // Turn the LED on
  digitalWrite(led, HIGH);
  // Pause the task for 500ms
  vTaskDelay(500 / portTICK_PERIOD_MS);
  // Turn the LED off
  digitalWrite(led, LOW);
  // Pause the task again for 500ms
  vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}