#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OUTPUT_PIN 2
#define POTENTIO_PIN 4
#define BUTTON_BACK_PIN 16
#define BUTTON_OK_PIN 17
#define BUTTON_NEXT_PIN 18
#define BUZZER_PIN 15
#define SCREEN_WIDTH 128 // OLED width,  in pixels
#define SCREEN_HEIGHT 64 // OLED height, in pixels
#define I2C_ADDRESS 0x3C // I2C address, depends on specs

#define VCC 3.3
#define EXPECTED_VOUT 2.0
#define INPUT_RANGE 255.0
#define EXPECTED_IOUT 0.008

unsigned long previousDimMillis = 0;
unsigned long dimInterval = 100; // Interval for dimming in milliseconds

Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

class Button
{                                             // a simple class for buttons based on the "Debounce" example
    const byte buttonPin;                     // the GPIO / pin for the button
    static constexpr byte debounceDelay = 30; // the debounce time; increase if the output flickers. Static because we only need one value for all buttons
    const bool active;                        // is the pin active HIGH or active LOW (will also activate the pullups!)
    bool lastButtonState = HIGH;              // the previous reading from the input pin
    byte lastDebounceTime = 0;                // the last time the output pin was toggled - we check only ONE byte, so I didn't mess around with unsigned long

public:
    /**
       \brief constructor for a button

       The constructor takes the GPIO as parameter.
       If you omit the second parameter, the library will activate the internal pullup resistor
       and the button should connect to GND.
       If you set the second parameter to HIGH, the button is active HIGH.
       The button should connect to VCC.
       The internal pullups will not be used but you will need an external pulldown resistor.

       \param attachTo the GPIO for the button
       \param active LOW (default) - if button connects to GND, HIGH if button connects to VCC
    */
    Button(byte attachTo, bool active = LOW) : buttonPin(attachTo), active(active) {}

    /**
       \brief set the pin to the proper state

       Call this function in your setup().
       The pinMode will be set according to your constructor.
    */
    void begin()
    {
        if (active == LOW)
            pinMode(buttonPin, INPUT);
        else
            pinMode(buttonPin, INPUT_PULLUP);
    }

    /**
        \brief indicate if button was pressed since last call

        @return HIGH if button was pressed since last call - debounce
    */
    bool wasPressed()
    {
        bool buttonState = LOW; // the current reading from the input pin
        byte reading = LOW;     // "translated" state of button LOW = released, HIGH = pressed, despite the electrical state of the input pint
        if (digitalRead(buttonPin) == active)
            reading = HIGH;                                         // if we are using INPUT_PULLUP we are checking invers to LOW Pin
        if (((millis() & 0xFF) - lastDebounceTime) > debounceDelay) // If the switch changed, AFTER any pressing or noise
        {
            if (reading != lastButtonState && lastButtonState == LOW) // If there was a change and and last state was LOW (= released)
            {
                buttonState = HIGH;
            }
            lastDebounceTime = millis() & 0xFF;
            lastButtonState = reading;
        }
        return buttonState;
    }
};

Button buttonBack{BUTTON_BACK_PIN};
Button buttonOK{BUTTON_OK_PIN};
Button buttonNext{BUTTON_NEXT_PIN};

void setup()
{
    Serial.begin(115200);

    pinMode(OUTPUT_PIN, OUTPUT);
    pinMode(POTENTIO_PIN, INPUT);

    pinMode(BUZZER_PIN, OUTPUT);
    digitalWrite(BUZZER_PIN, LOW);

    buttonBack.begin();

    if (!oled.begin(SSD1306_SWITCHCAPVCC, I2C_ADDRESS))
    {
        Serial.println(F("Failed to start SSD1306 OLED"));
        while (1)
            ;
    }
}

void loop()
{
    unsigned long currentMillis = millis();

    if (currentMillis - previousDimMillis >= dimInterval)
    {
        dim();
        previousDimMillis = currentMillis;
    }

    receiveInput();
}

void receiveInput()
{
    if (buttonBack.wasPressed())
    {
        beep(3000);
    }
    if (buttonOK.wasPressed())
    {
        beep(2000);
    }
    if (buttonNext.wasPressed())
    {
        beep(3000);
    }
}

void beep(long freq)
{
    tone(BUZZER_PIN, freq, 125);
}

void dim()
{
    float potentiometerValue = map(analogRead(POTENTIO_PIN), 0, 4095, 0, 255);
    analogWrite(OUTPUT_PIN, measure(potentiometerValue));
}

float measure(float input)
{
    float voltage = input / INPUT_RANGE * VCC;
    float resistance = (VCC - EXPECTED_VOUT) / EXPECTED_IOUT;
    float current = voltage / resistance;
    float power = voltage * current;

    displayOLEDData(power, current, resistance, voltage);
    return input;
}

void displayOLEDData(float power, float current, float resistance, float voltage)
{
    oled.clearDisplay();
    oled.setTextSize(1);
    oled.setTextColor(WHITE);
    oled.setCursor(0, 2);
    oled.print("Power (W): ");
    oled.println(power);
    oled.print("Current (mA): ");
    oled.println(current * 1000);
    oled.print("Resistance (Ohm): ");
    oled.println(resistance);
    oled.print("Voltage (V): ");
    oled.println(voltage);
    oled.display();
}
