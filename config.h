#ifndef CONFIG_H
#define CONFIG_H

#define OUTPUT_PIN 2
#define POTENTIO_PIN 4
#define BUTTON_BACK_PIN 16
#define BUTTON_OK_PIN 17
#define BUTTON_NEXT_PIN 18
#define BUZZER_PIN 15
#define SCREEN_WIDTH 128 // OLED width,  in pixels
#define SCREEN_HEIGHT 64 // OLED height, in pixels
#define I2C_ADDRESS 0x3C // I2C address, depends on specs

#define VCC 9
#define EXPECTED_VOUT 2.0
#define INPUT_RANGE 255.0
#define EXPECTED_IOUT 0.008

#endif // CONFIG_H
