// -------------------------------------------------
// Copyright (c) 2021 HiBit <https://www.hibit.dev>
// -------------------------------------------------

#define POTENTIOMETER_PIN A6

struct potentiometer {
  byte level = 0;
};

potentiometer potentiometer;

void setup()
{
  pinMode(POTENTIOMETER_PIN, INPUT);

  Serial.begin(115200);
}

void loop()
{
  potentiometer.level = readPotentiometerLevelMapped(POTENTIOMETER_PIN);

  Serial.print("Potentiometer value [0-255]: ");
  Serial.println(potentiometer.level);
}

byte readPotentiometerLevelMapped(int pin)
{
  return map(analogRead(pin), 0, 1023, 0, 255);
}
