#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED width,  in pixels
#define SCREEN_HEIGHT 64 // OLED height, in pixels
#define I2C_ADDRESS 0x3C
#define OUTPUT_PIN 2
#define VCC 3.3
#define EXPECTED_VOUT 2.0
#define INPUT_RANGE 255.0
#define EXPECTED_IOUT 0.008

// create an OLED display object connected to I2C
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup()
{
    Serial.begin(115200);

    pinMode(OUTPUT_PIN, OUTPUT);
    // initialize OLED display with I2C address 0x3C
    if (!oled.begin(SSD1306_SWITCHCAPVCC, I2C_ADDRESS))
    {
        Serial.println(F("failed to start SSD1306 OLED"));
        while (1)
            ;
    }

    delay(2000); // wait two seconds for initializing
}

void loop()
{
    dim();
}

void dim()
{
    analogWrite(OUTPUT_PIN, measure(12.0));  // Dim the LED to half brightness
    delay(1000);                             // Wait for 1 second
    analogWrite(OUTPUT_PIN, measure(255.0)); // Turn the LED on full brightness
    delay(1000);                             // Wait for 1 second
}

float measure(float input)
{
    // Measure the voltage across the LED
    float voltage = input / INPUT_RANGE * VCC;

    float resistance = (VCC - EXPECTED_VOUT) / EXPECTED_IOUT;
    // Measure the current flowing through the LED
    float current = voltage / resistance;

    // Calculate the power output of the LED
    float power = voltage * current;

    displayoled(power, current, resistance, voltage);
    return input;
}

void displayoled(float power, float current, float resistance, float voltage)
{
    oled.clearDisplay(); // clear display

    oled.setTextSize(0.5);    // set text size
    oled.setTextColor(WHITE); // set text color
    oled.setCursor(0, 2);     // set position to display (x,y)
    oled.print("Power (W): ");
    oled.println(power);
    oled.print("Current (mA): ");
    oled.println(current * 1000);
    oled.print("Resistance (Ohm): ");
    oled.println(resistance);
    oled.print("Voltage (V): ");
    oled.println(voltage);
    oled.display(); // display on OLED
}
