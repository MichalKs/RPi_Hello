/**
 * @file    GPIO.h
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
#ifndef GPIO_H_
#define GPIO_H_

#include "wiringPi.h" // for low level GPIO access

/**
 * @brief Class for GPIO pin
 */
class GPIO {

public:

  enum pinDirection {
    DIR_INPUT = 0,
    DIR_OUTPUT = 1
  };

  GPIO(int pin, pinDirection dir);
  virtual ~GPIO();

  void toggle(void);
  int read(void);
  void set(int newState);

private:
  static int initialized;

  int pinNumber;
  int direction;
};

#endif /* GPIO_H_ */
