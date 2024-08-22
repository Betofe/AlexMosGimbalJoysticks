#pragma once

#include "Arduino.h"

#define DEBUG_BAUD_RATE 9600

#define PITCH_INDEX 0
#define ROLL_INDEX 1
#define YAW_INDEX 2

extern uint16_t axes_pwms[3];