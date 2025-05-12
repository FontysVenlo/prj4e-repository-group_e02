#include <Arduino.h>
#include "movementManager.h"

const int motorPin1 = 12;  // white
const int motorPin2 = 14;

// Settings PWM
const int pwmChannel = 0;
const int pwmChannel2 = 1;
const int pwmFreq = 50;       
const int pwmResolution = 16; 
const int centerPulse = 4915; 
const int maxDelta = 820; 

void move();

void startMovementManager(void * parameter) {
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  
    // PWM
    ledcSetup(pwmChannel, pwmFreq, pwmResolution);
    ledcAttachPin(motorPin1, pwmChannel);
    ledcSetup(pwmChannel2, pwmFreq, pwmResolution);
    ledcAttachPin(motorPin2, pwmChannel2);
  
    Serial.println("Start test");
    for (;;) {
        vTaskDelay(500 / portTICK_PERIOD_MS);
        move(); 
    }
}  

void move() {
    // anti clock wise
    ledcWrite(pwmChannel, centerPulse + maxDelta);
    ledcWrite(pwmChannel2, centerPulse + maxDelta);
    Serial.println("Forward");
    vTaskDelay(3000 / portTICK_PERIOD_MS);

    // Stop
    ledcWrite(pwmChannel, centerPulse);
    ledcWrite(pwmChannel2, centerPulse);
    Serial.println("Stop");
    vTaskDelay(1000 / portTICK_PERIOD_MS);

    // clock wise
    ledcWrite(pwmChannel, centerPulse - maxDelta);
    ledcWrite(pwmChannel2, centerPulse - maxDelta);
    Serial.println("Back");
    vTaskDelay(1000 / portTICK_PERIOD_MS);

    // Stop
    ledcWrite(pwmChannel, centerPulse);
    ledcWrite(pwmChannel2, centerPulse);
    Serial.println("Stop");
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    
}
