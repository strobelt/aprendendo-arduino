#include <IRremote.h>

#define IRPin A0
#define Rele1 A1
#define Rele2 A2

#define BtnFrente 0xFF18E7
#define BtnTras 0xFF4AB5
#define BtnDireita 0xFF5AA5
#define BtnEsquerda 0xFF10EF

IRrecv irrecv(IRPin);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();

  pinMode(Rele1, OUTPUT);
  pinMode(Rele2, OUTPUT);

  desligaRodaEsquerda();
  desligaRodaDireita();
  delay(100);
}

void loop()
{
  results.value = 0;
  if (irrecv.decode(&results))
  {
    Serial.println(results.value, HEX);
    irrecv.resume();
    delay(10);
  }

  switch (results.value)
  {
  case BtnFrente:
    ligaRodaEsquerda();
    ligaRodaDireita();
    break;

  case BtnTras:
    desligaRodaEsquerda();
    desligaRodaDireita();
    break;

  case BtnDireita:
    desligaRodaDireita();
    ligaRodaEsquerda();
    break;

  case BtnEsquerda:
    desligaRodaEsquerda();
    ligaRodaDireita();
    break;

  default:
    break;
  }
}

void ligaRodaEsquerda()
{
  digitalWrite(Rele1, LOW);
}

void ligaRodaDireita()
{
  digitalWrite(Rele2, LOW);
}

void desligaRodaEsquerda()
{
  digitalWrite(Rele1, HIGH);
}

void desligaRodaDireita()
{
  digitalWrite(Rele2, HIGH);
}
