// GimbalSettings.h

#pragma once

#include <Arduino.h>

#define PITCH_PIN 26
#define YAW_PIN 13
#define ROLL_PIN 14

#define FREQUENCY 400
#define PITCH_CHANNEL 0
#define YAW_CHANNEL 1
#define ROLL_CHANNEL 2
#define RESOLUTION 8

#define MAX_PWM 175
#define MIN_PWM 73


class Gimbal {
private:
	uint16_t pitch_pwm;
	uint16_t roll_pwm;
	uint16_t yaw_pwm;
public:
	void init();
	void map_pwm();
	void run();

};