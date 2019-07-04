#ifndef TESTS_H
#define TESTS_H
#include "hwlib.hpp"
#include "DS3231.h"
///\brief ///The Tests class to test DS3231 functions
///\details /// This class inherits form DS3231 and there for requires hwlib to operate 
            /// This class is written as a tests class
            /// and contains tests that will check certain functions
            /// of the DS3231 class when the program is flashed to arduino Due
            /// This class contains pre-defined test parameters to ensure functionality of the DS3231 class
            /// It is best to comment out the test constructor + call in the main program when one wants to use a display
            /// with this library since this test writes and reads date registers witch may interfere with normal operations 
class Tests : public DS3231{
#define binValue 0b01100101
#define decTobinValue 0b00011001
#define decValue 19
#define binTodecValue 65
#define Day 7
#define Month 11
#define Year 19
#define Sec 15
#define Min 30
#define Hour 18
private:
hwlib::i2c_bus_bit_banged_scl_sda & i2c;
const uint8_t chipaddres;
int testSec;
int testMin;
int testHr;
int testDay;
int testMonth;
int testYear;
unsigned char Bin;
unsigned char DecToBin;
int Dec;
int BinToDec;
unsigned char Date[];
unsigned char Time[];
public:
    Tests(hwlib::i2c_bus_bit_banged_scl_sda & i2c, const uint8_t chipaddres, unsigned char Date[], unsigned char Time[],
    int testSec=Sec,int testMin=Min,int testHr=Hour,int testDay=Day, int testMonth=Month, int testYear=Year,unsigned char Bin=binValue, 
    unsigned char DecToBin=decTobinValue,int Dec=decValue,int BinToDec=binTodecValue);
    void PrintTestResults();
    bool Test_Bin_to_dec();
    bool Test_Dec_to_bin();
    bool Test_write_read_date();
    bool Test_write_read_time();
    
};

#endif
