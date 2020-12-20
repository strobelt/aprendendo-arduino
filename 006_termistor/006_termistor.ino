#define VIn 5.0
#define T0 298.15   // Kelvin
#define Rt 10000
#define R0 10000
#define T1 273.15   // 0C in K
#define T2 373.15   // 100C in K
#define RT1 355563
#define RT2 549

float beta,
      RInf,
      TempKelvin,
      TempCelsius,
      VOut,
      ROut;

void setup() {
    Serial.begin(9600);
    beta = log(RT1/RT2) / ((1/T1) - (1/T2));
    RInf = R0 * exp(-beta / T0);
    delay(100);
}

void loop() {
    VOut = VIn * ((float)analogRead(0)) / 1024.0;
    ROut = (Rt * VOut / (VIn - VOut));
    TempKelvin = (beta / log(ROut / RInf));
    TempCelsius = TempKelvin - T1;

    Serial.print("Temp. Celsius: ");
    Serial.print(TempCelsius);
    Serial.print("  Temp. Kelvin: ");
    Serial.println(TempKelvin);
    delay(500);
}