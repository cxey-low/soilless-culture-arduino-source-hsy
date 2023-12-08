#include <LiquidCrystal_I2C.h>

#define BUTTON 27

#define STEAM A10
#define TEM A9
#define LIGHT A8

#define WAIT 500

LiquidCrystal_I2C lcd(0x20, 16, 2);

const int sensorNum[3] = {A8, A9, A10};
const char sensor[3][6] = {"LIGHT", "TEM  ", "STEAM"};
short sensorType = 0;
unsigned long time = 0;
unsigned long time2 = 0;

short buttonPressed()
{

    if (digitalRead(BUTTON) == HIGH)
    {
        if (millis() - time > 500)
        {
            time = millis();
            sensorType = (sensorType == 2) ? 0 : (sensorType + 1);
            sensorSer();

            return 1;
        }
        else
        {
            return 0;
        }
    }
}

double sensorRead(uint8_t a)
{
    return (a == A9) ? (double)analogRead(A9) * (5 / 10.24) : analogRead(a);
}

void sensorSer()
{
    if (Serial.available())
    {
        for (short i = 0; i < 3; i += 1)
        {
            Serial.println(sensor[i]);
            Serial.println(sensorRead(sensorNum[i]));
        }
    }
}

void sensorLcd()
{
    if (millis()-time2>500)
    {
        time2=millis();
            lcd.setCursor(0, 0);
    lcd.print(sensor[sensorType]);
    lcd.setCursor(0, 1);
    lcd.print("                 ");
    lcd.setCursor(0, 1);
    lcd.print(sensorRead(sensorNum[sensorType]));
    lcd.setCursor(0, 0);
    lcd.print(sensor[sensorType]);
    lcd.setCursor(0, 1);
    lcd.print("                 ");
    lcd.setCursor(0, 1);
    lcd.print(sensorRead(sensorNum[sensorType]));

    }
    
}


void setup()
{
    // lcd
    lcd.init();
    lcd.backlight();
    lcd.home();
    lcd.clear();


    // Serial
    Serial.begin(9600);

    // pinMode

    pinMode(TEM, INPUT);
    pinMode(LIGHT, INPUT);
    pinMode(STEAM, INPUT);
}

void loop()
{
    buttonPressed();

    sensorLcd();
}