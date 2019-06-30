#include "Display.h"
///\brief ///Display class constructor
///\details /// This takes a hwlib::i2c_bus_bit_banged_scl_sda
            /// wich represents the i2c bus communcation
            /// const unit8_t chipaddres wich represents the RTC i2c addres
            /// hwlib::terminal_from & display wich represents the Oled display
            /// unsinged char Time[] wich represents a buffer with time data
            /// unsinged char Date[] wich represents a buffer with date data
            /// a common call to this constructor would look something like this:
            /// Display object(hwlib::i2c_bus_bit_banged_scl_sda, a_rtc_chipaddres, hwlib::terminal_from & display,
            ///                unsigned char Time[], unsinged char Date[]);
 Display::Display(hwlib::i2c_bus_bit_banged_scl_sda & i2c,const uint8_t chipaddres,hwlib::terminal_from & display, unsigned char Time[], unsigned char Date[]):
         DS3231(i2c,chipaddres),display(display){}

///\brief ///Print date time function
///\detail  /// This function will format and print the date and time
            /// to an oled display as defined in the main.cpp
            ///
            /// a common call to this function would look something like this:
            /// Display object.Display_print_Date_Time(unsigned char Time[], unsigned char Date[], hwlib::terminal_from & display);
void Display::Display_print_Date_Time(unsigned char Time[], unsigned char Date[], hwlib::terminal_from & display){
        display<<"\f";
        //Write Date to display
        display<<"\t0101";
        display<<"DS3231_CLOCK";
        display<<"\t0303";
        if(convert_bin_to_dec(Date[0]) < 10){ display<<'0';}
        display<<convert_bin_to_dec(Date[0])<<'/';
        if(convert_bin_to_dec(Date[1]) < 10){display<<'0';}
        display<<convert_bin_to_dec(Date[1])<<'/';
        display<<"20";
        if(convert_bin_to_dec(Date[2] < 10)){display<<'0';}
        display<<convert_bin_to_dec(Date[2]);
    
        //Write Time to display
        display<<"\t0306";
        if(convert_bin_to_dec(Time[2]) < 10){display<<"0";}
        display<< convert_bin_to_dec(Time[2])<<':';
        if(convert_bin_to_dec(Time[1]) < 10){display<<"0";}
        display<< convert_bin_to_dec(Time[1])<<':';
        if(convert_bin_to_dec(Time[0]) < 10){display<<"0";}
        display<< convert_bin_to_dec(Time[0])<<hwlib::flush;
    }
