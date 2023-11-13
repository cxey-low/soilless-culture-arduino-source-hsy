#include <LiquidCrystal_I2C.h>

#define ROTATION A15
#define anaRO map(analogRead(A15), 0, 1023, 1, 4)

#define STEAM A10
#define TEM A9
#define LIGHT A8

#define WAIT 1000

LiquidCrystal_I2C lcd(0x20, 16, 2);

void hello()
{
    // clean();
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
    pinMode(ROTATION, INPUT);

    pinMode(TEM, INPUT);
    pinMode(LIGHT, INPUT);
    pinMode(STEAM, INPUT);
}

void loop()
{
    if (Serial.available())
    {
        switch ((char)Serial.read())
        {
        case 'd':

            Serial.println("ROTATION");
            Serial.println(analogRead(ROTATION));
            Serial.println("TEM");
            Serial.println(analogRead(TEM));
            Serial.println("LIGHT");
            Serial.println(analogRead(LIGHT));
            Serial.println("STEAM1");
            Serial.println(analogRead(STEAM));

            break;
        default:
            break;
        }
    }

    switch (anaRO)
    {
    case 1:
        lcd.home();
        lcd.print("STEAM         ");
        lcd.setCursor(0, 1);
        lcd.print("           ");
        lcd.setCursor(0, 1);
        lcd.print(analogRead(STEAM));
        lcd.setCursor(5, 1);
        delay(WAIT);
        break;
    case 2:
        lcd.home();
        lcd.print("Tem           ");
        lcd.setCursor(0, 1);
        lcd.print("           ");
        lcd.setCursor(0, 1);
        lcd.print((double)analogRead(TEM) * (5 / 10.24));
        lcd.setCursor(6, 1);
        delay(WAIT);
        break;
    case 3:
        lcd.home();
        lcd.print("LIGHT         ");
        lcd.setCursor(0, 1);
        lcd.print("           ");
        lcd.setCursor(0, 1);
        lcd.print(analogRead(LIGHT));
        lcd.setCursor(5, 1);
        delay(WAIT);
        break;
    default:
        break;
    }
}
