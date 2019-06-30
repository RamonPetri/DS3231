#ifndef DS3231_H
#define DS3231_H
#include "hwlib.hpp"
///\brief /// The DS3231 class written to be used with a DS3231 RTC
///\detail  /// This class is written to give a interface to work with a DS2321 RTC
            /// These RTC's can be used in a varity of application including servers, gps modules and embedded systems
            /// This class and classes that inherit from it are written to work with the library Hwlib from Wouter van Ooijen
            /// The hwlib library can be found at his github page: https://github.com/wovo/hwlib
            /// This class makes it easy for a user to set and get the date & time in the DS3231 registers 
            /// written by Ramon Petri (28-06-2019)
class DS3231{
private:
    hwlib::i2c_bus_bit_banged_scl_sda & i2c;
    const uint8_t chipaddres;
public:
    DS3231(hwlib::i2c_bus_bit_banged_scl_sda & i2c, const uint8_t chipaddres);
    void set_Time(int hour, int minute, int second);
    void set_Date(int day, int month, int year);
    unsigned char* get_Time(unsigned char time[]);
    unsigned char* get_Date(unsigned char date[]);
    void print_Date_Time(unsigned char date[], unsigned char time[]);
    int convert_bin_to_dec(unsigned char value);
    uint8_t convert_dec_to_bin(int value);
};
    
#endif