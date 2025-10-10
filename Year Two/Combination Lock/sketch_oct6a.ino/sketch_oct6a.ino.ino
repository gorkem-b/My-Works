#include <Keypad.h>          
#include <LiquidCrystal_I2C.h> 
#include <Servo.h>           
#include <Wire.h>            

char Master[] = "1234";      
LiquidCrystal_I2C lcd(0x27, 16, 2); 
Servo kilitServo;             
const int servoPin = 13;     
const int kirmiziLedPin = 7;  
const int yesilLedPin = 6;    
const int buzzerPin = 8;      

const byte SATIR_SAYISI = 4;  
const byte SUTUN_SAYISI = 4;  
char tuslar[SATIR_SAYISI][SUTUN_SAYISI] = { 
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte satirPinleri[SATIR_SAYISI] = {A3, A2, A1, A0}; 
byte sutunPinleri[SUTUN_SAYISI] = {12, 11, 10, 9};
Keypad customKeypad = Keypad(makeKeymap(tuslar), satirPinleri, sutunPinleri, SATIR_SAYISI, SUTUN_SAYISI);


char girilenSifre[sizeof(Master)];
byte sayac = 0;

void setup() {
  pinMode(kirmiziLedPin, OUTPUT);
  pinMode(yesilLedPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  kilitServo.attach(servoPin);
  lcd.init();
  lcd.backlight();
  kapiyiKilitle();
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Sifreyi Girin:");
  char customKey = customKeypad.getKey();
  if (customKey) {
    girilenSifre[sayac] = customKey;
    lcd.setCursor(sayac, 1);
    lcd.print("*");
    sayac++;
    sesCikar();
  }
  if (sayac == (sizeof(Master) - 1) || customKey == '*') {
    if (customKey == '*') {
      sifirlama();
    } else {
      kontrolEt();
    }
  }
}

void kontrolEt() {
  if (strcmp(girilenSifre, Master) == 0) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sifre Dogru");
    digitalWrite(yesilLedPin, HIGH);
    kapiyiAc();
    delay(5000);
    sifirlama();
  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sifre Hatali");
    digitalWrite(kirmiziLedPin, HIGH);
    sesCikar();
    delay(200);
    sesCikar();
    delay(2000);
    sifirlama();
  }
}

void kapiyiAc() {
  kilitServo.write(90);
}
void kapiyiKilitle() {
  kilitServo.write(0);
}
void sifirlama() {
  memset(girilenSifre, 0, sizeof(girilenSifre));
  sayac = 0;
  digitalWrite(yesilLedPin, LOW);
  digitalWrite(kirmiziLedPin, LOW);
  kapiyiKilitle();
  lcd.clear();
}
void sesCikar() {
  digitalWrite(buzzerPin, HIGH);
  delay(100);
  digitalWrite(buzzerPin, LOW);
}