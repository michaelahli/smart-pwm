#include "ResourceUsage.h"

ResourceUsage::ResourceUsage()
{
    voltage = 0;
    current = 0;
    power = 0;
}

float ResourceUsage::store(float input)
{
    voltage = input / INPUT_RANGE * VCC;
    current = voltage / resistance;
    power = voltage * current;

    return input;
}

float ResourceUsage::getVoltage()
{
    return voltage;
}

float ResourceUsage::getResistance()
{
    return resistance;
}

float ResourceUsage::getCurrent()
{
    return current;
}

float ResourceUsage::getPower()
{
    return power;
}

float ResourceUsage::getMaxPower()
{
    return pow(VCC, 2) / resistanceCoil;
}

int ResourceUsage::powerToAnalog(float power)
{
    return power / getMaxPower() * INPUT_RANGE;
}
