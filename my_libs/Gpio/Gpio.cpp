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

#include "Gpio.h"
#include "wiringPi.h"

bool Gpio::initialized = false;

/**
 * @brief Constructor for GPIO pin
 * @param pinNumber Pin number (pin numbers as per BCM numbering scheme)
 * @param pinDirection Pin direction
 */
Gpio::Gpio(int pinNumber, PinDirection pinDirection) {
  // initialize library only once at start of program
  if (!initialized) {
    wiringPiSetupGpio();
    initialized = true;
  }
  this->pinNumber = pinNumber;
  this->pinDirection = pinDirection;
  pinMode(pinNumber, pinDirection);
}
/**
 * @brief Destructor (sets pin as input)
 */
Gpio::~Gpio() {
  pinMode(pinNumber, DIRECTION_INPUT);
}
/**
 * @brief Toggle pin value
 */
void Gpio::toggle() {
  int pinValue = read();
  set(!pinValue);
}
/**
 * @brief Read pin value
 * @return Value of pin (0 or 1)
 */
bool Gpio::read() {
  return digitalRead(pinNumber);
}
/**
 * @brief Set pin value
 * @param newState New pin value
 */
void Gpio::set(bool newState) {
  digitalWrite(pinNumber, newState);
}
