
#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
SoftwareSerial Gsm(11, 10);

LiquidCrystal lcd(8, 7, 6, 5, 4, 3);
#define Load1 14
#define Load2 15
#define Load3 16
#define Load4 17
#define Load5 18

bool Active1 = false;
bool Active2 = false;
bool Active3 = false;
bool Active4 = false;
bool Active5 = false;

bool Start = false;

char data;

void setup() {

  pinMode(Load1, OUTPUT);
  pinMode(Load2, OUTPUT);
  pinMode(Load3, OUTPUT);
  pinMode(Load4, OUTPUT);
  pinMode(Load5, OUTPUT);

  digitalWrite(Load1, HIGH);
  digitalWrite(Load2, HIGH);
  digitalWrite(Load3, HIGH);
  digitalWrite(Load4, HIGH);
  digitalWrite(Load5, HIGH);

  Serial.begin(9600);
  Gsm.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("    Welcome    ");
  lcd.setCursor(0, 1);
  lcd.print("  Smart Glove  ");
  delay(200);
  Gsm.println("AT");    //To send SMS in Text Mode
  delay(200);
  Gsm.println("AT");    //To send SMS in Text Mode
  delay(200);
  Gsm.println("AT+IPR=9600");    //To send SMS in Text Mode
  delay(200);
  Gsm.println("AT"); //Once the handshake test is successful, it will back to OK
  delay(200);
  Gsm.println("AT+CSQ"); //Signal quality test, value range is 0-31 , 31 is the best
  delay(200);
  Gsm.println("AT+CCID"); //Read SIM information to confirm whether the SIM is plugged
  delay(200);
  Gsm.println("AT+CREG?"); //Check whether it has registered in the network
  delay(200);
  Gsm.println("AT+CMGF=1"); // Configuring TEXT mode
  delay(200);
  Gsm.println("AT+CNMI=2,2,0,0,0"); // Decides how newly arrived SMS messages should be handled
  delay(200);
  Gsm.println("AT+CMGF=1");    //To send SMS in Text Mode
  delay(1000);
  Gsm.println("AT+CMGS=\"+923135302984\""); // change to the phone number you using
  delay(1000);
  Gsm.println("Device Activated");//the content of the message
  delay(2000);
  Gsm.println((char)26);//the stopping character
  delay(2000);
  lcd.clear();
}
void loop() {
  if (Serial.available()) {
    data = Serial.read();
    Serial.println(data);




    switch (data) {
      case ('A'):
        Gsm.println("AT+CMGF=1");    //To send SMS in Text Mode
        delay(1000);
        Gsm.println("AT+CMGS=\"+923135302984\""); // change to the phone number you using
        delay(1000);
        Gsm.println("I Want To Eat Food");//the content of the message
        delay(2000);
        Gsm.println((char)26);//the stopping character
        delay(1000);
        lcd.setCursor(0, 1);
        lcd.print("Message 1 Send  ");
        delay(10);
        break;

      case ('B'):
        Gsm.println("AT+CMGF=1");    //To send SMS in Text Mode
        delay(1000);
        Gsm.println("AT+CMGS=\"+923135302984\""); // change to the phone number you using
        delay(1000);
        Gsm.println("I Want To Drink Water");//the content of the message
        delay(2000);
        Gsm.println((char)26);//the stopping character
        delay(1000);
        lcd.setCursor(0, 1);
        lcd.print("Message 2 Send");
        delay(10);
        break;

      case ('C'):
        Gsm.println("AT+CMGF=1");    //To send SMS in Text Mode
        delay(1000);
        Gsm.println("AT+CMGS=\"+923135302984\""); // change to the phone number you using
        delay(1000);
        Gsm.println("I Need Help");//the content of the message
        delay(2000);
        Gsm.println((char)26);//the stopping character
        delay(1000);
        lcd.setCursor(0, 1);
        lcd.print("Message 3 Send");
        delay(10);
        break;

      case ('D'):
        Gsm.println("AT+CMGF=1");    //To send SMS in Text Mode
        delay(1000);
        Gsm.println("AT+CMGS=\"+923135302984\""); // change to the phone number you using
        delay(1000);
        Gsm.println("I Want To Goto Washroom");//the content of the message
        delay(2000);
        Gsm.println((char)26);//the stopping character
        delay(1000);
        lcd.setCursor(0, 1);
        lcd.print("Message 4 Send");
        delay(10);
        break;

      case ('E'):
        Gsm.println("AT+CMGF=1");    //To send SMS in Text Mode
        delay(1000);
        Gsm.println("AT+CMGS=\"+923135302984\""); // change to the phone number you using
        delay(1000);
        Gsm.println("I Want To Take My Medicine");//the content of the message
        delay(2000);
        Gsm.println((char)26);//the stopping character
        delay(1000);
        lcd.setCursor(0, 1);
        lcd.print("Message 5 Send");
        delay(10);
        break;

      case ('1'):
        Start = true;

        if (Active1 == false && Start == true) {

          lcd.setCursor(0, 0);
          lcd.print("Load1 OFF      ");
          digitalWrite(Load1, HIGH);
          delay(1000);
          Active1 = true;
          Start = false;
        }
        if (Active1 == true && Start == true) {

          lcd.setCursor(0, 0);
          lcd.print("Load1 ON       ");
          digitalWrite(Load1, LOW);
          delay(1000);
          Active1 = false;
          Start = false;
        }
        else {

        }


        break;

      case ('2'):
        Start = true;

        if (Active2 == false && Start == true) {

          lcd.setCursor(0, 0);
          lcd.print("Load2 OFF      ");
          digitalWrite(Load2, HIGH);
          delay(1000);
          Active2 = true;
          Start = false;
        }
        if (Active2 == true && Start == true) {

          lcd.setCursor(0, 0);
          lcd.print("Load2 ON       ");
          digitalWrite(Load2, LOW);
          delay(1000);
          Active2 = false;
          Start = false;
        }
        else {

        }


        break;

      case ('3'):
        Start = true;

        if (Active3 == false && Start == true) {

          lcd.setCursor(0, 0);
          lcd.print("Load3 OFF      ");
          digitalWrite(Load3, HIGH);
          delay(1000);
          Active3 = true;
          Start = false;
        }
        if (Active3 == true && Start == true) {

          lcd.setCursor(0, 0);
          lcd.print("Load3 ON       ");
          digitalWrite(Load3, LOW);
          delay(1000);
          Active3 = false;
          Start = false;
        }
        else {

        }


        break;

      case ('4'):
        Start = true;

        if (Active4 == false && Start == true) {

          lcd.setCursor(0, 0);
          lcd.print("Load4 OFF      ");
          digitalWrite(Load4, HIGH);
          delay(1000);
          Active4 = true;
          Start = false;
        }
        if (Active4 == true && Start == true) {

          lcd.setCursor(0, 0);
          lcd.print("Load4 ON       ");
          digitalWrite(Load4, LOW);
          delay(1000);
          Active4 = false;
          Start = false;
        }
        else {

        }


        break;

        
      case ('5'):
        Start = true;

        if (Active5 == false && Start == true) {

          lcd.setCursor(0, 0);
          lcd.print("Load5 OFF      ");
          digitalWrite(Load5, HIGH);
          delay(1000);
          Active5 = true;
          Start = false;
        }
        if (Active5 == true && Start == true) {

          lcd.setCursor(0, 0);
          lcd.print("Load5 ON       ");
          digitalWrite(Load5, LOW);
          delay(1000);
          Active5 = false;
          Start = false;
        }
        else {

        }


        break;
    }


  }
  else {

  }






}
