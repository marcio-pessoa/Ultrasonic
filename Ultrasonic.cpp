/* Ultrasonic.cpp - Ultrasonic Distance Measuring Sensor Library
 * 
 */

#include "Arduino.h"
#include "Ultrasonic.h"

/* Ultrasonic
 * 
 * Description
 *   Ultrasonic distance measuring sensor.
 * 
 *   Ultrasonic ()
 * 
 * Parameters
 *   none
 * 
 * Returns
 *   void
 */
Ultrasonic::Ultrasonic() {
}

/* attach
 * 
 * Description
 *   Attach sensor.
 * 
 *   sensor.attach(byte trigger_pin, byte echo_pin)
 * 
 * Parameters
 *   trigger_pin: Arduino pin connected to trigger sensor pin
 *   echo_pin: Arduino ping connected to echo sensor pin
 * 
 * Returns
 *   void
 */
void Ultrasonic::attach(byte trigger_pin, byte echo_pin) {
  pinMode(trigger_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  _trigger_pin = trigger_pin;
  _echo_pin = echo_pin;
  // 
  type(SR04);
}

/* type
 * 
 * Description
 *   Set sensor type.
 * 
 *   sensor.type(byte sensor_type)
 * 
 * Parameters
 *   sensor_type: HC-SR04 (default)
 * 
 * Returns
 *   void
 */
void Ultrasonic::type(byte sensor_type) {
  // 
  switch (sensor_type) {
    default:
    case SR04: {
      _wait_time = 2;
      _trigger_time = 10;
      break;
    }
    case US100: {
      _wait_time = 5;
      _trigger_time = 10;
      break;
    }
  }
}

/* read
 * 
 * Description
 *   Get sensor distance.
 * 
 *   sensor.read()
 * 
 * Parameters
 *   none
 * 
 * Returns
 *   float: distance to nearest bulkhead (centimeters)
 */
float Ultrasonic::read() {
  float duration, distance;
  pinMode(_trigger_pin, OUTPUT);
  pinMode(_echo_pin, INPUT);
  digitalWrite(_trigger_pin, LOW); 
  delayMicroseconds(_wait_time); 
  digitalWrite(_trigger_pin, HIGH);
  delayMicroseconds(_trigger_time); 
  digitalWrite(_trigger_pin, LOW);
  duration = pulseIn(_echo_pin, HIGH);
  distance = duration / 58.2;
  return distance;
}
