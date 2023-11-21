#include <Servo.h>

int pirPin = 2;   // broche n°2
const int ledPin =13; //broche LED
Servo monServo;


void setup() {

  // put your setup code here, to run once:
  pinMode(pirPin, INPUT);
  pinMode (ledPin, OUTPUT);
  Serial.begin(9600);
 

}

void loop() {
  // put your main code here, to run repeatedly:
  int detection = digitalRead(pirPin);

  if (detection == HIGH) {
    Serial.println("Mouvement détecté");
    digitalWrite(ledPin, HIGH);
    delay(1000);
    

  }
  else{
    Serial.println(" Mouvement non détecté");
    digitalWrite(ledPin, LOW);
  }
}
