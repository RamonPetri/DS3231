#ifndef DS3231_H
#define DS3231_H
#include "hwlib.hpp"
class DS3231{
private:
    hwlib::target::pin_oc & data;
    hwlib::target::pin_oc & clock;
    const uint8_t chipaddres;
public:
    DS3231(hwlib::target::pin_oc & data, hwlib::target::pin_oc & clock, const uint8_t chipaddres);
    void set_Time(int hour, int minute, int second);
    void set_Date(int day, int month, int year);
    unsigned char* get_Time(unsigned char time[]);
    unsigned char* get_Date(unsigned char date[]);
    void print_Date_Time(unsigned char date[], unsigned char time[]);
    uint8_t convert_bin_to_dec(unsigned char value);
    uint8_t convert_dec_to_bin(int value);
};
    
#endif