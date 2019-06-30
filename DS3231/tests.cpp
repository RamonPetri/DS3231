#include "tests.h"

///\brief ///Tests class constructor
///\details /// This constructor takes a hwlib::i2c_bus_bit_banged_scl_sda i2c wich represnts the i2c bus,
            /// const uint8_t chipaddres wich represents the RTC addres, 
            ///unsigned char Date[] witch represents the buffer for the date,
            ///unsigned chat Time[] witch represents the buffer for the time,
            /// int testSec wich represents the predefined test parameter for the seconds, 
            /// int testMin wich reprsents the predefined test parameter for the minutes,
            /// int testHr wich represents the predefined test parameter for the hours,
            /// int testDay wich represents the predefined test parameter for the day, 
            /// int testMonth wich reprsents the predefined test parameter for the month,
            /// int testYear wich represents the predefined test parameter for the year,
            /// unsigned char Bin wich represents the predefined test parameter for a Binary coded decimal,
            /// unsigned char DecToBin wich represents the predefined test parameter for a Decmial converted to a binary converted decimal,
            /// int Dec wich represents the predefined test parameter for a decimal value,
            /// int BinToDec wich represents the predefined test parameter for a binary converted decmial converted to a decimal 
            /// A common call to this constructor will look something like this:
            /// Tests object(hwlib::i2c_bus_bit_banged_scl_sda, a_chipaddres, unsigned char Date[], unsigned Time[]); The rest of the values in the constructor have predefined default values
Tests::Tests(hwlib::i2c_bus_bit_banged_scl_sda & i2c, const uint8_t chipaddres, unsigned char Date[], unsigned char Time[],
    int testSec,int testMin,int testHr,int testDay, int testMonth, int testYear,unsigned char Bin, 
    unsigned char DecToBin,int Dec,int BinToDec):
    DS3231(i2c,chipaddres),i2c(i2c),chipaddres(chipaddres),testSec(testSec),testMin(testMin),testHr(testHr),
    testDay(testDay),testMonth(testMonth),testYear(testYear), Bin(Bin),DecToBin(DecToBin),Dec(Dec),BinToDec(BinToDec){}

///\brief ///Test to check the functionality of the convert_bin_to_dec function
///\details ///This function checks if after conversion by the convert_bin_to_dec function
            /// the Bin value equals that of the predefined expected BinToDec value.
            /// If this is the case the test passes otherwise it fails and prints the result of Bin
bool Tests::Test_Bin_to_dec(){
    if (convert_bin_to_dec(Bin) == BinToDec){
        hwlib::cout<<"Passed ";
        return true;
    }
    else{hwlib::cout<<"Failed "<<" output: "<<convert_bin_to_dec(Bin)<<" ";
        return false;}
}

///\brief ///Test to check the functionality of the convert_dec_to_bin function
///\details /// This function checks if after conversion by the convert_dec_to_bin function 
            /// the Dec value equals that of the predefined expected DecToBin value.
            /// If this is the case the test passes otherwise it fails and prints the result of Dec
bool Tests::Test_Dec_to_bin(){
    if(convert_dec_to_bin(Dec) == DecToBin){
        hwlib::cout<<"Passed ";
        return true;
    }
    else{hwlib::cout<<"Failed "<<" output: "<<convert_dec_to_bin(Dec)<<" ";
        return false;}
    
}

///\brief ///Test to check the functionality of the write and read functions
///\details /// This function checks the write and read functions by first
            /// writing the predefined test values of day month and year
            /// to their respective date registers after the write operation
            /// a read operation is used to read out the date registers and store this in the 
            /// unsigned char Date[] varible. The test will pass when all elements of Date[]
            /// are equal to their respective predefined test values
