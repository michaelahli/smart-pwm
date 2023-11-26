#include "Output.h"

Output::Output(int outputPin, ResourceUsage usage)
{
    this->outputPin = outputPin;
    this->usage = usage;
}

void Output::pwm()
{
    if (connected)
    {
        usage.store(pwmval);
        analogWrite(outputPin, pwmval);
    }
}

void Output::disconnect()
{
    connected = false;
    analogWrite(outputPin, 0);
}

void Output::connect()
{
    connected = true;
}

bool Output::state()
{
    return connected;
}

void Output::setPower(int power)
{
    this->power = power;
    this->pwmval = usage.powerToAnalog(power);
}

int Output::getPower()
{
    return power;
}