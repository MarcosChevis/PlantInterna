#include <Servo.h> 

Servo servo1;

int umidadeValue = 0;
int lightValue = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //LED
  pinMode(13, OUTPUT);

  //Light
  pinMode(A5, INPUT);

  //Umidade
  pinMode(A0, INPUT);
  //SERVO
  servo1.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  lightValue = analogRead(A5);
  umidadeValue = analogRead(A0);

  Serial.print(umidadeValue);
  Serial.print(",");
  Serial.print(lightValue);
  Serial.print("\n");

  if (umidadeValue > 900) {
    servo1.write(100);
  } else {
    servo1.write(0);
  }
  
  if (lightValue < 950 && (lightValue - umidadeValue) < 300) {
      digitalWrite(13, HIGH);
  } else {
      digitalWrite(13, LOW);

  }
  
}
