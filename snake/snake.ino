#include <LiquidCrystal_I2C.h>

int btn_pin = 2;

LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() {
  pinMode(btn_pin, INPUT);

  lcd.begin();
  lcd.backlight();
}

void loop() {
  int btnState = digitalRead(btn_pin);
  
  lcd.clear();
  lcd.setCursor(0,0);
  
  if(btnState == HIGH) {
    lcd.print("On!");
  } else {
    lcd.print("Off!");
  }

  delay(100);
}
