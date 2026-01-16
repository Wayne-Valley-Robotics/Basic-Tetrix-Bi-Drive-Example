#pragma once
#include <Arduino.h>
#include <PRIZM.h>
#include <TELEOP.h>

extern PRIZM prizm;
extern EXPANSION exc;
extern PS4 ps4;

// Constants
constexpr int DEADZONE = 8;
constexpr int MOTOR_MAX_OUTPUT = 100;
constexpr bool BRAKE_ON_RELEASE = true;

constexpr int MOTOR_LEFT_EXPANSION = 0;
constexpr int MOTOR_LEFT_PORT = 1;

constexpr int MOTOR_RIGHT_EXPANSION =0;
constexpr int MOTOR_RIGHT_PORT = 2;

// 1 or -1 (this value is used as a multiplier)
constexpr int INVERT_LEFT = -1;
constexpr int INVERT_RIGHT = -1;

void updateDrive();
