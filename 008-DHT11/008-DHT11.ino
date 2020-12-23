#include <DHT.h>
#include <DHT_U.h>

#define DHTType DHT11
#define DHTPin 2
DHT_Unified dht(DHTPin, DHTType);
uint32_t delayMS = 500;

void setup()
{
    Serial.begin(9600);
    dht.begin();
    Serial.println("Inicializando Sensor DHT11");
    sensor_t sensor;
}

void loop()
{
    delay(delayMS);
    sensors_event_t event;

    dht.temperature().getEvent(&event);
    if(isnan(event.temperature))
    {
        Serial.println("Não foi possível ler a temperatura");
    }
    else
    {
        Serial.print("Temperatura: ");
        Serial.print(event.temperature);
        Serial.println(" °C");
    }

    dht.humidity().getEvent(&event);
    if(isnan(event.relative_humidity))
    {
        Serial.println("Não foi possível ler a umidade");
    }
    else
    {
        Serial.print("Umidade relativa: ");
        Serial.print(event.relative_humidity);
        Serial.println("%");
    }
}
