#include<SoftwareSerial.h>
SoftwareSerial HC11(2,3);//2rx pir  3tx pin    
#define Sensor1 A0
#define Sensor2 A1
#define Sensor3 A2
#define Sensor4 A3
#define Sensor5 A4

#define XPin A5
int Sensor1Value = 0;
int Sensor2Value = 0;
int Sensor3Value = 0;
int Sensor4Value = 0;
int Sensor5Value = 0;
//digitalWrite(4,1);
int XAxis = 0;

void setup() {

  digitalWrite(4,1);
  pinMode(Sensor1, INPUT);
  pinMode(Sensor2, INPUT);
  pinMode(Sensor3, INPUT);
  pinMode(Sensor4, INPUT);
  pinMode(Sensor5, INPUT);
  pinMode(XPin, INPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(4,OUTPUT);
  Serial.begin(9600);
  HC11.begin(9600);
}

void loop() {
  
  Sensor1Value = analogRead(Sensor1);
  Sensor2Value = analogRead(Sensor2);
  Sensor3Value = analogRead(Sensor3);
  Sensor4Value = analogRead(Sensor4);
  Sensor5Value = analogRead(Sensor5);
  XAxis = analogRead(XPin);
  

  Serial.print(" S1 = ");
  Serial.print(Sensor1Value);
  Serial.print(" S2 = ");
  Serial.print(Sensor2Value);
  Serial.print(" S3 = ");
  Serial.print(Sensor3Value);
  Serial.print(" S4 = ");
  Serial.print(Sensor4Value);
  Serial.print(" S5 = ");
  Serial.println(Sensor5Value);
  Serial.print(" XAxis = ");
  Serial.println(XAxis);
  delay(1);

  Check();
}
void Check() {
  if (XAxis >= 400) {
  digitalWrite(7,1);digitalWrite(8,0);
   Message();
  }

  if (XAxis < 280) {
  digitalWrite(7,0);digitalWrite(8,1);
   Control();
  }
  else{
    
  }
}

void Message () {
   if (Sensor1Value <= 100 && Sensor2Value >= 100 && Sensor3Value >= 100 && Sensor4Value >= 100 && Sensor5Value >= 100) {
    HC11.println("A");
    digitalWrite(4,0);
    delay(2000);
    digitalWrite(4,1);
  }
  if (Sensor1Value >= 100 && Sensor2Value <= 100 && Sensor3Value >= 100 && Sensor4Value >= 100 && Sensor5Value >= 100 ) {
    HC11.println("B");
    digitalWrite(4,0);
    delay(2000);
    digitalWrite(4,1);
  }
  if (Sensor1Value >= 100 && Sensor2Value >= 100 && Sensor3Value <= 100 && Sensor4Value >= 100 && Sensor5Value >= 100 ) {
    HC11.println("C");
    digitalWrite(4,0);
    delay(2000);
    digitalWrite(4,1);
  }
  if (Sensor1Value >= 100 && Sensor2Value >= 100 && Sensor3Value >= 100 && Sensor4Value <= 100 && Sensor5Value >= 100 ) {
    HC11.println("D");
    digitalWrite(4,0);
    delay(2000);
    digitalWrite(4,1);
  }
  if (Sensor1Value >= 100 && Sensor2Value >= 100 && Sensor3Value >= 100 && Sensor4Value >= 100 && Sensor5Value <= 100 ) {
    HC11.println("E");
    digitalWrite(4,0);
    delay(2000);
    digitalWrite(4,1);
  }
  else{
    

}
}
void Control () {
 if (Sensor1Value <= 100 && Sensor2Value >= 100 && Sensor3Value >= 100 && Sensor4Value >= 100 && Sensor5Value >= 100) {
    HC11.println("1");
    digitalWrite(4,0);
    delay(2000);
    digitalWrite(4,1);
  }
  if (Sensor1Value >= 100 && Sensor2Value <= 100 && Sensor3Value >= 100 && Sensor4Value >= 100 && Sensor5Value >= 100 ) {
    HC11.println("2");
    digitalWrite(4,0);
    delay(2000);
    digitalWrite(4,1);
  }
  if (Sensor1Value >= 100 && Sensor2Value >= 100 && Sensor3Value <= 100 && Sensor4Value >= 100 && Sensor5Value >= 100 ) {
    HC11.println("3");
    digitalWrite(4,0);
    delay(2000);
    digitalWrite(4,1);
  }
  if (Sensor1Value >= 100 && Sensor2Value >= 100 && Sensor3Value >= 100 && Sensor4Value <= 100 && Sensor5Value >= 100 ) {
    HC11.println("4");
    digitalWrite(4,0);
    delay(2000);
    digitalWrite(4,1);
  }
  if (Sensor1Value >= 100 && Sensor2Value >= 100 && Sensor3Value >= 100 && Sensor4Value >= 100 && Sensor5Value <= 100 ) {
    HC11.println("5");
    digitalWrite(4,0);
    delay(2000);
    digitalWrite(4,1);
  }
  else{
    

}
}
