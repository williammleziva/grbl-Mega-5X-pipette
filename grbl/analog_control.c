/*
  analog_control.c - Read analog input
  Part of Grbl

    Grbl $ command:
    $A : Read all analog inputs

    User defined M codes :
    M167 P<0/1>: Read analog input, Synchronized
    M168 P<0/1>: Read analog input, Immediate

  Copyright (c) 2017-2022 Gauthier Briere

  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "grbl.h"

float readAnalog()
{
  float value = 0.0;
  // Voltage reference for ADC. The default Arduino's analog reference 
  // of 5 volts on 5V Arduino boards.
  uint8_t adcVRef = 1 << 6;
  // A13 : pin = 13 --- A14 pin = 14
  uint8_t pin = 13;
  
  // ADC Prescaler = 32
  sbi(ADCSRA, ADPS2);
  cbi(ADCSRA, ADPS1);
  sbi(ADCSRA, ADPS0);

  // Selection de la pin
  ADMUX = 
  // On lance la lecture analogique
  sbi(ADCSRA, ADSC);

  return value;
}