bool Tests::Test_write_read_date(){
    const uint8_t writeBuff[4] = {0x04, convert_dec_to_bin(testDay),
                                 convert_dec_to_bin(testMonth),
                                 convert_dec_to_bin(testYear)};
    hwlib::i2c_write_transaction(i2c, chipaddres).write(writeBuff,4);
    
    hwlib::i2c_write_transaction(i2c,chipaddres).write(0x04);
    Date[0] = hwlib::i2c_read_transaction(i2c, chipaddres).read_byte();
    hwlib::i2c_write_transaction(i2c,chipaddres).write(0x05);
    Date[1] = hwlib::i2c_read_transaction(i2c, chipaddres).read_byte();
    hwlib::i2c_write_transaction(i2c, chipaddres).write(0x06);
    Date[2] = hwlib::i2c_read_transaction(i2c, chipaddres).read_byte();
    
    if(convert_bin_to_dec(Date[0]) == testDay && convert_bin_to_dec(Date[1]) == testMonth && convert_bin_to_dec(Date[2]) == testYear){
        hwlib::cout<<"Passed";
        return true;
    }
    else{hwlib::cout<<"Failed "<<" output: ";
         hwlib::cout<<" Date: "<<convert_bin_to_dec(Date[0]);
         hwlib::cout<<" Month: "<<convert_bin_to_dec(Date[1]);
         hwlib::cout<<" Year: "<<convert_bin_to_dec(Date[2]);
         return false;
    
    }
}

///\brief ///Test to check the functionality of the write and read functions
///\details /// This function checks the write and read functions by first
            /// writing the predefined test values of seconds minutes and hours
            /// to their respective date registers after the write operation
            /// a read operation is used to read out the time registers and store this in the 
            /// unsigned char Time[] varible. The test will pass when all elements of Time[]
            /// are equal to their respective predefined test values
bool Tests::Test_write_read_time(){
    const uint8_t writeBuff[4] = {0x00, convert_dec_to_bin(testSec),
                                 convert_dec_to_bin(testMin),
                                 convert_dec_to_bin(testHr)};
    hwlib::i2c_write_transaction(i2c, chipaddres).write(writeBuff,4);
    
    hwlib::i2c_write_transaction(i2c,chipaddres).write(0x00);
    Time[0] = hwlib::i2c_read_transaction(i2c, chipaddres).read_byte();
    hwlib::i2c_write_transaction(i2c,chipaddres).write(0x01);
    Time[1] = hwlib::i2c_read_transaction(i2c, chipaddres).read_byte();
    hwlib::i2c_write_transaction(i2c, chipaddres).write(0x02);
    Time[2] = hwlib::i2c_read_transaction(i2c, chipaddres).read_byte();
    
    if(convert_bin_to_dec(Time[0]) == testSec && convert_bin_to_dec(Time[1]) == testMin && convert_bin_to_dec(Time[2]) == testHr){
        hwlib::cout<<"Passed";
        return true;
    }
    else{hwlib::cout<<"Failed "<<" output: ";
         hwlib::cout<<" Date: "<<convert_bin_to_dec(Time[0]);
         hwlib::cout<<" Month: "<<convert_bin_to_dec(Time[1]);
         hwlib::cout<<" Year: "<<convert_bin_to_dec(Time[2]);
         return false;
    
    }
}

///\brief ///Test print function
///\details /// This function will print the results of each test
            /// it will either print if the test has passed or failed
            /// when a test fails this function will print the value 
            /// of any varibels that could have made the test fail
void Tests::PrintTestResults(){
    hwlib::cout<<"Running Tests"<<hwlib::endl;
    hwlib::cout<<"Test convert bin to dec: "<<Test_Bin_to_dec()<<hwlib::endl;
    hwlib::cout<<"Test convert dec to bin: "<<Test_Dec_to_bin()<<hwlib::endl;
    hwlib::cout<<"Test write/read date to ds3231: "<<Test_write_read_date()<<hwlib::endl;
    hwlib::cout<<"Test write/read time to ds3231: "<<Test_write_read_time()<<hwlib::endl;
    hwlib::cout<<"Finished running Tests";
    hwlib::cout<<hwlib::endl;
}