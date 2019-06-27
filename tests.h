#ifndef TESTS_H
#define TESTS_H
#include "hwlib.hpp"
#include "DS3231.h"
class Tests : public DS3231{
private:
unsigned char Bin;
unsigned char DecToBin;
int Dec;
int BinToDec;
bool Test_Bin_to_dec();
bool Test_Dec_to_bin();
public:
    Tests(hwlib::i2c_bus_bit_banged_scl_sda & i2c, const uint8_t chipaddres, unsigned char Bin, unsigned char DecToBin,int Dec,int BinToDec);
    void PrintTestResults();
    
};

#endif