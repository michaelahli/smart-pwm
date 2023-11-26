#ifndef RESOURCE_USAGE_H
#define RESOURCE_USAGE_H

#include "config.h"

#include <Arduino.h>
#include <math.h>

class ResourceUsage
{
public:
    ResourceUsage();
    float store(float input);
    float getVoltage();
    float getResistance();
    float getCurrent();
    float getPower();
    float getMaxPower();
    int powerToAnalog(float power);

private:
    float voltage;
    float current;
    float power;
    // TODO: measure resistance using analog input
    float resistance = (VCC - EXPECTED_VOUT) / EXPECTED_IOUT;
    float resistanceCoil = 1;
};

#endif // RESOURCE_USAGE_H
