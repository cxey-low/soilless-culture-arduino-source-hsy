#include <LiquidCrystal_I2C.h>

#define tem_led 14
#define tem_button 15
#define tem_sensor A11

/*
I2C device found at address 0x20  !
I2C device found at address 0x7C  !
*/

LiquidCrystal_I2C lcd(0x20, 16, 2);

void hello()
{
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("Hello world!");
    lcd.setCursor(6, 1);
    lcd.print("CXeY");
}

void setup()
{
    // lcd
    lcd.init();
    lcd.backlight();
    lcd.home();

    hello();

    // Serial
    Serial.begin(9600);

    // pinMode
    pinMode(tem_led, OUTPUT);
    pinMode(tem_button, INPUT_PULLUP);
    pinMode(tem_sensor, INPUT);
}

void loop()
{
    delay(1000);

    digitalWrite(tem_led, digitalRead(tem_button));

    if (digitalRead(tem_button))
    {
        lcd.clear();
        lcd.home();
        lcd.print("Tem:");
        lcd.setCursor(1, 1);
        lcd.print((double)(analogRead(tem_sensor) * (5 / 10.24)));
    }else if (!(digitalRead(tem_button)))
    {
        hello();
    }
    
}
