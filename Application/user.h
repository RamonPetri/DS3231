#ifndef USER_H
#define USER_H

#include "DS3231.h"
#include "hwlib.hpp"
///\brief ///The user class for a OLED display set time and date menu
///\details /// This class inherits form DS3231 and there for requires hwlib to operate 
            /// this class is written to giva a user menu to enable the setting of date & time
            /// by using hardware buttons
class user : public DS3231{
private: 
     hwlib::target::pin_in & saveSetting;
     hwlib::target::pin_in & startSetting;
     hwlib::target::pin_in & addNum;
     hwlib::terminal_from & display;
public:
    user(hwlib::i2c_bus_bit_banged_scl_sda & i2c,const uint8_t chipaddres,hwlib::target::pin_in&saveSetting,hwlib::target::pin_in & startSetting, hwlib::target::pin_in & addNum, hwlib::terminal_from&display);
    void BeginSetting();
    void set_date_time();
};




#endif