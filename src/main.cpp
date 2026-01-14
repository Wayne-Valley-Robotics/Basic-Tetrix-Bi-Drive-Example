#include "battery_check.h"
#include "drive.h"

PRIZM prizm;
EXPANSION exc;
PS4 ps4;

void setup()
{
  prizm.PrizmBegin();
  Serial.begin(115200);
  int batteryWarnLevel = batteryCheck();
  if (batteryWarnLevel >= 3) {
    Serial.println("Battery level low. Warning level " + batteryWarnLevel);
    prizm.setRedLED(HIGH);
  }
}

void loop()
{
  ps4.getPS4();
  updateDrive();
}