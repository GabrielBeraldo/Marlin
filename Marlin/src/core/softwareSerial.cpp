
#include "softwareSerial.h"
#include "serial.h"
#include "../lcd/ultralcd.h"

#ifdef ARDUINO
  #include <pins_arduino.h>
#endif

#if SOFTWARE_SERIAL > 0
  
  SoftwareSerial SW_SERIAL_1(S_SERIAL_RX_1, S_SERIAL_TX_1); // RX, TX

  char    _sw_serial_1_received_data[S_SERIAL_DATASIZE];
  uint8_t _sw_serial_1_length = 0;
  bool    _sw_serial_1_avaliable = false;

  static void SW_SERIAL_1_CHAR(char t)           { SW_SERIAL_1.write(t); }
  static void SW_SERIAL_1_PRINT(String text)     { SW_SERIAL_1.print(text); }
  static void SW_SERIAL_1_PRINTLN(String text)   { SW_SERIAL_1.println(text); }
  static void SW_SERIAL_1_FLUSH()                { SW_SERIAL_1.flush(); }
  static void SW_SERIAL_1_LISTEN()               { SW_SERIAL_1.listen(); }
 

  void SW_SERIAL_1_ECHO(String text)             { SW_SERIAL_1.print(text); }
  void SW_SERIAL_1_ECHOLN(String text)           { SW_SERIAL_1.println(text); }
  void SW_SERIAL_1_STOP_LISTENING()              { SW_SERIAL_1.end();}    
  
  
  #if SOFTWARE_SERIAL > 1
    
    SoftwareSerial SW_SERIAL_2(S_SERIAL_RX_2, S_SERIAL_TX_2); // RX, TX
   
    char    _sw_serial_2_received_data[S_SERIAL_DATASIZE];
    uint8_t _sw_serial_2_length = 0;
    bool    _sw_serial_2_avaliable = false;

    static void SW_SERIAL_2_CHAR(char t)           { SW_SERIAL_2.write(t); }
    static void SW_SERIAL_2_PRINT(String text)     { SW_SERIAL_2.print(text); }
    static void SW_SERIAL_2_PRINTLN(String text)   { SW_SERIAL_2.println(text); }
    static void SW_SERIAL_2_FLUSH()                { SW_SERIAL_2.flush(); }
    static void SW_SERIAL_2_LISTEN()               { SW_SERIAL_2.listen(); }

    void SW_SERIAL_2_ECHO(String text)             { SW_SERIAL_2.print(text); }
    void SW_SERIAL_2_ECHOLN(String text)           { SW_SERIAL_2.println(text); }
    void SW_SERIAL_2_STOP_LISTENING()              { SW_SERIAL_2.end();}

     
    #if SOFTWARE_SERIAL > 2
    
      SoftwareSerial SW_SERIAL_3(S_SERIAL_RX_3, S_SERIAL_TX_3); // RX, TX
   
      char    _sw_serial_3_received_data[S_SERIAL_DATASIZE];
      uint8_t _sw_serial_3_length = 0;
      bool    _sw_serial_3_avaliable = false;

      static void SW_SERIAL_3_CHAR(char t)           { SW_SERIAL_2.write(t); }
      static void SW_SERIAL_3_PRINT(String text)     { SW_SERIAL_2.print(text); }
      static void SW_SERIAL_3_PRINTLN(String text)   { SW_SERIAL_2.println(text); }
      static void SW_SERIAL_3_FLUSH()                { SW_SERIAL_2.flush(static ); }

      
      void SW_SERIAL_3_ECHO(String text)             { SW_SERIAL_3.print(text); }
      void SW_SERIAL_3_ECHOLN(String text);          { SW_SERIAL_3.println(text); }
      void SW_SERIAL_3_STOP_LISTENING()              { SW_SERIAL_3.end();}
    
    #endif
  #endif
#endif


