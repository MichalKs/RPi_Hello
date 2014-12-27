/**
 * @file    GPIO.cpp
 * @brief	  
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

int GPIO::initialized =0;


GPIO::GPIO(int pin, pinDirection dir) {

  if (!initialized) {
    wiringPiSetup();
    initialized = 1;
  }
  pinNumber = pin;
  direction = dir;

  pinMode(pinNumber, direction);

}

GPIO::~GPIO() {
  pinMode(pinNumber, DIR_INPUT);
}

void GPIO::toggle(void) {
  int pinValue = digitalRead(pinNumber);
  set(!pinValue);
}

int GPIO::read(void) {
  return digitalRead(pinNumber);
}

void GPIO::set(int newState) {
  digitalWrite(pinNumber, newState);
}
