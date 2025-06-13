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
#define maxSpeed 205 // 820 max speed

int delta = 40; //to understand why 20 pls look at the datasheet average rotational velocity graph
volatile int state = 0;

void handleState();
void move();
void stop();
void turn();

void startMovementManager(void * parameter) {
    // PWM
    ledcSetup(pwmChannel, pwmFreq, pwmResolution);
    ledcAttachPin(motorPin1, pwmChannel);
    ledcSetup(pwmChannel2, pwmFreq, pwmResolution);
    ledcAttachPin(motorPin2, pwmChannel2);
  
    vTaskDelay(2000 / portTICK_PERIOD_MS);
    // Serial.println("Start motors");
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
    ledcWrite(pwmChannel2, centerPulse + delta);
    //clock wise
    ledcWrite(pwmChannel, centerPulse - delta);
    // Serial.println("Forward start");
    
    if (delta < maxSpeed)
    {
        delta += 2;
    }
    vTaskDelay(20); 
}

void turn(){
    ledcWrite(pwmChannel, centerPulse + maxSpeed);
    ledcWrite(pwmChannel2, centerPulse + maxSpeed);
    // Serial.println("Forward");
    vTaskDelay(20);
}

void stop(){
    delta = 40; //to understand why 20 pls look at the datasheet average rotational velocity graph
    ledcWrite(pwmChannel, centerPulse);
    ledcWrite(pwmChannel2, centerPulse);
    // Serial.println("Stop");
    vTaskDelay(20);
}

//should maye use vTaskDelay(1) when able to test out
