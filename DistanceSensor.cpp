#include <Arduino.h>
#include "DistanceSensor.h"

/**
 * DistanceSensor.cpp
 *
 * This class is responsible for controlling the distance sensor.
 * @see DistanceSensor.h
 * @method readUltrasonicDistance() - Reads the distance in ultrasonic pulses.
 * @method readMetricSystemDistance() - Reads the distance in centimeters.
 */

/**
 * Constructor
 * @param assignedTriggerPin - The trigger pin to assign.
 * @param assignedEchoPin - The echo pin to assign.
 */
DistanceSensor::DistanceSensor(int assignedTriggerPin, int assignedEchoPin) {
  _triggerPin = assignedTriggerPin;
  _echoPin = assignedEchoPin;
}

/**
 * Reads the distance in ultrasonic pulses.
 * @return The distance in ultrasonic pulses.
 */
long DistanceSensor::readUltrasonicDistance() {
  // Setup Trigger Pin
  pinMode(_triggerPin, OUTPUT);
  // Clear Trigger Pin
  digitalWrite(_triggerPin, LOW);
  // Wait
  delayMicroseconds(2);
  // Activate Trigger Pin during 10 microseconds
  digitalWrite(_triggerPin, HIGH);
  delayMicroseconds(10);
  // Deactivate Trigger Pin
  digitalWrite(_triggerPin, LOW);
  // Setup Echo Pin
  pinMode(_echoPin, INPUT);
  // Return Pulse value
  return pulseIn(_echoPin, HIGH);
}

/**
 * Reads the distance in centimeters.
 * @return The distance in centimeters.
 */
float DistanceSensor::readMetricSystemDistance() {
  // Convert Ultrasonic Pulse Reading into Centimeters
  return readUltrasonicDistance()/58;
}
