#include <Arduino.h>
#include <ESP32Servo.h>
#include <LoRa.h>
#include <DabbleESP32.h>

const int escPinL = GPIO_NUM_26;
const int escPinR = GPIO_NUM_25;

Servo escL = Servo();
Servo escR = Servo();

unsigned long signalTimeoutLastMeasure = millis();
unsigned long signalTimeout = 5000;

uint32_t rL = 0;
uint32_t rR = 0;


void setup() {
    Serial.begin(9600);
    LoRa.setPins(5, 4, 2);
    LoRa.begin(433E6);
	escL.attach(escPinL, 1000, 2000);
	escR.attach(escPinR, 1000, 2000);
}

void loop() {
    char speed[8];
    int p = LoRa.parsePacket();
    if(p){
        if(LoRa.available()){
            signalTimeoutLastMeasure = millis();

            String s = LoRa.readString();
            s.toCharArray(speed, 8, 0);
        }
        speed[7] = '\0';
        int comma = 0;
        for(int i = 0; speed[i] != '\0'; i++){
            if(speed[i] == ','){
                comma = i;
                break;
            }
        }
        // 34,100\0
        char buff[4];
        int i;
        for(i = 0; i < comma; i++){
            buff[i] = speed[i];
        }
        buff[i] = '\0';
        
        rL = atoi(buff);

        char buff2[4];
        int j = 0;
        for(i = comma+1; speed[i] != '\0'; i++){
            buff2[j++] = speed[i];
        }
        buff2[j] = '\0';
        rR = atoi(buff2);
        // Serial.println(speed);
        Serial.printf("%d   %d\n", rL, rR);
    }
    // if(millis() - signalTimeoutLastMeasure >= signalTimeout){
    //     rL = 0;
    //     rR = 0;
    // }
    escL.write(rL);
	escR.write(rR);
}
