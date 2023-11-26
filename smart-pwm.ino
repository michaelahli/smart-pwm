#include "config.h"
#include "ResourceUsage.h"
#include "Button.h"
#include "OLEDModule.h"

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

ResourceUsage usage;
Button buttonBack(BUTTON_BACK_PIN, 3000);
Button buttonOK(BUTTON_OK_PIN, 2000);
Button buttonNext(BUTTON_NEXT_PIN, 3000);
OLEDModule oledmod(oled, buttonBack, buttonOK, buttonNext);

unsigned long previousDimMillis = 0;
unsigned long dimInterval = 100; // Interval for dimming in milliseconds

void dim()
{
    float potentiometerValue = map(analogRead(POTENTIO_PIN), 0, 4095, 0, 255);
    usage.store(potentiometerValue);
    oledmod.setUsage(usage);
    analogWrite(OUTPUT_PIN, potentiometerValue);
}

void monitor(void *pvParameters)
{
    pinMode(BUZZER_PIN, OUTPUT);
    digitalWrite(BUZZER_PIN, LOW);

    buttonOK.begin();
    buttonNext.begin();
    buttonBack.begin();

    oledmod.begin();

    for (;;)
    {
        oledmod.commonDisplay();
    }
}

void output(void *pvParameters)
{
    pinMode(OUTPUT_PIN, OUTPUT);
    pinMode(POTENTIO_PIN, INPUT);

    for (;;)
    {
        dim();
        vTaskDelay(100);
    }
}

void setup()
{
    Serial.begin(115200);

    xTaskCreate(&output, "Output Thread", 4096, NULL, 1, NULL);
    xTaskCreate(&monitor, "Monitor Thread", 4096, NULL, 2, NULL);
}

void loop()
{
}
