#include <Arduino.h>
#include "movementManager.h"
#include "distanceSensorManager.h"

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

void start() {
    Serial.begin(115200);
    delay(1000);
  
    // PWM
    ledcSetup(pwmChannel, pwmFreq, pwmResolution);
    ledcAttachPin(motorPin1, pwmChannel);
    ledcSetup(pwmChannel2, pwmFreq, pwmResolution);
    ledcAttachPin(motorPin2, pwmChannel2);
  
    Serial.println("Start test");
  }  

void startMovement(void * parameter){
    start();
    xTaskCreate(
        startDistanceSensor, // Function that should be called
        "distanceSensor", // Name of the task (for debugging)
        4096, // Stack size (bytes)
        NULL, // Parameter to pass
        1, // Task priority
        NULL // Task handle
      );

    for(;;){
        // Serial.println(getDistance());
        delay(500);
        move();
    }
}
   

void move() {
        // anti clock wise
        ledcWrite(pwmChannel, centerPulse + maxDelta);
        ledcWrite(pwmChannel2, centerPulse + maxDelta);
        Serial.println("Forward");
        delay(3000);

        // Stop
        ledcWrite(pwmChannel, centerPulse);
        ledcWrite(pwmChannel2, centerPulse);
        Serial.println("Stop");
        Serial.println(getDistance());
        delay(1000);

        // clock wise
        ledcWrite(pwmChannel, centerPulse - maxDelta);
        ledcWrite(pwmChannel2, centerPulse - maxDelta);
        Serial.println("Back");
        delay(3000);

        // Stop
        ledcWrite(pwmChannel, centerPulse);
        ledcWrite(pwmChannel2, centerPulse);
        Serial.println("Stop");
        Serial.println(getDistance());
        delay(1000);
}
