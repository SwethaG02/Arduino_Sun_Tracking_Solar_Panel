#include <Servo.h>

// LDR analog input pins
const int LDR_LEFT  = A0;
const int LDR_RIGHT = A1;

// Servo signal pin
const int SERVO_PIN = 9;

// Tracking configuration
const int INITIAL_ANGLE = 90;
const int MIN_ANGLE = 10;
const int MAX_ANGLE = 170;
const int TOLERANCE = 40;
const int MOVE_STEP = 1;

Servo trackingServo;

int servoAngle = INITIAL_ANGLE;

void setup()
{
    Serial.begin(9600);

    trackingServo.attach(SERVO_PIN);
    trackingServo.write(servoAngle);

    delay(500);

    Serial.println("Arduino Sun Tracking System");
    Serial.println("LDR Left | LDR Right | Servo Angle");
}

void loop()
{
    int leftValue = analogRead(LDR_LEFT);
    int rightValue = analogRead(LDR_RIGHT);

    int difference = leftValue - rightValue;

    // Move toward the brighter side
    if (difference > TOLERANCE)
    {
        servoAngle += MOVE_STEP;
    }
    else if (difference < -TOLERANCE)
    {
        servoAngle -= MOVE_STEP;
    }

    // Prevent the servo from exceeding its limits
    servoAngle = constrain(servoAngle, MIN_ANGLE, MAX_ANGLE);

    trackingServo.write(servoAngle);

    // Print sensor readings for debugging
    Serial.print(leftValue);
    Serial.print(" | ");
    Serial.print(rightValue);
    Serial.print(" | ");
    Serial.println(servoAngle);

    delay(50);
}
