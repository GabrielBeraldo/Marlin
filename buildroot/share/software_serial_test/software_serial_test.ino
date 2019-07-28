
#include <arduino.h>
#include <pins_arduino.h>
#include <SoftwareSerial.h>
//#include <NeoSWSerial.h>

#define SOFTWARE_SERIAL 2

#define S_SERIAL_RX_1 53 //AUX2 D44
#define S_SERIAL_TX_1 51 //AUX2 A12 66
#define S_SERIAL_BAUDRATE_1 9600

#define S_SERIAL_RX_2 52 //AUX2 D42
#define S_SERIAL_TX_2 50 //AUX2 A11 65
#define S_SERIAL_BAUDRATE_2 9600

#define SERIAL_ECHOLN(arg)  Serial.println(arg)
#define SERIAL_ECHO(arg)    Serial.print(arg)
#define SERIAL_EOL()        Serial.println("")
#define SERIAL_BEGIN(arg)   Serial.begin(arg)

#define SW_SERIAL_1_ECHOLN(arg) SW_SERIAL_1.println(arg)
#define SW_SERIAL_1_ECHO(arg)   SW_SERIAL_1.print(arg)
#define SW_SERIAL_1_EOL()       SW_SERIAL_1.println("")
#define SW_SERIAL_1_LISTEN()    SW_SERIAL_1.listen()
#define SW_SERIAL_1_BEGIN(arg)  SW_SERIAL_1.begin(arg)
#define SW_SERIAL_1_USED()      _sw_serial_1_avaliable = false

#define SW_SERIAL_2_ECHOLN(arg) SW_SERIAL_2.println(arg)
#define SW_SERIAL_2_ECHO(arg)   SW_SERIAL_2.print(arg)
#define SW_SERIAL_2_EOL()       SW_SERIAL_2.println("")
#define SW_SERIAL_2_LISTEN()    SW_SERIAL_2.listen()
#define SW_SERIAL_2_BEGIN(arg)  SW_SERIAL_2.begin(arg)
#define SW_SERIAL_2_USED()      _sw_serial_2_avaliable = false


SoftwareSerial SW_SERIAL_1(S_SERIAL_RX_1, S_SERIAL_TX_1); // RX, TX
SoftwareSerial SW_SERIAL_2(S_SERIAL_RX_2, S_SERIAL_TX_2); // RX, TX

char _sw_serial_1_received_data[30];
char _sw_serial_2_received_data[30];
char _sw_serial_3_received_data[30];

uint8_t _sw_serial_1_length = 0;
uint8_t _sw_serial_2_length = 0;
uint8_t _sw_serial_3_length = 0;

bool _sw_serial_1_avaliable = false;
bool _sw_serial_2_avaliable = false;
bool _sw_serial_3_avaliable = false;

void SW_SERIAL_1_CHAR(char t)           { SW_SERIAL_1.write(t); }
void SW_SERIAL_1_PRINT(String text)     { SW_SERIAL_1.print(text); }
void SW_SERIAL_1_PRINTLN(String text)   { SW_SERIAL_1.println(text); }
void SW_SERIAL_1_FLUSH()                { SW_SERIAL_1.flush(); }

void SW_SERIAL_2_CHAR(char t)           { SW_SERIAL_1.write(t); }
void SW_SERIAL_2_PRINT(String text)     { SW_SERIAL_1.print(text); }
void SW_SERIAL_2_PRINTLN(String text)   { SW_SERIAL_1.println(text); }
void SW_SERIAL_2_FLUSH()                { SW_SERIAL_1.flush(); }


static void UPDATE_SOFTWARE_SERIAL_1(){
    
    if (_sw_serial_1_avaliable){
        SW_SERIAL_1_USED();
        SERIAL_ECHO("SERIAL_1:");
        SERIAL_ECHO(_sw_serial_1_received_data);
        
        SW_SERIAL_2_LISTEN();

    }else{
        while(SW_SERIAL_1.available()>0) HANDLE_RX_SERIAL_1(SW_SERIAL_1.read());
    }
    
}

static void UPDATE_SOFTWARE_SERIAL_2(){
    
    if (_sw_serial_2_avaliable){
        SW_SERIAL_2_USED();
        SERIAL_ECHO("SERIAL_2:");
        SERIAL_ECHO(_sw_serial_2_received_data);

        SW_SERIAL_1_LISTEN();

    }else{
        while(SW_SERIAL_2.available()>0) HANDLE_RX_SERIAL_2(SW_SERIAL_2.read());
    }
    
}

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


void initialize_software_serial()
{
   //SW_SERIAL_1.attachInterrupt( HANDLE_RX_SERIAL_1 );
    SW_SERIAL_1.begin(S_SERIAL_BAUDRATE_1);
    
    #if SOFTWARE_SERIAL > 1
        //SW_SERIAL_2.attachInterrupt( HANDLE_RX_SERIAL_2 );
        SW_SERIAL_2.begin(S_SERIAL_BAUDRATE_2);
       
        #if SOFTWARE_SERIAL > 2
            SW_SERIAL_3.begin(S_SERIAL_BAUDRATE_3);
        
        #endif
    #endif
}


void setup()
{
    SERIAL_BEGIN(250000);
    initialize_software_serial();
    SERIAL_ECHOLN("initialized");
    SW_SERIAL_1_PRINTLN("serial 1 initialized");
    SW_SERIAL_2_PRINTLN("serial 2 initialized");
}

void loop()
{

    UPDATE_SOFTWARE_SERIAL_1();
    UPDATE_SOFTWARE_SERIAL_2();
}
