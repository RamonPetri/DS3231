#include "DS3231.h"

///\brief //DS3231 class constructor 
///\detail  // This constructor takes a hwlib::i2c_bus_bit_banged_scl_sda i2c 
            // wich represents the i2c communication bus
            // and a uint8_t value wich represents the i2c addres of the DS3231 chip
            // these varabels are used to initilize I2C bus communication
            // A common call to this constructor would look something like this:
            // DS3231 object(hwlib::i2c_bus_bit_banged_scl_sda, a_rtc_chipaddres);
DS3231::DS3231(hwlib::i2c_bus_bit_banged_scl_sda & i2c, const uint8_t chipaddres):
    i2c(i2c),chipaddres(chipaddres){}

///\brief //Convert binary to decimal
///\detail  // This function takes a uint8_t value wich represents a binary
            // number Than the function will convert this number into a decimal number
            // with the formula as specifide with in the function
            // A common call to this function would look something like this:
            // DS3231 object.convert_bin_to_dec(binary_value);
int DS3231::convert_bin_to_dec(unsigned char value){
        return ((value/16*10) + (value%16));
    }
///\brief //Convert decimal to binary
///\detail  // This function takes a integer value wich represents a decimal
            // number Than the function will convert this number into a binary number
            // with the formula as specifide with in the function
            // A common call to this function would look something like this:
            // DS3231 object.convert_dec_to_bin(a_integer_value);
uint8_t DS3231::convert_dec_to_bin(int value){
        return ( ( value/10*16)+(value%10));
    }

///\brief //Sets the date on the DS3231
///\detail  // This function takes integer values wich represent the day month and year
            // The function than makes a i2c bit banged bus and constructs a Writebuffer that
            // contains the following: Adress pointer(0x04) and the converted day month and year
            // Than this function starts a I2C write transaction to write the buffer to
            // the date registers(0x04,0x05,0x06) on the chip.
            // A common call to this function would look something like this:
            // DS3231 object.set_Date(integer day_value, integer month_value, integer year_value);
void DS3231::set_Date(int day,int month, int year){
    const uint8_t writeBuff[4] = {0x04, convert_dec_to_bin(day),
                                 convert_dec_to_bin(month),
                                 convert_dec_to_bin(year)};
    hwlib::i2c_write_transaction(i2c, chipaddres).write(writeBuff,4);
}

///\brief //Set the time on the DS3231
///\detail  // This function takes integer values wich represent the hours minutes and seconds
            // The function than makes a i2c bit banged bus and constructs a Writebuffer that
            // contains the following: Adress pointer(0x00) and the converted hours minutes and seconds
            // Than this function starts a I2C write transaction to write the buffer to
            // the time registers(0x00,0x01,0x02) on the chip.
            // A common call to this function would look something like this:
            // DS3231 object.set_Time(integer hour_value, integer minute_value, integer seconds_value);
void DS3231::set_Time(int hour, int minute, int second){
   const uint8_t writeBuff[4] = {0x00, convert_dec_to_bin(second),
                                convert_dec_to_bin(minute), 
                                convert_dec_to_bin(hour)};
   hwlib::i2c_write_transaction(i2c,chipaddres).write(writeBuff,4);
}

///\brief //Gets the time 
///\detail  // This function takes a unsinged char buffer time with a size of 3 wich will be filled with the
            // following: seconds, minutes, hours
            // This will be acomplised by first writing to either the seconds minutes
            // or hour register respectiflly after this the function will read a byte
            // from the selected register after the Time buffer is filled
            // it will be returned.
            // A common call to this function would look something like this:
            // DS3231 object.get_Time(unsigned char buffer_to_store_time[3]);
unsigned char* DS3231::get_Time(unsigned char time[]){
    hwlib::i2c_write_transaction(i2c, chipaddres).write(0x00);
    time[0] = hwlib::i2c_read_transaction(i2c,chipaddres).read_byte();
    hwlib::i2c_write_transaction(i2c, chipaddres).write(0x01);
    time[1] = hwlib::i2c_read_transaction(i2c,chipaddres).read_byte();
    hwlib::i2c_write_transaction(i2c, chipaddres).write(0x02);
    time[2] = hwlib::i2c_read_transaction(i2c,chipaddres).read_byte();
    return time;
}

///\brief //Gets the date 
///\detail  // This function takes a unsinged char buffer date with a size of 3 wich will be filled with the
            // following: day, month, year
            // This will be acomplised by first writing to either the day month or year
            // register respectiflly after this the function will read a byte
            // from the selected register after the dtae buffer is filled
            // it will be returned
            // A common call to this function would look something like this:
            // DS3231 object.get_Date(unsigned char buffer_to_store_date[3]);
unsigned char* DS3231::get_Date(unsigned char date[]){
    hwlib::i2c_write_transaction(i2c,chipaddres).write(0x04);
    date[0] = hwlib::i2c_read_transaction(i2c, chipaddres).read_byte();
    hwlib::i2c_write_transaction(i2c,chipaddres).write(0x05);
    date[1] = hwlib::i2c_read_transaction(i2c, chipaddres).read_byte();
    hwlib::i2c_write_transaction(i2c, chipaddres).write(0x06);
    date[2] = hwlib::i2c_read_transaction(i2c, chipaddres).read_byte();
    return date;
}

///\brief //Print date and time to hwlib::cout for debug purposes
///\detail  // This function has as purposes to let a user see time and date info without using any kind of display
            // This function takes two unsigned chars a date one and a time one
            // This function will print the date and time in the following format:
            // "dd-MM-YY ss-mm-HH" this function also checks if any values are lower
            // than 10 if so the function will print a leading 0
            // A common call to this fucntion will look something like this:
            // DS3231 object.print_Date_Time(unsigned char your_Date_buffer[], unsigned char your_time_buffer[]);
void DS3231::print_Date_Time(unsigned char date[],unsigned char time[]){
    //Print date
    if(convert_bin_to_dec(date[0]) < 10){ hwlib::cout<<'0';}
    hwlib::cout<<convert_bin_to_dec(date[0]);
    if(convert_bin_to_dec(date[1]) < 10){hwlib::cout<<'0';}
    hwlib::cout<<convert_bin_to_dec(date[1]);
    if(convert_bin_to_dec(date[2] < 10)){hwlib::cout<<'0';}
    hwlib::cout<<convert_bin_to_dec(date[2])<<" ";
    
    //Print time 
    if(convert_bin_to_dec(time[2]) < 10){hwlib::cout<<"0";}
    hwlib::cout<< convert_bin_to_dec(time[2])<<':';
    if(convert_bin_to_dec(time[1]) < 10){hwlib::cout<<"0";}
    hwlib::cout<< convert_bin_to_dec(time[1])<<':';
    if(convert_bin_to_dec(time[0]) < 10){hwlib::cout<<"0";}
    hwlib::cout<< convert_bin_to_dec(time[0]);
}