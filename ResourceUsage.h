#ifndef RESOURCE_USAGE_H
#define RESOURCE_USAGE_H

#include "config.h"

class ResourceUsage
{
public:
    ResourceUsage();
    float store(float input);
    float getVoltage();
    float getResistance();
    float getCurrent();
    float getPower();

private:
    float voltage;
    float resistance;
    float current;
    float power;
};

#endif // RESOURCE_USAGE_H
