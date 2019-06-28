#ifndef USER_H
#define USER_H

#include "DS3231.h"
#include "hwlib.hpp"

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