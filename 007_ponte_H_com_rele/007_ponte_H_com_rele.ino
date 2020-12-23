#define IN1 4
#define IN2 5
#define button 8

bool rodaSentidoHorario = true;

void setup()
{
    Serial.begin(9600);
    pinMode(button, INPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);
    delay(100);
}

void loop()
{
    if (digitalRead(button) == HIGH)
    {
        rodaSentidoHorario = !rodaSentidoHorario;
        delay(500);
    }

    if (rodaSentidoHorario)
    {
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        Serial.println("Relé K1 acionado!");
    }
    else
    {
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        Serial.println("Relé K2 acionado!");
    }
}