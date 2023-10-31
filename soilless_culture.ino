#include <LiquidCrystal_I2C.h>


/*
I2C device found at address 0x20  !
I2C device found at address 0x7C  !
*/

LiquidCrystal_I2C lcd(0x20,16,2);

void setup()
{
    lcd.init();
    lcd.backlight();
    lcd.home();
    lcd.setCursor(2,1);
    lcd.print("hello world");
}

void loop()
{
}
