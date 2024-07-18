// #include <Arduino.h>
// #include <DabbleESP32.h>
// #include <LoRa.h>

// unsigned long lora_sending_delay_ms = 100;
// unsigned long last_time_ms = 0;

// uint8_t deviceID = 0xFA;
// uint8_t payLoad_size = 2;

// void setup() {
// 	// inicialização Serial
//   	Serial.begin(9600); 

// 	// Dabble (comunicação com o app Dabble)
// 	Dabble.begin("MyEsp32");

// 	// LoRa initialization
//     LoRa.setPins(5, 4, 2);
// 	LoRa.begin(433E6);
// }

// void loop() {
//   	Dabble.processInput();

// 	// Raio representa o multiplicador de velocidade dos dois motores
// 	int radius = GamePad.getRadius();

// 	float vetE; // Quantos porcento o motor E está ligado
// 	float vetD; // Quantos porcento o motor D está ligado
	
//     if(GamePad.isSquarePressed()){
//         vetD = 1;
// 		vetE = 0.35f;
//     }else if(GamePad.isCirclePressed()){
//         vetD = 0.35f;
// 		vetE = 1;
//     }else{
//         vetE = 1;
//         vetD = 1;
//     }

// 	int escE = (int)(radius * vetE * 1000);
// 	int escD = (int)(radius * vetD * 1000);

// 	// Envia o PWM para o ESC do motor (0 a 180)
// 	uint8_t rE = map(escE, 0, 7000, 0, 180);
// 	uint8_t rD = map(escD, 0, 7000, 0, 180);
	
// 	LoRa.beginPacket();
// 	// Envia ID para diferenciar dispositivo de outros
// 	LoRa.write(deviceID);
// 	// Tamanho do pacote
// 	LoRa.write(payLoad_size);
// 	LoRa.write(rE);
//   LoRa.write(rD); 
// 	LoRa.endPacket();
// }
