#define POTENTIOMETER_INPUT A0
#define LED_OUTPUT 2
#define PUSH_INPUT 5

#define BASE_PERIOD 25.0
#define DEVIATION_COMPARATOR 10.0

#define POTENSIOMETER_MIN_SCALE 1
#define POTENSIOMETER_MAX_SCALE 1023
#define POTENSIOMETER_MIN_RESCALE -255.75
#define POTENSIOMETER_MAX_RESCALE 767.25

int counter = 0;

void setup()
{
    Serial.begin(9600);

    pinMode(LED_OUTPUT, OUTPUT);
    pinMode(PUSH_INPUT, INPUT_PULLUP);
    pinMode(POTENTIOMETER_INPUT, INPUT);
}

void loop()
{
    float deviation = variableDeviation();
    float period = BASE_PERIOD;
    if (isDeviceOn())
    {
        pulseWidthModulation(period, deviation);
        return;
    };
    delay(100);
}

bool isDeviceOn()
{
    return digitalRead(PUSH_INPUT) == LOW;
}

float variableDeviation()
{
    int input = analogRead(POTENTIOMETER_INPUT);
    input = map(input, POTENSIOMETER_MIN_SCALE, POTENSIOMETER_MAX_SCALE, POTENSIOMETER_MIN_RESCALE, POTENSIOMETER_MAX_RESCALE);
    return input / DEVIATION_COMPARATOR;
}

void pulseWidthModulation(float period, float deviation)
{
    float highDuration = constrain(period + deviation, 0, 1000);
    digitalWrite(LED_OUTPUT, HIGH);
    delay(highDuration);

    float lowDuration = constrain(period - deviation, 0, 1000);
    digitalWrite(LED_OUTPUT, LOW);
    delay(lowDuration);

    traceMetrics(highDuration, lowDuration);
}

void traceMetrics(float highDuration, float lowDuration)
{
    Serial.print(" duty cycle: ");
    Serial.print(100 * highDuration / (lowDuration + highDuration));
    Serial.print("%");
    Serial.print(" high: ");
    Serial.print(highDuration);
    Serial.print("ms ");
    Serial.print(1000.0 / highDuration);
    Serial.print("hz");
    Serial.print(" low: ");
    Serial.print(lowDuration);
    Serial.print("ms ");
    Serial.print(1000.0 / lowDuration);
    Serial.print("hz");
    Serial.println("");
}