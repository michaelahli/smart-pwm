#include "OLEDModule.h"

extern Adafruit_SSD1306 oled;

const char OLEDModule::batteryIconLowBitmap[] = {
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xe0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x01, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xe0, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xe0, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x60,
    0x38, 0x00, 0xff, 0xff, 0xff, 0xfc, 0x60, 0x38, 0x00, 0xff, 0xff, 0xff, 0xfc, 0x60, 0x38, 0x00,
    0xff, 0xff, 0xff, 0xfc, 0x60, 0x38, 0x00, 0xff, 0xff, 0xff, 0xfc, 0x60, 0x38, 0x00, 0xff, 0xff,
    0xff, 0xfc, 0x60, 0x38, 0x00, 0xff, 0xff, 0xff, 0xfc, 0x20, 0x38, 0x00, 0xff, 0xff, 0xff, 0xfc,
    0x00, 0x38, 0x00, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x38, 0x00, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x38,
    0x00, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x38, 0x00, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x38, 0x00, 0xff,
    0xff, 0xff, 0xfc, 0x00, 0x38, 0x00, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x38, 0x00, 0xff, 0xff, 0xff,
    0xfc, 0x20, 0x38, 0x00, 0xff, 0xff, 0xff, 0xfc, 0x60, 0x38, 0x00, 0xff, 0xff, 0xff, 0xfc, 0x60,
    0x38, 0x00, 0xff, 0xff, 0xff, 0xfc, 0x60, 0x38, 0x00, 0xff, 0xff, 0xff, 0xfc, 0x60, 0x38, 0x00,
    0xff, 0xff, 0xff, 0xfc, 0x60, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x60, 0x1f, 0xff, 0xff, 0xff,
    0xff, 0xfc, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x01,
    0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xe0};

const char OLEDModule::batteryIconMediumBitmap[] = {
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xe0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x01, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xe0, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xe0, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x60,
    0x38, 0x00, 0x00, 0x7f, 0xff, 0xfc, 0x60, 0x38, 0x00, 0x00, 0x3f, 0xff, 0xfc, 0x60, 0x38, 0x00,
    0x00, 0x3f, 0xff, 0xfc, 0x60, 0x38, 0x00, 0x00, 0x7f, 0xff, 0xfc, 0x60, 0x38, 0x00, 0x00, 0x3f,
    0xff, 0xfc, 0x60, 0x38, 0x00, 0x00, 0x7f, 0xff, 0xfc, 0x20, 0x38, 0x00, 0x00, 0x3f, 0xff, 0xfc,
    0x00, 0x38, 0x00, 0x00, 0x3f, 0xff, 0xfc, 0x00, 0x38, 0x00, 0x00, 0x3f, 0xff, 0xfc, 0x00, 0x38,
    0x00, 0x00, 0x3f, 0xff, 0xfc, 0x00, 0x38, 0x00, 0x00, 0x3f, 0xff, 0xfc, 0x00, 0x38, 0x00, 0x00,
    0x3f, 0xff, 0xfc, 0x00, 0x38, 0x00, 0x00, 0x3f, 0xff, 0xfc, 0x00, 0x38, 0x00, 0x00, 0x3f, 0xff,
    0xfc, 0x20, 0x38, 0x00, 0x00, 0x3f, 0xff, 0xfc, 0x60, 0x38, 0x00, 0x00, 0x3f, 0xff, 0xfc, 0x60,
    0x38, 0x00, 0x00, 0x7f, 0xff, 0xfc, 0x60, 0x38, 0x00, 0x00, 0x3f, 0xff, 0xfc, 0x60, 0x38, 0x00,
    0x00, 0x7f, 0xff, 0xfc, 0x60, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x60, 0x1f, 0xff, 0xff, 0xff,
    0xff, 0xfc, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x01,
    0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xe0};

