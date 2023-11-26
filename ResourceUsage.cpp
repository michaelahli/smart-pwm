#include "ResourceUsage.h"

ResourceUsage::ResourceUsage()
{
    voltage = 0;
    resistance = 0;
    current = 0;
    power = 0;
}

float ResourceUsage::store(float input)
{
    voltage = input / INPUT_RANGE * VCC;
    resistance = (VCC - EXPECTED_VOUT) / EXPECTED_IOUT;
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
