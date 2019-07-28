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

#if SOFTWARE_SERIAL>0
  
  SoftwareSerial SW_SERIAL_1(S_SERIAL_RX_1, S_SERIAL_TX_1); // RX, TX

  char    _sw_serial_1_received_data[30];
  uint8_t _sw_serial_1_length = 0;
  bool    _sw_serial_1_avaliable = false;

  static void SW_SERIAL_1_CHAR(char t)           { SW_SERIAL_1.write(t); }
  static void SW_SERIAL_1_PRINT(String text)     { SW_SERIAL_1.print(text); }
  static void SW_SERIAL_1_PRINTLN(String text)   { SW_SERIAL_1.println(text); }
  static void SW_SERIAL_1_FLUSH()                { SW_SERIAL_1.flush(); }
  static void SW_SERIAL_1_LISTEN()               { SW_SERIAL_1.listen(); }

  void SW_SERIAL_1_ECHO(String text)             { SW_SERIAL_1.print(text); }
  void SW_SERIAL_1_ECHOLN(String text)           { SW_SERIAL_1.println(text); }
      

  #if SOFTWARE_SERIAL>1
   
    SoftwareSerial SW_SERIAL_2(S_SERIAL_RX_2, S_SERIAL_TX_2); // RX, TX
   
    char    _sw_serial_2_received_data[30];
    uint8_t _sw_serial_2_length = 0;
    bool    _sw_serial_2_avaliable = false;

    static void SW_SERIAL_2_CHAR(char t)           { SW_SERIAL_2.write(t); }
    static void SW_SERIAL_2_PRINT(String text)     { SW_SERIAL_2.print(text); }
    static void SW_SERIAL_2_PRINTLN(String text)   { SW_SERIAL_2.println(text); }
    static void SW_SERIAL_2_FLUSH()                { SW_SERIAL_2.flush(); }
    static void SW_SERIAL_2_LISTEN()               { SW_SERIAL_2.listen(); }

    void SW_SERIAL_2_ECHO(String text)             { SW_SERIAL_2.print(text); }
    void SW_SERIAL_2_ECHOLN(String text)           { SW_SERIAL_2.println(text); }
  
    #if SOFTWARE_SERIAL>2

      SoftwareSerial SW_SERIAL_3(S_SERIAL_RX_3, S_SERIAL_TX_3); // RX, TX
   
      char    _sw_serial_3_received_data[30];
      uint8_t _sw_serial_3_length = 0;
      bool    _sw_serial_3_avaliable = false;

      static void SW_SERIAL_3_CHAR(char t)           { SW_SERIAL_2.write(t); }
      static void SW_SERIAL_3_PRINT(String text)     { SW_SERIAL_2.print(text); }
      static void SW_SERIAL_3_PRINTLN(String text)   { SW_SERIAL_2.println(text); }
      static void SW_SERIAL_3_FLUSH()                { SW_SERIAL_2.flush(static ); }

      
      void SW_SERIAL_3_ECHO(String text)             { SW_SERIAL_3.print(text); }
      void SW_SERIAL_3_ECHOLN(String text);          { SW_SERIAL_3.println(text); }
  
    #endif
  #endif
#endif


static void HANDLE_RX_SERIAL_1( uint8_t c ){
    if(!_sw_serial_1_avaliable){
        
        if (_sw_serial_1_length < sizeof( _sw_serial_1_received_data) - 1)  _sw_serial_1_received_data[_sw_serial_1_length++] = c; 
        
        if(c == ('\r')) {
            _sw_serial_1_received_data[_sw_serial_1_length] = '\0';
            _sw_serial_1_avaliable = true;  
            _sw_serial_1_length = 0; 
        }
    }
}

static void HANDLE_RX_SERIAL_2( uint8_t c ){
    if(!_sw_serial_2_avaliable){
        
        if (_sw_serial_2_length < sizeof( _sw_serial_2_received_data) - 1)  _sw_serial_2_received_data[_sw_serial_2_length++] = c; 
        
        if(c == ('\r')) {
            _sw_serial_2_received_data[_sw_serial_2_length] = '\0';
            _sw_serial_2_avaliable = true;  
            _sw_serial_2_length = 0;
        }
    }
}


void UPDATE_SOFTWARE_SERIAL_1(){
    
    if (_sw_serial_1_avaliable){
        _sw_serial_1_avaliable = false;
        SERIAL_ECHO("SERIAL_1:");
        SERIAL_ECHO(_sw_serial_1_received_data);
        
        SW_SERIAL_2_LISTEN();

    }else{
        while(SW_SERIAL_1.available()>0) HANDLE_RX_SERIAL_1(SW_SERIAL_1.read());
    }
    
}

void UPDATE_SOFTWARE_SERIAL_2(){
    
    if (_sw_serial_2_avaliable){
        _sw_serial_2_avaliable = false;;
        SERIAL_ECHO("SERIAL_2:");
        SERIAL_ECHO(_sw_serial_2_received_data);

        SW_SERIAL_1_LISTEN();

    }else{
        while(SW_SERIAL_2.available()>0) HANDLE_RX_SERIAL_2(SW_SERIAL_2.read());
    }
    
}


void initialize_software_serial()
{
   //SW_SERIAL_1.attachInterrupt( HANDLE_RX_SERIAL_1 );
    SW_SERIAL_1.begin(S_SERIAL_BAUDRATE_1);
    SW_SERIAL_1_PRINTLN("serial 1 initialized");
    
    #if SOFTWARE_SERIAL > 1
        //SW_SERIAL_2.attachInterrupt( HANDLE_RX_SERIAL_2 );
        SW_SERIAL_2.begin(S_SERIAL_BAUDRATE_2);
        SW_SERIAL_2_PRINTLN("serial 2 initialized");
       
        #if SOFTWARE_SERIAL > 2
            SW_SERIAL_3.begin(S_SERIAL_BAUDRATE_3);
            SW_SERIAL_3_PRINTLN("serial 3 initialized");
        
        #endif
    #endif
}

