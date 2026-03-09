#include "drive.h"

void updateDrive()
{
    // Reinitialize variables each loop
    int outputLeft = 0;
    int outputRight = 0;
    // Store joystick values to avoid streneuously polling the motor expansions
    int joyLY = ps4.Stick(LY) - 128; // set center to 0
    int joyRY = ps4.Stick(RY) - 128;
    constexpr int joyMin = -128;
    constexpr int joyMax = 127;

    // ps4.Stick(); returns 0 to 255
    // by subtracting 128, we get a range of -128 to 127, where the centered stick is now 0

    // Get joy values and apply deadzone
    outputLeft = (joyLY * (abs(joyLY) > DEADZONE));
    outputRight = (joyRY * (abs(joyRY) > DEADZONE));

    // Input logic

    // Brake on release logic
    if ((abs(outputLeft) + abs(outputRight)) > 0)
    {
        if (abs(outputLeft) > 0)
        {
            outputLeft = map(outputLeft, joyMin, joyMax, -MOTOR_MAX_OUTPUT, MOTOR_MAX_OUTPUT);
        }
        if (abs(outputRight) > 0)
        {
            outputRight = map(outputRight, joyMin, joyMax, -MOTOR_MAX_OUTPUT, MOTOR_MAX_OUTPUT);
        }
    }
    else
    {
        // Continuation of brake logic, we already know we need to brake
        // brake == 125, coast == 0
        int brakePower = BRAKE_ON_RELEASE * 125;
        outputLeft = brakePower;
        outputRight = brakePower;
    }

    // Apply inversion settings
    outputLeft = outputLeft * INVERT_LEFT;
    outputRight = outputRight * INVERT_RIGHT;

    Serial.print("JoyLY: ");
    Serial.print(joyLY);
    Serial.print("\t");
    Serial.print("JoyRY: ");
    Serial.print(joyRY);
    Serial.print("\t");
    Serial.print(outputLeft);
    Serial.print("\t");
    Serial.print(outputRight);
    Serial.println();

    // Set motor powers
    exc.setMotorPower(MOTOR_LEFT_EXPANSION, MOTOR_LEFT_PORT, outputLeft);
    exc.setMotorPower(MOTOR_RIGHT_EXPANSION, MOTOR_RIGHT_PORT, outputRight);
}
