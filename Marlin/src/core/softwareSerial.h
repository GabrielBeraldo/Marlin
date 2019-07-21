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
#ifndef SOFTWARESERIAL_H
#define SOFTWARESERIAL_H

#include "../inc/MarlinConfigPre.h"

#include <arduino.h>
#include <SoftwareSerial.h>


#if SOFTWARE_SERIAL > 0
   
    void initialize_software_serial();
    
    void SOFTWARE_SERIAL_1_CHAR(char);
    void SOFTWARE_SERIAL_1_PRINT(String);   
    void SOFTWARE_SERIAL_1_PRINTLN(String);   
    void SOFTWARE_SERIAL_1_FLUSH();  
    void UPDATE_SOFTWARE_SERIAL_1();         

    #if SOFTWARE_SERIAL > 1
    
        void SOFTWARE_SERIAL_2_CHAR(char);
        void SOFTWARE_SERIAL_2_PRINT(String);   
        void SOFTWARE_SERIAL_2_PRINTLN(String);   
        void SOFTWARE_SERIAL_2_FLUSH();  

        #if SOFTWARE_SERIAL > 2

            void SOFTWARE_SERIAL_3_CHAR(char);
            void SOFTWARE_SERIAL_3_PRINT(String);   
            void SOFTWARE_SERIAL_3_PRINTLN(String);   
            void SOFTWARE_SERIAL_3_FLUSH();  
        
        #endif
    #endif
    
    

#endif
#endif