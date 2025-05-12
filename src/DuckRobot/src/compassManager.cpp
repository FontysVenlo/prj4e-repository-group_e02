#include "compassManager.h"
#include <Wire.h>
#include <Arduino.h>

// TTGO T-Display I2C pins
#define SDA_PIN 21
#define SCL_PIN 22

#define DECLINATION 2.55  // magnetic declination for your location
#define CMPS2_ADDRESS 0x30

float X, Y;
float Max[2], Min[2], Mid[2];
bool calibrated = false;
unsigned long calibrationStart;

float getHeading();
void readMagnetometer();
void decodeHeading(float heading);
void updateCalibration();

void startCompass(void *parameter) {
  Wire.begin(SDA_PIN, SCL_PIN);

  pinMode(26, OUTPUT);
  digitalWrite(26, LOW);

  for (int i = 0; i < 2; i++) {
    Max[i] = -32768;
    Min[i] = 32767;
    Mid[i] = 0;
  }

  Serial.println("Compass task started. Calibrating for 5 seconds...");
  calibrationStart = millis();

  for (;;) {
    readMagnetometer();

    if (!calibrated) {
      if (millis() - calibrationStart < 5000) {
        updateCalibration();
        Serial.println("Calibrating...");
      } else {
        calibrated = true;
        Serial.println("Calibration complete.");
      }
    }

    float heading = getHeading();
    Serial.print("Heading = ");
    Serial.print(heading);
    Serial.print("°\t");
    decodeHeading(heading);

    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}

void readMagnetometer() {
  Wire.beginTransmission(CMPS2_ADDRESS);
  Wire.write(0x07);
  Wire.write(0x01);
  Wire.endTransmission();
  delay(8);

  bool ready = false;
  while (!ready) {
    Wire.beginTransmission(CMPS2_ADDRESS);
    Wire.write(0x06);
    Wire.endTransmission();

    delay(2);

    Wire.requestFrom(CMPS2_ADDRESS, (uint8_t)1);
    if (Wire.available() && (Wire.read() & 0x01)) {
      ready = true;
    }
  }

  Wire.beginTransmission(CMPS2_ADDRESS);
  Wire.write(0x00);
  Wire.endTransmission();
  Wire.requestFrom(CMPS2_ADDRESS, (uint8_t)6);
  

  byte buf[6];
  for (int i = 0; i < 6 && Wire.available(); i++) {
    buf[i] = Wire.read();
  }

  int16_t rawX = (int16_t)(buf[1] << 8 | buf[0]);
  int16_t rawY = (int16_t)(buf[3] << 8 | buf[2]);

  X = rawX * 0.48828125;
  Y = rawY * 0.48828125;
}

float getHeading() {
  float correctedX = X - Mid[0];
  float correctedY = Y - Mid[1];

  float heading = atan2(correctedY, correctedX) * (180.0 / PI);
  heading += DECLINATION;

  if (heading < 0) heading += 360;
  if (heading >= 360) heading -= 360;

  return heading;
}

void decodeHeading(float angle) {
  if (angle > 337.25 || angle < 22.5) {
    Serial.println("North");
    digitalWrite(26, HIGH);
  } else {
    digitalWrite(26, LOW);
    if (angle > 292.5) Serial.println("North-West");
    else if (angle > 247.5) Serial.println("West");
    else if (angle > 202.5) Serial.println("South-West");
    else if (angle > 157.5) Serial.println("South");
    else if (angle > 112.5) Serial.println("South-East");
    else if (angle > 67.5) Serial.println("East");
    else Serial.println("North-East");
  }
}

void updateCalibration() {
  for (int i = 0; i < 2; i++) {
    float val = (i == 0) ? X : Y;
    if (val > Max[i]) Max[i] = val;
    if (val < Min[i]) Min[i] = val;
    Mid[i] = (Max[i] + Min[i]) / 2.0;
  }
}
