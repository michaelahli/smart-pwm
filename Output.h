#ifndef OUTPUT_H
#define OUTPUT_H

class Output
{
public:
    Output(int outputPin, int potentiometerPin);

    void pwm();
    void disconnect();
    void connect();
    bool state();

private:
    int outputPin;
    int potentiometerPin;
    bool connected;
};

#endif // OUTPUT_H
