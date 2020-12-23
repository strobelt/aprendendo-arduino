#define sensorPin A0

int sensorValue = 0;
float voltage;

void setup()
{
  Serial.begin(9600);
  delay(200);
}

void loop()
{
  sensorValue = analogRead(sensorPin);
  voltage = sensorValue * (5.0 / 1024);

  Serial.print("Tensão do potenciômetro: ");
  Serial.print(voltage);
  Serial.print("V Valor lógico: ");
  Serial.println(sensorValue);
  delay(1000);
}
