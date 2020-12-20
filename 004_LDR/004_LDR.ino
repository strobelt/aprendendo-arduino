#define analogLDR A0
#define outraPernaLDR A1
#define limiar 1.5
#define ledPin 13

int leitura = 0;
float voltageLDR;
float resistanceLDR;

void setup()
{
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  delay(100);
}

void loop()
{
  leitura = analogRead(analogLDR);
  voltageLDR = leitura * (5.0/1024);
  Serial.print("Sensor LDR: ");
  Serial.print(voltageLDR);
  Serial.println("V");

  if(voltageLDR > limiar)
    digitalWrite(ledPin, HIGH);
  else
    digitalWrite(ledPin, LOW);

  delay(500);
}
