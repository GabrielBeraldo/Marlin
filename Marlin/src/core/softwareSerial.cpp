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

#include "softwareSerial.h"
#include "serial.h"
#include "../lcd/ultralcd.h"

#ifdef ARDUINO
  #include <pins_arduino.h>
#endif

#if SOFTWARE_SERIAL > 0

    
    SoftwareSerial SOFTWARE_SERIAL_1(S_SERIAL_RX_1, S_SERIAL_TX_1); // RX, TX
    #if SOFTWARE_SERIAL > 1
        SoftwareSerial SOFTWARE_SERIAL_2(S_SERIAL_RX_2, S_SERIAL_TX_2); // RX, TX
        #if SOFTWARE_SERIAL > 2
            SoftwareSerial SOFTWARE_SERIAL_3(S_SERIAL_RX_3, S_SERIAL_TX_3); // RX, TX
        #endif
    #endif    

    void initialize_software_serial(){
        //SERIAL_ECHOLN("serial initialize here!");
        SOFTWARE_SERIAL_1.begin(S_SERIAL_BAUDRATE_1);
        #if SOFTWARE_SERIAL > 1
            SOFTWARE_SERIAL_2.begin(S_SERIAL_BAUDRATE_2);
            #if SOFTWARE_SERIAL > 2
                SOFTWARE_SERIAL_3.begin(S_SERIAL_BAUDRATE_3);
            #endif
        #endif   

    }
    
    void SOFTWARE_SERIAL_1_CHAR(char t){SOFTWARE_SERIAL_1.write(t);}
    void SOFTWARE_SERIAL_1_PRINT(String text){SOFTWARE_SERIAL_1.print(text);}
    void SOFTWARE_SERIAL_1_PRINTLN(String text){ SOFTWARE_SERIAL_1.println(text);}   
    void SOFTWARE_SERIAL_1_FLUSH(){SOFTWARE_SERIAL_1.flush();} 

    void UPDATE_SOFTWARE_SERIAL_1(){
        String cmd = "";

        
        if(SOFTWARE_SERIAL_1.available()) SERIAL_ECHOLN("avaliable");
        while (SOFTWARE_SERIAL_1.available()) {
            char inChar = (char)SOFTWARE_SERIAL_1.read();
             cmd += inChar;
        }

        if(cmd != ""){
          SERIAL_ECHOLN("diff");
          cmd="";
        }
    }


#endif


//void cmd_execute();

/*
  SerialEvent occurs whenever a new data comes in the
  hardware serial RX.  This routine is run between each
  time loop() runs, so using delay inside loop can delay
  response.  Multiple bytes of data may be available.
*/
/* 
void serialEvent2() {
  while (Serial2.available()) {
    // get the new byte:
    char inChar = (char)Serial2.read();

    switch (state) {
      case 0:
        if (inChar == '#') state = 1;
        break;
      case 1:
        if (inChar == '$') {
          cmd = comdata;
          comdata = "";
          Cmd_completed = true;
          cmd_excute();
          state = 0;
        }
        else {
          comdata += inChar;
        }
        break;
      default:
        break;
    }

  }
}

void cmd_execute() {
  if ( cmd == "AskForFileList") {
    Serial2.print("#TA100/230\tTB56/230\tTC110/112\tPS4\tPP56\tPT02:43:24\tFNmonkey.gco\t$");
  }
  if ( cmd == "GoOnPrinting1") {
    ;//断点打印
  }
  if ( cmd == "GoOnPrinting2") {
   ;//暂停后继续打印
  }
  if ( cmd == "PrintingCanceled") { }
  if ( cmd == "GetInfo") { }
  if ( cmd == "RefuseInfo") { }
  if ( cmd == "StartPrinting") { }
  if ( cmd == "PausePrinting") { }
  if ( cmd == "ReplaceMaterial") { }
  if ( cmd == "NozzleHeating225") { }
  if ( cmd == "BedHeating225") { }
  if ( cmd == "XHome") { }
  if ( cmd == "YHome") { }
  if ( cmd == "ZHome") { }
  if ( cmd == "AllHome") { }
}
*/