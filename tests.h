#ifndef TESTS_H
#define TESTS_H
#include "hwlib.hpp"
class Tests{
private:
unsigned char Bin;
unsigned char DecToBin;
int Dec;
int BinToDec;
bool Test_Bin_to_dec();
bool Test_Dec_to_bin();
public:
    Tests(unsigned char Bin, unsigned char DecToBin,int Dec,int BinToDec);
    void PrintTestResults();
    
};

#endif