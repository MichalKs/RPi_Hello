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
#include <unistd.h>
#include <sstream>

#include "GPIO.h"

using namespace std;

/**
 * @brief Main function
 * @retval 0 Program ended successfully
 */
int main(int argc, char* argv[]) {

  cout << "Hello world!!!" << endl;

  const int delayTime = 500*1000;

  int pinNumber;

  if (argc != 2) {
    cout << "Error: Wrong number of parameters" << endl;
    cout << "Usage: " << argv[0] << " pinNumber" << endl;
    return 1;
  }

  string s(argv[1]);
  istringstream sstr(s);
  sstr >> pinNumber;
  cout << "Got pin number " << pinNumber << endl;

  GPIO led(pinNumber, GPIO::DIR_OUTPUT);

  while (1) {
    led.toggle();
    cout << "Pin value: " << led.read() << endl;
    usleep(delayTime); // sleep given number of microseconds
  }
  return 0;
}
