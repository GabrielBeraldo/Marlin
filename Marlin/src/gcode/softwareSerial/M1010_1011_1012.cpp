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
#include "../../module/stepper.h"
#include "../../inc/MarlinConfig.h"

#if SOFTWARE_SERIAL > 0


void GcodeSuite::M1010() {
  
  planner.synchronize(); //wait for all the instructions to finish executing

  if (!parser.seenval('P')){
    SERIAL_ECHOLN("error: no port selected P1 P2 or P3 ");
    return;
  } 
  const int serial_port = parser.value_int();

  const int port_baudrate = parser.intval('B', DEFAULT_SW_SERIAL_BAUDRATE);

  const bool initialized = INITIALIZE_SW_SERIAL(serial_port, port_baudrate);  

  SERIAL_ECHO("echo:");
  SERIAL_ECHO(initialized ? " INITIALIZED" : " FAILED");
  SERIAL_ECHOPAIR(" | PORT: ", serial_port);
  SERIAL_ECHOPAIR(" | BAUDRATE: ", port_baudrate);
  SERIAL_EOL();

}

void GcodeSuite::M1011() {
  
  const int serial_port = parser.intval('P', 0);

  const bool listening = LISTEN_TO_SW_SERIAL(serial_port);

  SERIAL_ECHO("echo:");
  SERIAL_ECHO(listening ? " LISTENING" : " FAILED");
  SERIAL_ECHO(" | PORT: ");
  SERIAL_ECHO((serial_port > 0) ? String(serial_port) : "ALL");
  SERIAL_EOL();

}

void GcodeSuite::M1012() {
  
  const int serial_port = parser.intval('P', 0);

  const bool stopped = STOP_LISTEN_SW_SERIAL(serial_port);

  SERIAL_ECHO("echo:");
  SERIAL_ECHO(stopped ? " STOPPED" : " FAILED");
  SERIAL_ECHO(" | PORT: ");
  SERIAL_ECHO((serial_port > 0) ? String(serial_port) : "ALL");
  SERIAL_EOL();

}

#endif