const char OLEDModule::batteryIconHighBitmap[] = {
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xe0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x01, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xe0, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xe0, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x60,
    0x38, 0x00, 0x00, 0x00, 0x1f, 0xfc, 0x60, 0x38, 0x00, 0x00, 0x00, 0x1f, 0xfc, 0x60, 0x38, 0x00,
    0x00, 0x00, 0x1f, 0xfc, 0x60, 0x38, 0x00, 0x00, 0x00, 0x1f, 0xfc, 0x60, 0x38, 0x00, 0x00, 0x00,
    0x1f, 0xfc, 0x60, 0x38, 0x00, 0x00, 0x00, 0x1f, 0xfc, 0x20, 0x38, 0x00, 0x00, 0x00, 0x1f, 0xfc,
    0x00, 0x38, 0x00, 0x00, 0x00, 0x1f, 0xfc, 0x00, 0x38, 0x00, 0x00, 0x00, 0x1f, 0xfc, 0x00, 0x38,
    0x00, 0x00, 0x00, 0x1f, 0xfc, 0x00, 0x38, 0x00, 0x00, 0x00, 0x1f, 0xfc, 0x00, 0x38, 0x00, 0x00,
    0x00, 0x1f, 0xfc, 0x00, 0x38, 0x00, 0x00, 0x00, 0x1f, 0xfc, 0x00, 0x38, 0x00, 0x00, 0x00, 0x1f,
    0xfc, 0x20, 0x38, 0x00, 0x00, 0x00, 0x1f, 0xfc, 0x60, 0x38, 0x00, 0x00, 0x00, 0x1f, 0xfc, 0x60,
    0x38, 0x00, 0x00, 0x00, 0x1f, 0xfc, 0x60, 0x38, 0x00, 0x00, 0x00, 0x1f, 0xfc, 0x60, 0x38, 0x00,
    0x00, 0x00, 0x1f, 0xfc, 0x60, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x60, 0x1f, 0xff, 0xff, 0xff,
    0xff, 0xfc, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x01,
    0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xe0};

const char OLEDModule::batteryIconFullBitmap[] = {
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xe0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x01, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xe0, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xe0, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x60,
    0x38, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x60, 0x38, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x60, 0x38, 0x00,
    0x00, 0x00, 0x00, 0x0c, 0x60, 0x38, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x60, 0x38, 0x00, 0x00, 0x00,
    0x00, 0x0c, 0x60, 0x38, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x20, 0x38, 0x00, 0x00, 0x00, 0x00, 0x0c,
    0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x38,
    0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x38, 0x00, 0x00,
    0x00, 0x00, 0x0c, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00,
    0x0c, 0x20, 0x38, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x60, 0x38, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x60,
    0x38, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x60, 0x38, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x60, 0x38, 0x00,
    0x00, 0x00, 0x00, 0x0c, 0x60, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x60, 0x1f, 0xff, 0xff, 0xff,
    0xff, 0xfc, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x01,
    0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xe0};

OLEDModule::OLEDModule(Output &output, Adafruit_SSD1306 &oled, Button &btnBack, Button &btnOK, Button &btnNext, ResourceUsage usage)
    : output(output), oled(oled), buttonBack(btnBack), buttonOK(btnOK), buttonNext(btnNext), usage(usage)
{
    menuOptions = {"Settings", "Shut Down", "Resource Usages", "Check Battery"};
}

void OLEDModule::begin()
{
    if (!oled.begin(SSD1306_SWITCHCAPVCC, I2C_ADDRESS))
    {
        Serial.println(F("Failed to start SSD1306 OLED"));
        while (1)
            ;
    }
    reboot();
}

