#define buttonPin 8
#define ledPin 7

bool aceso = false;

void setup()
{
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  delay(100);
}

void loop()
{
  if(digitalRead(buttonPin) == HIGH)
  {
    aceso = !aceso;
  }
  if(aceso)
  {
    digitalWrite(ledPin, HIGH);
    Serial.println("Acendendo LED");
  }
  else
  {
    digitalWrite(ledPin, LOW);
    Serial.println("Desligando LED");
  }
  delay(100); 
}
