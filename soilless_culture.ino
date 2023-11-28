#include <LiquidCrystal_I2C.h>

#define WAIT 500

LiquidCrystal_I2C lcd(0x20, 16, 2);

void hello()
{
    lcd.setCursor(0, 0);
    lcd.print("  Hellooworld!  ");
    lcd.setCursor(0, 1);
    lcd.setCursor(1, 1);
    lcd.print("     CXeY      ");
}

void setup()
{
    // lcd
    lcd.init();
    lcd.backlight();
    lcd.home();
    lcd.clear();

    hello();

    // Serial
    Serial.begin(9600);

    // pinMode
    pinMode(A6,INPUT);
}

void loop()
{
    delay(WAIT);
    Serial.print(analogRead(A6));
    lcd.print("123");
}