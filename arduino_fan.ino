#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//Define Display
LiquidCrystal_I2C lcd(0x27,20,4);

//Define our Button Pins
const int BUTTON1 = 0;
const int BUTTON2 = 1;
const int BUTTON3 = 2;
const int BUTTON4 = 3;
const int BUTTON5 = 4;
const int BUTTON6 = 5;

unsigned long previousRPMMillis;
unsigned long previousMillis;
float RPM;
int percentage;
int newpwmValue;
 
unsigned long interval = 1000;
byte pwmValue = 78;
byte lastpwmValue = 250;
byte pwmInterval = 5;
const byte pwmMax = 250;
const byte pwmMin = 75;
 
const int reedPin = 2;
const int fanPin = 5;  
 
volatile unsigned long pulses=0;
unsigned long lastRPMmillis = 0;

#include "fancontrol.h"
#include "lcdfunctions.h"
#include "controls.h"
 
void setup() {
  Serial.begin(115200);
  pinMode(reedPin,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(reedPin), countPulse, FALLING);
  lcd.init();
  lcd.backlight();
  pinMode(fanPin, OUTPUT); // probably PWM
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  pinMode(BUTTON3, INPUT);
  pinMode(BUTTON4, INPUT);
  pinMode(BUTTON5, INPUT);
  pinMode(BUTTON6, INPUT);
}
 
void loop() {
  handleButton();
  analogWrite(fanPin, pwmValue);
  if (millis() - previousMillis > interval) {
    lcdUpdate();
//    Serial.print("RPM=");
//    Serial.print(calculateRPM());
//    Serial.print(F(" @ PWM="));
//    Serial.println(pwmValue);
    previousMillis = millis();  
  }
}
