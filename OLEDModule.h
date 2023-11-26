#ifndef OLED_MODULE_H
#define OLED_MODULE_H

#include <vector>

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "ResourceUsage.h"
#include "Button.h"
#include "Output.h"

class OLEDModule
{
public:
    OLEDModule(Output &output, Adafruit_SSD1306 &oled, Button &btnBack, Button &btnOK, Button &btnNext, ResourceUsage usage);

    void begin();
    void shutDown();
    void reboot();
    void displayLogo();
    void error(String message);
    void commonDisplay();
    void displayMenu();
    void handleMenu();
    void handleLogo();
    void handleResource();
    void handleBattery();
    void handleReboot();
    void handleSettings();
    void displayBattery(int battery);
    void displayResources();
    void displaySettings(int power);
    void setUsage(ResourceUsage usage);

    static const char batteryIconLowBitmap[];
    static const char batteryIconMediumBitmap[];
    static const char batteryIconHighBitmap[];
    static const char batteryIconFullBitmap[];

private:
    int selectedOption;
    String selectedPage;
    ResourceUsage ru;
    Adafruit_SSD1306 &oled;
    Output &output;
    std::vector<String> menuOptions;
    Button &buttonBack;
    Button &buttonOK;
    Button &buttonNext;
    ResourceUsage usage;
};

#endif // OLED_MODULE_H