void OLEDModule::displayLogo()
{
    selectedPage = "Logo";

    const unsigned char logoBitmap[] PROGMEM = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf9, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x06, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x03, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x80,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00,
        0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00,
        0xe0, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0,
        0x21, 0xe0, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x80, 0x00, 0xe0, 0x30, 0x1f, 0xf9, 0xfc, 0x00, 0xc0, 0x61, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x80, 0x06, 0x00, 0x10, 0x1f, 0xf9, 0xff, 0x01, 0xe0, 0x61, 0x80, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x01, 0x00, 0x0f, 0x00, 0x10, 0x01, 0x81, 0x83, 0x81, 0xe0, 0x61, 0x80, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x01, 0x00, 0x07, 0x00, 0x18, 0x01, 0x81, 0x81, 0x83, 0xf0, 0x61, 0x80, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x40, 0x08, 0x01, 0x81, 0x81, 0x83, 0x30, 0x61, 0x80, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x60, 0xe0, 0x08, 0x01, 0x81, 0x81, 0x83, 0x30, 0x61, 0x80,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0xf0, 0xe0, 0x08, 0x01, 0x81, 0xc7, 0x86, 0x18, 0x61,
        0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x70, 0x40, 0x08, 0x01, 0x81, 0xff, 0x06, 0x18,
        0x61, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x06, 0x40, 0x08, 0x01, 0x81, 0xee, 0x0f,
        0xfc, 0x61, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x0f, 0x40, 0x18, 0x01, 0x81, 0x86,
        0x0f, 0xfc, 0x61, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x06, 0x40, 0x10, 0x01, 0x81,
        0x87, 0x1c, 0x0e, 0x61, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x40, 0x10, 0x01,
        0x81, 0x83, 0x98, 0x06, 0x61, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x60, 0x40, 0x30,
        0x1f, 0xff, 0x81, 0xf0, 0x07, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xff, 0xc0,
        0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x60,
        0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20,
        0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x30, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x18, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x06, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x03, 0x80, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

    oled.clearDisplay();

    int logoWidth = 135;
    int logoHeight = 135;

    int centerX = (SCREEN_WIDTH - logoWidth) / 2;
    int centerY = (SCREEN_HEIGHT - logoHeight) / 2;

    oled.drawBitmap(centerX, centerY, logoBitmap, logoWidth, logoHeight, 1);
    oled.display();
}

void OLEDModule::shutDown()
{
    displayLogo();
    vTaskDelay(2000);

    selectedPage = "None";

    oled.clearDisplay();
    oled.display();
    output.disconnect();
}

void OLEDModule::reboot()
{
    output.connect();
    displayLogo();
    vTaskDelay(2000);
    displayMenu();
}

void OLEDModule::error(String message)
{
    oled.clearDisplay();
    oled.println(message);
}

void OLEDModule::commonDisplay()
{
    if (selectedPage == "Logo")
    {
        handleLogo();
    };
    if (selectedPage == "Menu")
    {
        handleMenu();
    };
    if (selectedPage == "Resource")
    {
        handleResource();
    };
    if (selectedPage == "Battery")
    {
        handleBattery();
    };
    if (selectedPage == "None")
    {
        handleReboot();
    };
    if (selectedPage == "Settings")
    {
        handleSettings();
    };
}

void OLEDModule::displayMenu()
{
    selectedPage = "Menu";

    oled.clearDisplay();
    oled.setTextSize(1);
    oled.setTextColor(WHITE);
    oled.setCursor(0, 2);

    for (int i = 0; i < menuOptions.size(); i++)
    {
        if (i == selectedOption)
        {
            oled.print("> ");
        }
        else
        {
            oled.print("  ");
        }
        oled.println(menuOptions[i]);
    }

    oled.display();
}

void OLEDModule::handleReboot()
{
    if (!buttonOK.wasPressed())
    {
        return;
    }
    if (output.state())
    {
        return;
    }
    reboot();
}

void OLEDModule::displaySettings(int power)
{
    selectedPage = "Settings";

    oled.clearDisplay();

    oled.setTextSize(2);
    oled.setTextColor(WHITE);

    int screenWidth = oled.width();
    int screenHeight = oled.height();

    int textSize = 3;

    int textWidth = textSize * 6;
    int textHeight = textSize * 8;
    int xPos = (screenWidth - textWidth) / 2;
    int yPos = (screenHeight - textHeight) / 2;

    oled.setCursor(xPos, yPos);

    oled.println(String(power) + "W");

    oled.display();
}

