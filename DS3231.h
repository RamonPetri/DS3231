#ifndef DS3231_H
#define DS3231_H

#include "hwlib.hpp"
class DS3231{
private:
    hwlib::target::pin_oc & data;
    hwlib::target::pin_oc & clock;
    const uint8_t chipaddres;
    uint8_t convert_bin_to_dec(unsigned char value);
    uint8_t convert_dec_to_bin(int value);
public:
    DS3231(hwlib::target::pin_oc & data, hwlib::target::pin_oc & clock, const uint8_t chipaddres);
    void set_Time(int hour, int minute, int second);
    unsigned char* get_Time(unsigned char time[]);
    void print_Time(unsigned char time[]);
};
    
#endif