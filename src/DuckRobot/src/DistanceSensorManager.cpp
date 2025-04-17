#include <Arduino.h>
#include "DistanceSensorManager.h"
#include <Wire.h>

#define trigger 13
#define echo 15

float distance = -1;

void startDistanceSensor(void * parameter){
    pinMode(trigger, OUTPUT);
    pinMode(echo, INPUT);

    for(;;){
        long duration;

        digitalWrite(trigger, LOW);
        delayMicroseconds(2);

        digitalWrite(trigger, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigger, LOW);

        duration = pulseIn(echo, HIGH);
        distance = duration * 0.034 / 2;
        delay(500); // half a second
    }
}

float getDistance(){
    return distance;
}