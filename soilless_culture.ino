#include <LiquidCrystal_I2C.h>

/*
I2C device found at address 0x20  !
I2C device found at address 0x7C  !
*/

LiquidCrystal_I2C lcd(0x20, 16, 2);

void hello(){
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("Hello world!");
    lcd.setCursor(6, 1);
    lcd.print("CXeY");

}

void setup()
{
    //lcd
    lcd.init();
    lcd.backlight();
    lcd.home();

    hello();

    //Serial
    Serial.begin(9600);

    //pinMode
    pinMode(14,OUTPUT);


}

void loop()
{

    digitalWrite(14,HIGH);
    
}
