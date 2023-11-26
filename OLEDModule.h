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
    OLEDModule(Output &output, Adafruit_SSD1306 &oled, Button &btnBack, Button &btnOK, Button &btnNext);
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
    void displayBattery(int battery);
    void displayResources();
    void setUsage(ResourceUsage usage);
    static const char batteryIconLowBitmap[];
    static const char batteryIconMediumBitmap[];
    static const char batteryIconHighBitmap[];
    static const char batteryIconFullBitmap[];

private:
    int selectedOption;
    String selectedPage;
    ResourceUsage ru;
    std::vector<String> menuOptions;
    Adafruit_SSD1306 &oled;
    Button &buttonBack;
    Button &buttonOK;
    Button &buttonNext;
    Output &output;
};

#endif // OLED_MODULE_H
