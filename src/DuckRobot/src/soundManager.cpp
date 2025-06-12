#include <Arduino.h>
#include "soundManager.h"

#define RXD 19  // Define RX pin
#define TXD 23  // Define TX pin
#include <time.h>
#include <stdlib.h>

HardwareSerial mp3Serial(1);  // Use Serial1 for communication with MP3 module     So thats for the UART port (Its a communication protocll like I2C)

int playRandomSound();

void start(void * parameter){

    mp3Serial.begin(9600, SERIAL_8N1, RXD, TXD); //SERIAL_8N1 is the default frame: 8 bits no parity 1 stop

    //time for initialization
    delay(1000);
  
    // Set volume to 30 (0x1E is hex for 30)
    byte setVolume[] = { 0x7E, 0x03, 0x31, 0x1E, 0xEF };
    mp3Serial.write(setVolume, sizeof(setVolume));
    delay(200); // wait for it to work
    srand(time(NULL));   // Initialization, should only be called once.
  
    playRandomSound();
}

int playRandomSound(){
    for (;;)
    {
      int timeToWait = rand() % 20 + 20; //delay between the quacks
      delay(timeToWait * 1000);
  
      int r = rand() % 20 + 1;
      Serial.println(r);
  
      byte playCommand[] = { 0x7E, 0x04, 0x41, 0x00, 0x00, 0xEF };
      playCommand[4] = r; // Set the song index to play
      mp3Serial.write(playCommand, sizeof(playCommand));
    
      Serial.print("Playing mp3 file number: ");
      Serial.println(r);
      delay(200);
    }
  }
  