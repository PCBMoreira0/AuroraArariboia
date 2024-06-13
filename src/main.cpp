/*
   Gamepad module provides three different mode namely Digital, JoyStick and Accerleometer.

   You can reduce the size of library compiled by enabling only those modules that you want to
   use. For this first define CUSTOM_SETTINGS followed by defining INCLUDE_modulename.

   Explore more on: https://thestempedia.com/docs/dabble/game-pad-module/
*/

#include <Arduino.h>
#include <ESP32Servo.h>

#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>

const int escPin1 = GPIO_NUM_18;
const int escPin2 = GPIO_NUM_19;
Servo esc1 = Servo();
Servo esc2 = Servo();

void setup() {
  	// put your setup code here, to run once:
  	Serial.begin(115200);      // make sure your Serial Monitor is also set at this baud rate.
  	Dabble.begin("MyEsp32");       //set bluetooth name of your device
	esc1.attach(escPin1, 1000, 2000);
	esc2.attach(escPin2, 1000, 2000);
}

void loop() {
  	Dabble.processInput();             //this function is used to refresh data obtained from smartphone.Hence calling this function is mandatory in order to get data properly from your mobile.
	// int radius = GamePad.getRadius();
	// float vet = GamePad.getx_axis();
	// float vetE;
	// float vetD;
	// int escE;
	// int escD;
	// if(vet > 0){
	// 	vetE = vet /7.0f;
	// 	vetD = (7-vet) / 7.0f;
	// }else{
	// 	vetE = (7-vet) / 7.0f;
	// 	vetD = vet / 7.0f;
	// }
	// escE = radius * vetE;
	// escD = radius * vetD;
	// esc1.write(map(escE, 0, 7, 0, 180));
	// esc2.write(map(escD, 0, 7, 0, 180));
}
