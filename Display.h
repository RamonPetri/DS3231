class Display : public DS3231{
    private:
    hwlib::terminal_from & display;
    unsigned char Time[];
    unsigned char Date[];
    public:
    Display(hwlib::i2c_bus_bit_banged_scl_sda & i2c,const uint8_t chipaddres,hwlib::terminal_from & display, unsigned char Time[], unsigned char Date[]):
         DS3231(i2c,chipaddres),display(display){}
    void Display_print_Date_Time(hwlib::terminal_from & display, unsigned char Time[], unsigned char Date[]){
        display<<"\f";
        //Write Date to display
        display<<"\t0101";
        display<<"DS3231_CLOCK";
        display<<"\t0303";
        if(convert_bin_to_dec(Date[0]) < 10){ display<<'0';}
        display<<convert_bin_to_dec(Date[0])<<'/';
        if(convert_bin_to_dec(Date[1]) < 10){display<<'0';}
        display<<convert_bin_to_dec(Date[1])<<'/';
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

};