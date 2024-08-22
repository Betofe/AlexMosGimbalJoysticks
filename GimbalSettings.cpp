// 
// 
// 

#include "GimbalSettings.h"
#include "Globals.h"
#include "MavlinkSettings.h"

MavlinkConnection mavlink;

void Gimbal::init() {
	mavlink.init();

	ledcAttachPin(PITCH_PIN, PITCH_CHANNEL);
	ledcAttachPin(YAW_PIN, YAW_CHANNEL);
	ledcAttachPin(ROLL_PIN, ROLL_CHANNEL);

	ledcSetup(PITCH_CHANNEL, FREQUENCY, RESOLUTION);
	ledcSetup(YAW_CHANNEL, FREQUENCY, RESOLUTION);
	ledcSetup(ROLL_CHANNEL, FREQUENCY, RESOLUTION);

	pitch_pwm = 0;
	roll_pwm = 0;
	yaw_pwm = 0;

}

void Gimbal::map_pwm() {
	pitch_pwm = map(axes_pwms[PITCH_INDEX], CHANNEL_MIN, CHANNEL_MAX, MIN_PWM, MAX_PWM);
	roll_pwm = map(axes_pwms[ROLL_INDEX], CHANNEL_MIN, CHANNEL_MAX, MIN_PWM, MAX_PWM);
	yaw_pwm = map(axes_pwms[YAW_INDEX], CHANNEL_MIN, CHANNEL_MAX, MIN_PWM, MAX_PWM);

}

void Gimbal::run() {
	mavlink.run();
	map_pwm();
	Serial.println(pitch_pwm);
	//Serial.println(roll_pwm);
	//Serial.println(yaw_pwm);
	ledcWrite(PITCH_CHANNEL, pitch_pwm);
	ledcWrite(ROLL_CHANNEL, roll_pwm);
	ledcWrite(YAW_CHANNEL, yaw_pwm);

}