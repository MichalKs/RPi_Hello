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
#include <wiringPi.h>
#include "GPIO.h"

using namespace std;

int main (void) {

  cout << "Hello world!!!" << endl;

  GPIO led(0, GPIO::DIR_OUTPUT);

  while (1) {
    led.toggle();
    cout << "Pin value: " << led.read() << endl;
    delay(500);
  }
  return 0;
}
