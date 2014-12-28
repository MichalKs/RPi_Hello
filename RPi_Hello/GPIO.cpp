/**
 * @file    GPIO.cpp
 * @brief	  GPIO pin class
 * @date    27 gru 2014
 * @author  Michal Ksiezopolski
 *
 *
 * @verbatim
 * Copyright (c) 2014 Michal Ksiezopolski.
 * All rights reserved. This program and the
 * accompanying materials are made available
 * under the terms of the GNU Public License
 * v3.0 which accompanies this distribution,
 * and is available at
 * http://www.gnu.org/licenses/gpl.html
 * @endverbatim
 */
#include "GPIO.h"

int GPIO::initialized = 0; ///< Is low level library initialized

/**
 * @brief Constructor for GPIO pin
 * @param pin Pin number (pin numbers as per BCM numbering scheme)
 * @param dir Pin direction
 */
GPIO::GPIO(int pin, pinDirection dir) {

  // initialize library only once at start of program
  if (!initialized) {
    wiringPiSetupGpio();
    initialized = 1;
  }
  pinNumber = pin;
  direction = dir;

  pinMode(pinNumber, direction);

}
/**
 * @brief Destructor (sets pin as input)
 */
GPIO::~GPIO(void) {
  pinMode(pinNumber, DIR_INPUT);
}
/**
 * @brief Toggle pin value
 */
void GPIO::toggle(void) {
  int pinValue = read();
  set(!pinValue);
}
/**
 * @brief Read pin value
 * @return Value of pin (0 or 1)
 */
int GPIO::read(void) {
  return digitalRead(pinNumber);
}
/**
 * @brief Set pin value
 * @param newState New pin value
 */
void GPIO::set(int newState) {
  digitalWrite(pinNumber, newState);
}
