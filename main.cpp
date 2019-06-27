#include "DS3231.h"
#include "tests.h"
#include "Display.h"
int main( void ){
    namespace target = hwlib::target;
 
    auto scl = target::pin_oc( target::pins::scl );
    auto sda = target::pin_oc( target::pins::sda );
    auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda( scl, sda );
    uint8_t rtcAddres = 0x68;
    uint8_t OledAddres = 0x3c;
    auto oled    = hwlib::glcd_oled(i2c_bus, OledAddres); 
    auto font    = hwlib::font_default_8x8();
    auto display = hwlib::terminal_from( oled, font );
    int Dec = 19;
    int BinToDec = 65;
    unsigned char Bin = 0b01100101;
    unsigned char DecToBin = 0b00011001;
    unsigned char time[3];
    unsigned char date[3];
    DS3231 clock(i2c_bus,rtcAddres);
    Tests TestClock(i2c_bus,rtcAddres,Bin,DecToBin,Dec,BinToDec);
    Display dis(i2c_bus,rtcAddres,display,time,date);
    clock.set_Time(0,0,0);
    clock.set_Date(26,6,2019);
    TestClock.PrintTestResults();
    for(;;){
         clock.get_Time(time);
         clock.get_Date(date);
         dis.Display_print_Date_Time(display,time,date);
    }
}
