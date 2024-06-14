// #include <Arduino.h>
// #include <ESP32Servo.h>
// #include <DabbleESP32.h>

// const int escPin1 = GPIO_NUM_18;
// const int escPin2 = GPIO_NUM_19;

// Servo esc1 = Servo();
// Servo esc2 = Servo();

// void setup() {
//   	// put your setup code here, to run once:
//   	Serial.begin(115200); 
// 	Dabble.begin("MyEsp32");

// 	esc1.attach(escPin1, 1000, 2000);
// 	esc2.attach(escPin2, 1000, 2000);
// }

// void loop() {
//   	Dabble.processInput();

// 	// Raio representa o multiplicador de velocidade dos dois motores
// 	float radius = abs(GamePad.gety_axis());

// 	// vet representa o eixo X do analógico (-7 a 7)
// 	float vet = GamePad.getx_axis();

// 	float vetE; // Quantos porcento o motor E está ligado
// 	float vetD; // Quantos porcento o motor D está ligado
	
// 	if(vet > 0){
// 		vetD = (7-vet)/7.0f;
// 		vetE = 1;
// 	}else if(vet < 0){
// 		vetD = 1;
// 		vetE = (7-abs(vet))/7.0f;
// 	}else{
// 		vetD = 1;
// 		vetE = 1;
// 	}

// 	int escE = (int)(radius * vetE * 1000);
// 	int escD = (int)(radius * vetD * 1000);

// 	// // Envia o PWM para o ESC do motor (0 a 180)
// 	int rE = map(escE, 0, 7000, 0, 180);
// 	int rD = map(escD, 0, 7000, 0, 180);
// 	esc1.write(rE);
// 	esc2.write(rD);

// 	Serial.printf("%d     %d\n", rE, rD);
// }
