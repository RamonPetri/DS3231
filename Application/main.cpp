#include "DS3231.h"
#include "tests.h"
#include "Display.h"
#include "user.h"
int main( void ){
    namespace target = hwlib::target;
 
    auto scl = target::pin_oc( target::pins::scl );
    auto sda = target::pin_oc( target::pins::sda );
    auto userStart = target::pin_in(target::pins::d50);
    auto userSetting = target::pin_in(target::pins::d52);
    auto userSave = target::pin_in(target::pins::d48);
    auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda( scl, sda );
    uint8_t rtcAddres = 0x68;
    uint8_t OledAddres = 0x3c;
    auto oled    = hwlib::glcd_oled(i2c_bus, OledAddres); 
    auto font    = hwlib::font_default_8x8();
    auto display = hwlib::terminal_from( oled, font );
    unsigned char time[3];
    unsigned char date[3];
    //Tests TestClock(i2c_bus,rtcAddres,date,time);
    //TestClock.PrintTestResults();
    DS3231 clock(i2c_bus,rtcAddres);
    Display dis(i2c_bus,rtcAddres,display,time,date);
    user Gui(i2c_bus, rtcAddres,userSave,userStart,userSetting,display);
    
    for(;;){
         Gui.BeginSetting();
         clock.get_Time(time);
         clock.get_Date(date);
         dis.Display_print_Date_Time(time,date,display);
    }
}
