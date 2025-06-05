#include <Arduino.h>
#include "pwmEyesManager.h"

const int freq = 5000;
const int resolution = 8;
const int ledChannel0 = 0;

const int ledPin0 = 4;   //THEY NEED TO BE CHANGED


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