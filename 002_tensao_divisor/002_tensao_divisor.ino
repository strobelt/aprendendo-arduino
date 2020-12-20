#define sensorPin1 A0
#define sensorPin2 A1

int sensorValue1 = 0;
int sensorValue2 = 0;
float voltage1;
float voltage2;

void setup()
{
  Serial.begin(9600);
  delay(100);
}

void loop()
{
  sensorValue1 = analogRead(sensorPin1);
  sensorValue2 = analogRead(sensorPin2);
  voltage1 = sensorValue1 * (5.0 / 1024);
  voltage2 = sensorValue2 * (5.0 / 1024);

  Serial.print("Divisor 1: ");
  Serial.print(voltage1);
  Serial.print("V Divisor 2: ");
  Serial.print(voltage2);
  Serial.println("V");
  delay(500);
}
