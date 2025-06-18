#include <Arduino.h>
#include "pwmEyesManager.h"

#define freq 5000
#define resolution 8
#define ledChannel0  2

#define ledPin0 2  

void startPWM();

void setupPWM(void * parameter){
  ledcSetup(ledChannel0, freq, resolution);
  ledcAttachPin(ledPin0, ledChannel0);
  startPWM();
}

void startPWM() {
  int brightness = 0;
  int fadeAmount = 5;

  while (true) {
    // Update both LEDs
    ledcWrite(ledChannel0, brightness);

    // Update brightness
    brightness += fadeAmount;

    // Reverse direction at bounds
    if (brightness <= 0 || brightness >= 255) {
      fadeAmount = -fadeAmount;
    }

    vTaskDelay(30 / portTICK_PERIOD_MS); 
  }
}