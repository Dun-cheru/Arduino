#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial nodemcu(2, 3);
LiquidCrystal_I2C lcd(0x27,16,2);

Servo myservo1;
Servo myservo2;

int IR1 = 34; //entrance IR
int IR2 = 35; //exit IR
int IR3 = 33;
int IR4 = 32;
int IR5 = 31;
int IR6 = 30;

String sensor1;
String sensor2;
String sensor3;
String sensor4;

String cdata = ""; //complete data, consisting of sensors values
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
nodemcu.begin(9600);
 //LCD
  lcd.init();
  lcd.backlight();
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);
  pinMode(IR4, INPUT);
  pinMode(IR5, INPUT);
  pinMode(IR6, INPUT);
  pinMode(4, OUTPUT);
    //Servo motor Entrance
  myservo1.attach(36);

  //servo motor Exit
  myservo2.attach(37);

  lcd.setCursor (0, 0);
  lcd.print("     Hitman    ");
  lcd.setCursor(0, 1);
  lcd.print("  PARKING SYSTEM  ");
  delay (2000);
}

void loop() {
  // put your main code here, to run repeatedly:
//Entrance gate
if (digitalRead(34) == LOW) {
  myservo1.write(0);
  digitalWrite(4, HIGH);
  delay(3000);
}
else {
  myservo1.write(90);
  digitalWrite(4, LOW);
  delay(1000);
}
//Exit Gate
if (digitalRead(35) == LOW) {
  myservo2.write(0);
  delay(3000);
}
else {
  myservo2.write(90);
  delay(1000);
}
}
