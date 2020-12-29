#define triggerPin 2
#define echoPin 3

const float speedOfSoundMps = 340;
const float speedOfSoundMpus = 0.000340;

float echoTime = 0;

void setup()
{
    pinMode(triggerPin, OUTPUT);
    pinMode(echoPin, INPUT);

    digitalWrite(triggerPin, LOW);

    Serial.begin(9600);
    delay(100);
}

void loop()
{
    fireUltrasoundPulse();
    echoTime = pulseIn(echoPin, HIGH);

    Serial.print("Dist. (m): ");
    Serial.println(EstimateDistance(echoTime));

    delay(2000);
}

void fireUltrasoundPulse()
{
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);
}

float EstimateDistance(float timeUs)
{
    return timeUs * speedOfSoundMpus / 2.0;
}