#if SOFTWARE_SERIAL>0
  
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

  void ECHO_SOFTWARE_SERIAL_1(){
    
    if (_sw_serial_1_avaliable){
        _sw_serial_1_avaliable = false;
        SERIAL_ECHO("serial_1:");
        SERIAL_ECHO(_sw_serial_1_received_data);
        
        ui.set_status(_sw_serial_1_received_data);

    }
  }

  #if SOFTWARE_SERIAL>1
      
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

    void ECHO_SOFTWARE_SERIAL_2(){
      
      if (_sw_serial_2_avaliable){
          _sw_serial_2_avaliable = false;
          SERIAL_ECHO("serial_2:");
          SERIAL_ECHO(_sw_serial_2_received_data);
          
          ui.set_status(_sw_serial_2_received_data);

      }
    }

    #if SOFTWARE_SERIAL>2
          
      static void HANDLE_RX_SERIAL_3( uint8_t c ){
          if(!_sw_serial_3_avaliable){
              
              if (_sw_serial_3_length < sizeof( _sw_serial_3_received_data) - 1)  _sw_serial_3_received_data[_sw_serial_3_length++] = c; 
              
              if(c == ('\r')) {
                  _sw_serial_3_received_data[_sw_serial_3_length] = '\0';
                  _sw_serial_3_avaliable = true;  
                  _sw_serial_3_length = 0;
              }
          }
      }

      void ECHO_SOFTWARE_SERIAL_3(){
        
        if (_sw_serial_3_avaliable){
            _sw_serial_3_avaliable = false;
            SERIAL_ECHO("serial_3:");
            SERIAL_ECHO(_sw_serial_3_received_data);
            
            ui.set_status(_sw_serial_3_received_data);

        }
      }


    
    #endif
  #endif
#endif

void UPDATE_SOFTWARE_SERIAL(){
  #if SOFTWARE_SERIAL > 0
    
    if(SW_SERIAL_1.available()>0){
      _sw_serial_1_avaliable = false;
      while(SW_SERIAL_1.available()>0) HANDLE_RX_SERIAL_1(SW_SERIAL_1.read());
    }

    #if SOFTWARE_SERIAL > 1
      
      if(SW_SERIAL_2.available()>0){
        _sw_serial_2_avaliable = false;
        while(SW_SERIAL_2.available()>0) HANDLE_RX_SERIAL_2(SW_SERIAL_2.read());
      }

      #if SOFTWARE_SERIAL > 2
      
        if(SW_SERIAL_3.available()>0){
          _sw_serial_3_avaliable = false;
          while(SW_SERIAL_3.available()>0) HANDLE_RX_SERIAL_3(SW_SERIAL_3.read());
        }
      #endif
  #endif
  #endif
}

bool LISTEN_TO_SW_SERIAL(int serial_port){
  
  STOP_LISTEN_SW_SERIAL(0);

  switch(serial_port){
    
    case 1 : 
      SW_SERIAL_1_LISTEN(); 
      return true; break;
    
    case 2 :
      #if SOFTWARE_SERIAL > 1
        SW_SERIAL_2_LISTEN();
        return true;
        break;
      #else
        return false; break;
      #endif
      
    case 3 :
      #if SOFTWARE_SERIAL > 2
        SW_SERIAL_3_LISTEN();
        return true;
        break;
      #else
        return false; break;
      #endif
  
      default: return false; break;
  }
}


bool STOP_LISTEN_SW_SERIAL(int serial_port){
  
  switch(serial_port){
    
    case 1 : 
      SW_SERIAL_1_STOP_LISTENING(); 
      return true; break;
    
    case 2 :
      #if SOFTWARE_SERIAL > 1
        SW_SERIAL_2_STOP_LISTENING();
        return true;
        break;
      #else
        return false; break;
      #endif
      
    case 3 :
      #if SOFTWARE_SERIAL > 2
        SW_SERIAL_3_STOP_LISTENING();
        return true;
        break;
      #else
        return false; break;
      #endif

    default : 
      
      SW_SERIAL_1_STOP_LISTENING();
      #if SOFTWARE_SERIAL > 1
        SW_SERIAL_2_STOP_LISTENING();
        #if SOFTWARE_SERIAL > 2
          SW_SERIAL_3_STOP_LISTENING();
        #endif
      #endif  
      
      return true; break;
  }
}

