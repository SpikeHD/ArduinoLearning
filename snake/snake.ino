#include <LiquidCrystal_I2C.h>

int btn_pin = 2;
int x_lim = 20, y_lim = 4;
int curFoodX, curFoodY, curAiX = x_lim, curAiY = y_lim;

LiquidCrystal_I2C lcd(0x27, x_lim, y_lim);

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
    foodSpawn();
  }

  ai();

  delay(500);
}

void foodSpawn() {
  curFoodX = random(x_lim);
  curFoodY = random(y_lim);
}

void ai() {
  int x_dir = curFoodX - curAiX,
      y_dir = curFoodY - curAiY;

  if(x_dir < 0) {
    curAiX--;
  } else if (x_dir > 0) {
    curAiX++;
  } else if (y_dir < 0) {
    curAiY--;
  } else if (y_dir > 0) {
    curAiY++;
  } else {
    foodSpawn();
  }
  
  lcd.setCursor(curAiX, curAiY);
  lcd.print("S");
  
  lcd.setCursor(curFoodX, curFoodY);
  lcd.print("0");
}
