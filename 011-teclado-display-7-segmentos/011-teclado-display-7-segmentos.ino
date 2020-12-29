#include <Key.h>
#include <Keypad.h>
#include <SegmentDisplay.h>

SegmentDisplay segmentDisplay(A0, A1, A2, A3, A4, A5, 12, 13);

const byte ROWS = 4;
const byte COLS = 3;

char hexaKeys[ROWS][COLS] =
{
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'F','0','E'},
};

byte rowPins[ROWS] = { 11, 10, 9, 8 };
byte colPins[COLS] = { 7, 6, 5 };

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup()
{
  Serial.begin(9600);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
}

void loop()
{
  char customKey = customKeypad.getKey();
  int number = customKey - 48;

  if ((number > 16) && (number < 23)) number = number - 7;

  if (customKey)
  {
    segmentDisplay.displayHex(number, false);
    Serial.println(number);
  }
}
