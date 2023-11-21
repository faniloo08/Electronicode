#include <Servo.h>

const int trigPin = 9;   //broche de déclenchement du capteur
const int echoPin = 10;  //broche d'echo
int servoPin = 3;
Servo monServo;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  monServo.attach(servoPin) ;
  monServo.write(90); //position initiale
  Serial.begin(9600);


}

void loop() {
 
 // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
 
  int distance = duration/58.2; //conversion cm

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("  cm");

  if (distance < 20) {
    monServo.write(0); //déplacement
    delay(1000);
    monServo.write(90);
  }  

  delay(100);

 

}