void OLEDModule::handleSettings()
{
    int power = output.getPower();
    if (buttonBack.wasPressed())
    {
        if (power <= 0)
        {
            return;
        }
        power = power - 1;
        output.setPower(power);
        displaySettings(power);
    }
    if (buttonOK.wasPressed())
    {
        displayMenu();
    }
    if (buttonNext.wasPressed())
    {
        if (power >= usage.getMaxPower())
        {
            return;
        }
        power = power + 1;
        output.setPower(power);
        displaySettings(power);
    }
}

void OLEDModule::handleMenu()
{
    if (buttonBack.wasPressed())
    {
        selectedOption = (selectedOption - 1 + menuOptions.size()) % menuOptions.size();
        displayMenu();
    }
    if (buttonOK.wasPressed())
    {
        switch (selectedOption)
        {
        case 0:
            displaySettings(output.getPower());
            break;
        case 1:
            shutDown();
            break;
        case 2:
            displayResources();
            break;
        case 3:
            displayBattery(40);
            break;
        default:
            error("unknown selected menu: " + String(selectedOption));
        }
    }
    if (buttonNext.wasPressed())
    {
        selectedOption = (selectedOption + 1) % menuOptions.size();
        displayMenu();
    }
}

void OLEDModule::handleLogo()
{
    if (buttonBack.wasPressed())
    {
    }
    if (buttonOK.wasPressed())
    {
        displayMenu();
    }
    if (buttonNext.wasPressed())
    {
    }
}

void OLEDModule::handleResource()
{
    if (buttonBack.wasPressed())
    {
        displayMenu();
    }
    if (buttonOK.wasPressed())
    {
    }
    if (buttonNext.wasPressed())
    {
    }
}

void OLEDModule::handleBattery()
{
    if (buttonBack.wasPressed())
    {
        displayMenu();
    }
    if (buttonOK.wasPressed())
    {
    }
    if (buttonNext.wasPressed())
    {
    }
}

void OLEDModule::displayBattery(int battery)
{
    selectedPage = "Battery";

    oled.clearDisplay();
    oled.setTextSize(1);
    oled.setTextColor(WHITE);

    const uint8_t *batteryIcon;
    if (battery < 25)
    {
        batteryIcon = reinterpret_cast<const uint8_t *>(batteryIconLowBitmap);
    }
    else if (battery < 50)
    {
        batteryIcon = reinterpret_cast<const uint8_t *>(batteryIconMediumBitmap);
    }
    else if (battery < 75)
    {
        batteryIcon = reinterpret_cast<const uint8_t *>(batteryIconHighBitmap);
    }
    else
    {
        batteryIcon = reinterpret_cast<const uint8_t *>(batteryIconFullBitmap);
    }

    int iconWidth = 51;
    int iconHeight = 51;

    int centerX = (SCREEN_WIDTH - iconWidth) / 2;

    oled.drawBitmap(centerX, 0, batteryIcon, iconWidth, iconHeight, 1);

    String message = "Battery: " + String(battery) + "%";
    int textCharLength = message.length();
    oled.setCursor(centerX - textCharLength, 1 + iconHeight);
    oled.println(message);

    oled.display();
}

void OLEDModule::displayResources()
{
    selectedPage = "Resource";

    oled.clearDisplay();
    oled.setTextSize(1);
    oled.setTextColor(WHITE);
    oled.setCursor(0, 2);

    oled.print("Power (W): ");
    oled.println(ru.getPower());
    oled.print("Current (mA): ");
    oled.println(ru.getCurrent() * 1000);
    oled.print("Resistance (Ohm): ");
    oled.println(ru.getResistance());
    oled.print("Voltage (V): ");
    oled.println(ru.getVoltage());

    oled.display();
}

void OLEDModule::setUsage(ResourceUsage usage)
{
    ru = usage;
}
