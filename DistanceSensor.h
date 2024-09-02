#ifndef DistanceSensor_h

#define DistanceSensor_h

#include "Arduino.h"

/**
 * DistanceSensor.h
 *
 * This class is responsible for controlling the distance sensor.
 * @see DistanceSensor.cpp
 * @method readUltrasonicDistance() - Reads the distance in ultrasonic pulses.
 * @method readMetricSystemDistance() - Reads the distance in centimeters.
 */
class DistanceSensor {
  public:
    DistanceSensor(int assignedTriggerPin, int assignedEchoPin);
    long readUltrasonicDistance();
    float readMetricSystemDistance();
  private:
    int _triggerPin;
    int _echoPin;
};

#endif