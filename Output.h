#ifndef OUTPUT_H
#define OUTPUT_H

#include <Arduino.h>
#include "ResourceUsage.h"

class Output
{
public:
    Output(int outputPin, ResourceUsage usage);

    void pwm();
    void disconnect();
    void connect();
    void setPower(int power);
    int getPower();
    bool state();

private:
    int outputPin;
    ResourceUsage usage;

    int power = 0;
    int pwmval = 0;
    bool connected = true;
};

#endif // OUTPUT_H
