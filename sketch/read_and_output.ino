#include <MedianFilter.h>
#include <LiquidCrystal_I2C.h>
#include <NewPing.h>


#define TRIGGER_PIN  7  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     6  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 450 // Maximum distance we want to ping (CM)

// Create MedianFilter
MedianFilter filter(31, 0);

// Create NewPing
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

// Set LCD and LCD address
LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() {
  // Init LCD
  lcd.begin();

  // Turn on backlight
  lcd.backlight();
}

void loop() {
  unsigned int o,ultSon = sonar.ping();

  filter.in(ultSon);
  o = filter.out();
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(o/US_ROUNDTRIP_CM);
  delay(100);
}
