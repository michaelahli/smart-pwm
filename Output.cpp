#include "Output.h"
#include <Arduino.h>

Output::Output(int outputPin, int potentiometerPin)
{
    this->outputPin = outputPin;
    this->potentiometerPin = potentiometerPin;
    this->connected = true;
}

void Output::pwm()
{
    if (connected)
    {
        float potentiometerValue = map(analogRead(potentiometerPin), 0, 4095, 0, 255);
        analogWrite(outputPin, potentiometerValue);
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