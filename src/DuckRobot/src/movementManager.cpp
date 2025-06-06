#include <Arduino.h>
#include "movementManager.h"

#define motorPin1 12  // white
#define motorPin2 14

// Settings PWM
#define pwmChannel 0
#define pwmChannel2 1
#define pwmFreq 50       
#define pwmResolution 16
#define centerPulse 4915
#define maxDelta 820

int state = 0;

void move();
void handleState();
void stop();
void turn();

void startMovementManager(void * parameter) {
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  
    // PWM
    ledcSetup(pwmChannel, pwmFreq, pwmResolution);
    ledcAttachPin(motorPin1, pwmChannel);
    ledcSetup(pwmChannel2, pwmFreq, pwmResolution);
    ledcAttachPin(motorPin2, pwmChannel2);
  
    Serial.println("Start motors");
    handleState();
}  

void handleState(){
    for (;;) {
        if (state == 1){
            move();
        }else if(state == 2){
            turn();
        }else if(state == 3){
            stop();
        }
    }
}

void move() {
    // anti clock wise
    ledcWrite(pwmChannel, centerPulse + maxDelta);
    //clock wise
    ledcWrite(pwmChannel2, centerPulse - maxDelta);
    Serial.println("Forward");
    vTaskDelay(500 / portTICK_PERIOD_MS);
}

void turn(){
    ledcWrite(pwmChannel, centerPulse + maxDelta);
    ledcWrite(pwmChannel2, centerPulse + maxDelta);
    Serial.println("Forward");
    vTaskDelay(500 / portTICK_PERIOD_MS);
}

void stop(){
    ledcWrite(pwmChannel, centerPulse);
    ledcWrite(pwmChannel2, centerPulse);
    Serial.println("Stop");
    vTaskDelay(500 / portTICK_PERIOD_MS);
}

//should maye use vTaskDelay(1) when able to test out
