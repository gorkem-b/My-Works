// Include necessary libraries
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <Wire.h>

// --- SETTINGS ---
char Master[] = "5689";                     // The fixed password
LiquidCrystal_I2C lcd(0x27, 16, 2);         // LCD I2C address (Change to 0x3F if needed)

// --- PIN DEFINITIONS ---
Servo lockServo;
const int servoPin = 13;
const int redLedPin = 7;
const int greenLedPin = 6;
const int buzzerPin = 8;

// Keypad setup
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
// Pin assignments according to the standard wiring
byte rowPins[ROWS] = {A3, A2, A1, A0};
byte colPins[COLS] = {5, 4, 3, 2};

// Required variables
Keypad customKeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
char enteredPassword[sizeof(Master)];
byte charIndex = 0;

void setup() {
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  lockServo.attach(servoPin);
  lcd.init();
  lcd.backlight();
  lockDoor();
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Enter Password:");
  char customKey = customKeypad.getKey();
  if (customKey) {
    if (customKey == '*') {
        resetSystem();
        return;
    }

    if (charIndex < (sizeof(Master) - 1)) {
        enteredPassword[charIndex] = customKey;
        lcd.setCursor(charIndex, 1);
        lcd.print("*");
        charIndex++;
        makeSound();
    }
  }

  if (charIndex == (sizeof(Master) - 1)) {
      checkPassword();
  }
}

void checkPassword() {
  if (strcmp(enteredPassword, Master) == 0) {
    accessGranted();
  } else {
    accessDenied();
  }
}

void accessGranted() {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Access Granted");
    digitalWrite(greenLedPin, HIGH);
    openDoor();
    delay(5000);
    resetSystem();
}

void accessDenied() {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Access Denied");
    digitalWrite(redLedPin, HIGH);
    makeSound();
    delay(200);
    makeSound();
    delay(2000);
    resetSystem();
}

void openDoor() {
  lockServo.write(90);
}

void lockDoor() {
  lockServo.write(0);
}

void resetSystem() {
  memset(enteredPassword, 0, sizeof(enteredPassword));
  charIndex = 0;
  digitalWrite(greenLedPin, LOW);
  digitalWrite(redLedPin, LOW);
  lockDoor();
  lcd.clear();
}

void makeSound() {
  digitalWrite(buzzerPin, HIGH);
  delay(100);
  digitalWrite(buzzerPin, LOW);
}