#include "Button.h"

Button::Button(byte attachTo, long freq, bool active) : buttonPin(attachTo), freq(freq), active(active)
{
}

void Button::begin()
{
    if (active == LOW)
        pinMode(buttonPin, INPUT);
    else
        pinMode(buttonPin, INPUT_PULLUP);
}

void Button::beep()
{
    tone(BUZZER_PIN, freq, 75);
}

bool Button::wasPressed()
{
    bool buttonState = LOW;
    byte reading = LOW;
    if (digitalRead(buttonPin) == active)
        reading = HIGH;
    if (((millis() & 0xFF) - lastDebounceTime) > debounceDelay)
    {
        if (reading != lastButtonState && lastButtonState == LOW)
        {
            buttonState = HIGH;
            beep();
        }
        lastDebounceTime = millis() & 0xFF;
        lastButtonState = reading;
    }
    return buttonState;
}
