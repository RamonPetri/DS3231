#ifndef DISPLAY_H
#define DISPLAY_H

#include "DS3231.h"
///\brief ///The display class for a OLED display
///\details /// This class inherits form DS3231 and there for requires hwlib to operate 
            /// this class is written to format and print date and time on a 128x64 I2C OLED
class Display : public DS3231{
private:
    hwlib::terminal_from & display;
    unsigned char Time[];
    unsigned char Date[];
public:

    Display(hwlib::i2c_bus_bit_banged_scl_sda & i2c,const uint8_t chipaddres,hwlib::terminal_from & display, unsigned char Time[], unsigned char Date[]);
    
    void Display_print_Date_Time(unsigned char Time[], unsigned char Date[], hwlib::terminal_from & display);

};

#endif