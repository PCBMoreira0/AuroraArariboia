#include <Arduino.h>
#include <ESP32Servo.h>
#include <LoRa.h>
#include <DabbleESP32.h>

const int escPinL = GPIO_NUM_13;
const int escPinR = GPIO_NUM_14;

Servo escL = Servo();
Servo escR = Servo();

unsigned long signalTimeoutLastMeasure = millis();
unsigned long signalTimeout = 3000;

uint8_t rL = 0;
uint8_t rR = 0;

uint8_t deviceTxID = 0xFA;

void setup() {
    // Set digital LOW to act as ground
    pinMode(GPIO_NUM_12, OUTPUT);
    digitalWrite(GPIO_NUM_12, LOW);

    LoRa.setPins(5, 4, 2);
    LoRa.begin(433E6);
	escL.attach(escPinL, 1000, 2000);
	escR.attach(escPinR, 1000, 2000);
}

void loop() {
    int p = LoRa.parsePacket();

    if(p){
        if(LoRa.available()){
            signalTimeoutLastMeasure = millis();
            if(LoRa.read() == deviceTxID){
                if(LoRa.read() == 2){
                    rL = LoRa.read();
                    rR = LoRa.read();
                }
            }
        }
    }

    if(millis() - signalTimeoutLastMeasure >= signalTimeout){
        rL = 0;
        rR = 0;
    }

    escL.write(rL);
	escR.write(rR);
}
