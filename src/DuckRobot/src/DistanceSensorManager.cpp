#include <Arduino.h>
#include "distanceSensorManager.h"
#include <Wire.h>

#define trigger 13
#define echo 15

float distance = 9999;

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
        delay(100); // half a second
        Serial.print("Distance: ");
        Serial.println(distance);
    }
}

float getDistance(){
    return distance;
}