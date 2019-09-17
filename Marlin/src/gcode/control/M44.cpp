/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2019 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "../gcode.h"
#include "../../Marlin.h" // for pin_is_protected
#include "../../inc/MarlinConfig.h"

#include "../../module/stepper.h"

wait_for_change(millis_t time) {
  time += millis();
  while (PENDING(millis(), time)) idle();
}

void GcodeSuite::M44() {

    millis_t wait_ms = DEFAULT_M44_WAIT;
    int pwm_value = 255;

    if (parser.seenval('T')) wait_ms = parser.value_millis(); // seconds to wait

    if (parser.seenval('S')) pwm_value = parser.value_int();
    constrain(pwm_value,0,255);
    
    const pin_t pin_number = parser.byteval('P', LED_PIN);
    if (pin_number < 0) return;

    if (!parser.boolval('I') && pin_is_protected(pin_number)) return protected_pin_err();

    planner.synchronize();
    
    pinMode(pin_number, OUTPUT);
    digitalWrite(pin_number, 0);

    analogWrite(pin_number, pwm_value);
    wait_for_change(wait_ms);
    digitalWrite(pin_number, 0);

}

