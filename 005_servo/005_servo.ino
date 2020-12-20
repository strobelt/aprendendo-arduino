#include <Servo.h>

Servo servo;

#define potPin A0

int val;

void setup()
{
  servo.attach(6);
}

void loop()
{
  val = analogRead(potPin);
  val = map(val, 0, 1023, 0, 179);
  servo.write(val);
  Serial.print("Servo pos: ");
  Serial.println(val);
  delay(15);
}
