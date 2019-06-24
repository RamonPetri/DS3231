#include "DS3231.h"
DS3231::DS3231(hwlib::target::pin_oc & data, hwlib::target::pin_oc & clock, const uint8_t chipaddres):
    data(data),clock(clock),chipaddres(chipaddres){}

uint8_t DS3231::convert_bin_to_dec(uint8_t value){
        return ((value/16*10) + (value%16));
    }

uint8_t DS3231::convert_dec_to_bin(int value){
        return ( ( value/10*16)+(value%10));
    }

void DS3231::set_Time(int hour, int minute, int second){
   auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda(clock,data );
   const uint8_t writeBuff[4] = {0x00, convert_dec_to_bin(hour),
                                convert_dec_to_bin(minute), 
                                convert_dec_to_bin(second)};
   hwlib::i2c_write_transaction(i2c_bus,chipaddres).write(writeBuff,4);
}

unsigned char* DS3231::get_Time(unsigned char time[]){
    auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda(clock,data );
    hwlib::i2c_write_transaction(i2c_bus, chipaddres).write(0x00);
    time[0] = hwlib::i2c_read_transaction(i2c_bus,chipaddres).read_byte();
    hwlib::i2c_write_transaction(i2c_bus, chipaddres).write(0x01);
    time[1] = hwlib::i2c_read_transaction(i2c_bus,chipaddres).read_byte();
    hwlib::i2c_write_transaction(i2c_bus, chipaddres).write(0x02);
    time[2] = hwlib::i2c_read_transaction(i2c_bus,chipaddres).read_byte();
    return time;
}

void DS3231::print_Time(unsigned char time[]){
    hwlib::cout<< convert_bin_to_dec(time[2]);
    if(convert_bin_to_dec(time[2]) < 10){hwlib::cout<<"0";}
    hwlib::cout<<':';
    if(convert_bin_to_dec(time[1]) < 10){hwlib::cout<<"0";}
    hwlib::cout<< convert_bin_to_dec(time[1]);
    hwlib::cout<<':';
    if(convert_bin_to_dec(time[0]) < 10){hwlib::cout<<"0";}
    hwlib::cout<< convert_bin_to_dec(time[0]);
    hwlib::cout<<hwlib::endl;
}
