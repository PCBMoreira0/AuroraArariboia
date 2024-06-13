// #include <Arduino.h>
// #include <ESP32Servo.h>

// constexpr int escPin = 21;
// // constexpr int potPin = 4;

// Servo esc = Servo();

// void setup() {
// 	Serial.begin(9600);
// 	esc.attach(escPin, 1000, 2000);
	
// }

// void loop() {
// 	int potValue = analogRead(potPin);
// 	esc.write(map(potValue, 0, 4095, 0, 180));
// 	Serial.println(esc.read());
// }