bool INITIALIZE_SW_SERIAL(int serial_port, int port_baudrate){
  
  switch(serial_port){
    
    case 1 : 
      SW_SERIAL_1.begin(port_baudrate); 
      SW_SERIAL_1_STOP_LISTENING();
      return true; break;
    
    case 2 :
      #if SOFTWARE_SERIAL > 1
        SW_SERIAL_2.begin(port_baudrate);
        SW_SERIAL_2_STOP_LISTENING();
        return true;
        break;
      #else
        return false; break;
      #endif
      
    case 3 :
      #if SOFTWARE_SERIAL > 2
        SW_SERIAL_3.begin(port_baudrate);
        SW_SERIAL_3_STOP_LISTENING();
        return true;
        break;
      #else
        return false; break;
      #endif
  }
}

bool HANDLE_PH_READING_DATA(const char* received_data){
  
  int data_lenght = 0;
  bool _ph_read_is_stable = false;

  String date_info;
  String time_info;
  String ph_info;
  String temp_info;
  
  while(received_data[data_lenght] != ';'){
    if(received_data[data_lenght] != ' ') date_info+=received_data[data_lenght];
    data_lenght++;
  }
  
  data_lenght++;
  while(received_data[data_lenght] != ';'){
    if(received_data[data_lenght] != ' ') time_info+=received_data[data_lenght];
    data_lenght++;
  }
  
  data_lenght++;
  while(received_data[data_lenght] != ';'){
    if(received_data[data_lenght] == PH_READ_STABLE_CHAR) _ph_read_is_stable = true;
    data_lenght++;
  }

  data_lenght++;
  while(received_data[data_lenght] != ';'){
    if(received_data[data_lenght] != ' ') ph_info+=received_data[data_lenght];
    data_lenght++;
  }
  
  data_lenght++;
  while(received_data[data_lenght] != '\0'){
    if(received_data[data_lenght] != ' ') temp_info+=received_data[data_lenght];
    data_lenght++;
  }
  

  if(_ph_read_is_stable){
    STOP_LISTEN_SW_SERIAL(0);

    String Buffer = date_info + ", " + time_info + ", " + ph_info + ", " + temp_info;
    SERIAL_ECHOLN(Buffer);

    int ph_len = ph_info.length();  
    char ph_array[ph_len + 1];  
    strcpy(ph_array, ph_info.c_str());

    ui.set_status(ph_array);

    return true; 
  }
  else return false;
}

bool GET_PH_READING( int serial_port, int port_timeout){
  
  unsigned long _sw_serial_reading_time = millis();
  
  if(!LISTEN_TO_SW_SERIAL(serial_port)){
    SERIAL_ECHOLN("error: listening to serial port returned false");
    STOP_LISTEN_SW_SERIAL(0);
    return false;
  } 

  while(true){
    watchdog_reset();   // beat the dog

    if(millis() - _sw_serial_reading_time >= port_timeout){
      SERIAL_ECHOLN("error: reading timed out!");
      STOP_LISTEN_SW_SERIAL(0);
      return false;
    }

    UPDATE_SOFTWARE_SERIAL();

    switch(serial_port){
      
      case 1 : 
        if(_sw_serial_1_avaliable){
          _sw_serial_1_avaliable = false;
          if(HANDLE_PH_READING_DATA(_sw_serial_1_received_data)) return true;
          //SERIAL_ECHOLN("test received data 1");
        } 
        break;
      
      case 2 : 
        #if SOFTWARE_SERIAL > 1
          if(_sw_serial_2_avaliable){
            _sw_serial_2_avaliable = false;
            if(HANDLE_PH_READING_DATA(_sw_serial_2_received_data)) return true;
            //SERIAL_ECHOLN("test received data 2");
          } 
          break;  
        #else 
          break;
        #endif

      case 3 : 
        #if SOFTWARE_SERIAL > 2
          if(_sw_serial_3_avaliable){
            _sw_serial_3_avaliable = false;
            if(HANDLE_PH_READING_DATA(_sw_serial_3_received_data)) return true;
          } 
          break;
        #else 
          break; 
        #endif 
    }
  }

}

