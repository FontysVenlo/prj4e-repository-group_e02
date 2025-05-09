#include <Arduino.h>

const int motorPin1 = 26;  // white
const int motorPin2 = 23;

// Settings PWM
const int pwmChannel = 0;
const int pwmChannel2 = 1;
const int pwmFreq = 50;       
const int pwmResolution = 16; 
const int centerPulse = 4915; 
const int maxDelta = 820;     

void setup() {
  Serial.begin(115200);
  delay(1000);

  // PWM
  ledcSetup(pwmChannel, pwmFreq, pwmResolution);
  ledcAttachPin(motorPin1, pwmChannel);
  ledcSetup(pwmChannel2, pwmFreq, pwmResolution);
  ledcAttachPin(motorPin2, pwmChannel2);

  Serial.println("Start test");
}

void loop() {
  // anti clock wise
  ledcWrite(pwmChannel, centerPulse + maxDelta);
  ledcWrite(pwmChannel2, centerPulse + maxDelta);
  Serial.println("Forward");
  delay(3000);

  // Stop
  ledcWrite(pwmChannel, centerPulse);
  ledcWrite(pwmChannel2, centerPulse);
  Serial.println("Stop");
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
  delay(1000);
}
