#include <LiquidCrystal_I2C.h>

#define tem_led 14
#define tem_button 15
#define tem_sensor A11

/*
I2C device found at address 0x20  !
I2C device found at address 0x7C  !
*/

LiquidCrystal_I2C lcd(0x20, 16, 2);

byte cus[8] = {
    0b00000,
    0b01010,
    0b11111,
    0b11111,
    0b01110,
    0b00100,
    0b00000,
    0b00000};

byte ctem[8] = {
    0b11100,
    0b10111,
    0b11100,
    0b01100,
    0b01100,
    0b01111,
    0b00111,
    0b00111};

void clean()
{
    lcd.home();
    lcd.print("              ");
    lcd.setCursor(0, 1);
    lcd.print("              ");
}

void hello()
{
    // clean();
    lcd.setCursor(0, 0);
    lcd.print("  Hello world!  ");
    lcd.setCursor(0, 1);
    lcd.write(0);
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

    lcd.createChar(0, cus);
    lcd.createChar(1,ctem);

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
        // clean();
        lcd.home();
        lcd.print("Tem:              ");
        lcd.setCursor(5, 1);
        lcd.print("          ");
        lcd.setCursor(0, 1);
        lcd.print((double)(analogRead(tem_sensor) * (5 / 10.24)));
        lcd.setCursor(6,1);
        lcd.write(1);
    }
    else if (!(digitalRead(tem_button)))
    {
        hello();
    }
}
