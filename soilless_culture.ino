#include <LiquidCrystal_I2C.h>
#include <stdlib.h>

#define WAIT 500
#define KEY 41

LiquidCrystal_I2C lcd(0x20, 16, 2);

void hello()
{
    lcd.setCursor(0, 0);
    lcd.print("  Random       ");
    lcd.setCursor(0, 1);
    lcd.setCursor(1, 1);
    lcd.print("               ");
}

// 由 './test.js' 生成
int a[100] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23};

int rando()
{
    return a[rand() % 100];
}

unsigned long time = 0;

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
    pinMode(KEY, INPUT);
}

void loop()
{

    Serial.print(digitalRead(KEY));
    Serial.print("\n");

    Serial.print(millis());
    Serial.print("\n");

    Serial.print(time);
    Serial.print("\n");
    Serial.print("\n");

    // delay(WAIT);
    if (millis() - time > 500 && digitalRead(KEY) == HIGH)
    {
        Serial.print("he");
        Serial.print("\n");

        lcd.setCursor(0, 1);
        Serial.print("\n");

        lcd.print("  ");
        lcd.setCursor(0, 1);
        lcd.print(rando());
        Serial.print("\n");

        time = millis();
    }
}