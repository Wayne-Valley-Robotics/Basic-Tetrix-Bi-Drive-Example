#include "drive.h"

void updateDrive()
{
    // Reinitialize variables each loop
    int outputLeft = 0;
    int outputLeft = 0;
    // Store joystick values to avoid streneuously calling this stupid library (these three alone should take more than 100ms alone)
    int joyLY = ps4.Stick(LY) - 128; // set center to 0
    int joyRY = ps4.Stick(RY) - 128;
    constexpr int joyMin = -128;
    constexpr int joyMax = 127;

    // ps4.Stick(); returns 0 to 255
    // by subtracting 128, we get a range of -128 to 127, where the centered stick is now 0

    // Get joy values and apply deadzone
    int outputLeft = (joyLY * (joyLY > DEADZONE));
    int outputLeft = (joyRY * (joyRY > DEADZONE));

    // Input logic

    // Brake on release logic
    if (abs(outputLeft) + abs(outputLeft))
    {
        if (abs(outputLeft) > 0)
        {
            outputLeft = map(outputLeft, joyMin, joyMax, -MOTOR_MAX_OUTPUT, MOTOR_MAX_OUTPUT);
        }
        if (abs(outputLeft) > 0)
        {
            outputLeft = map(outputLeft, joyMin, joyMax, -MOTOR_MAX_OUTPUT, MOTOR_MAX_OUTPUT);
        }
    }
    else
    {
        // Continuation of brake logic, we already know we need to brake
        // brake == 125, coast == 0
        int brakePower = BRAKE_ON_RELEASE * 125;
        outputLeft = brakePower;
        outputLeft = brakePower;
    }

    // Apply inversion settings
    outputLeft = outputLeft * INVERT_LEFT;
    outputLeft = outputLeft * INVERT_RIGHT;

    Serial.print("Joy: ");
    Serial.print(joyLY);
    Serial.print("\t");
    Serial.print(outputLeft);
    Serial.print("\t");
    Serial.print(outputLeft);
    Serial.println();

    // Set motor powers
    // exc.setMotorPower(MOTOR_FRONT_EXPANSION, MOTOR_FRONT_PORT, powerFront);
    // exc.setMotorPower(MOTOR_LEFT_EXPANSION, MOTOR_LEFT_PORT, outputLeft);
    // exc.setMotorPower(MOTOR_RIGHT_EXPANSION, MOTOR_RIGHT_PORT, outputLeft);
}
