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

/**
 * @brief Class for GPIO pin
 */
class Gpio {

public:
  enum PinDirection {
    DIRECTION_INPUT = 0,
    DIRECTION_OUTPUT = 1,
  };

  Gpio(int pinNumber, PinDirection pinDirection);
  virtual ~Gpio();
  void toggle();
  bool read();
  void set(bool newState);

private:
  static bool initialized;    ///< Is low level library initialized
  int pinNumber;              ///< Pin number
  PinDirection pinDirection;  ///< Pin direction
};

#endif /* GPIO_H_ */
