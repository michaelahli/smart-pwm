#ifndef BUTTON_H
#define BUTTON_H

#include "config.h"
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class Button
{
public:
    Button(byte attachTo, long freq = 3000, bool active = LOW);
    void begin();
    void beep();
    bool wasPressed();

private:
    const byte buttonPin;
    static constexpr byte debounceDelay = 30;
    const bool active;
    const int freq;
    bool lastButtonState;
    byte lastDebounceTime;
};

#endif // BUTTON_H
