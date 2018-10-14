/* Ultrasonic.h - Ultrasonic Distance Measuring Sensor Library
 * 
 * Author: Márcio Pessoa <marcio.pessoa@sciemon.com>
 * Contributors: none
 * 
 * Change log
 * 2014-11-16
 *         * Ultrasonic
 *         changed int variables to byte variables to reduce memory
 *         consumption.
 * 
 * 2014-07-06
 *         Experimental version.
 */

#ifndef Ultrasonic_h
#define Ultrasonic_h

#include "Arduino.h"

#define SR04 0
#define US100 1

class Ultrasonic
{
  public:
    Ultrasonic();
    void attach(byte trigger_pin, byte echo_pin);
    void type(byte type);
    float read();
  private:
    byte _trigger_pin;
    byte _echo_pin;
    byte _wait_time;
    byte _trigger_time;
//~ int _range = 4500; // "cm": Centimeters
};

#endif
