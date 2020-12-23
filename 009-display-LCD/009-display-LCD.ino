#include <LiquidCrystal.h>
#include<DHT.h>
#include<DHT_U.h>

#define DHTTYPE DHT11
#define DHTPIN 2

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
DHT_Unified dht(DHTPIN, DHTTYPE);
uint32_t delayMS = 500;

void setup()
{
    dht.begin();
    sensor_t sensor;
    lcd.begin(16, 2);
    delay(500);
}

void loop()
{
    sensors_event_t event;
    dht.temperature().getEvent(&event);
    
    lcd.clear();
    if(!isnan(event.temperature))
    {
        lcd.setCursor(0, 0);
        lcd.print("Temp: ");
        lcd.print(event.temperature);
        lcd.print(" C");
    }

    dht.humidity().getEvent(&event);
    if(!isnan(event.relative_humidity))
    {
        lcd.setCursor(0, 1);
        lcd.print("Humi: ");
        lcd.print(event.relative_humidity);
        lcd.print(" %");
    }
    
    delay(delayMS);
}
