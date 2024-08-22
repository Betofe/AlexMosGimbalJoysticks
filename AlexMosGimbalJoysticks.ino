/*
 Name:		AlexMosGimbalJoysticks.ino
 Created:	6/6/2023 11:38:55 AM
 Author:	Imami Joel Betofe
*/

#include "GimbalSettings.h"
#include "Globals.h"

Gimbal gimbal;
// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(DEBUG_BAUD_RATE);
	gimbal.init();
}

// the loop function runs over and over again until power down or reset
void loop() {
	gimbal.run();
}