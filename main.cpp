/**
 * @file    main.cpp
 * @brief	  
 * @date    22 gru 2014
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

#include <iostream>
#include "Gpio/Gpio.h"
#include "Utils/Utils.h"

using namespace std;

/**
 * @brief Main function
 * @retval 0 Program ended successfully
 */
int main(int argc, char * argv[]) {

  cout << "Hello world!!!" << endl;
  const int DELAY_TIME_MILLIS = 500;
  const int LED_PIN_NUMBER = 17;
  Gpio * led = new Gpio(LED_PIN_NUMBER, Gpio::DIRECTION_OUTPUT);

  while (true) {
    led->toggle();
    cout << "Pin value: " << led->read() << endl;
    Utils::delayMillis(DELAY_TIME_MILLIS);
  }
  return 0;
}
