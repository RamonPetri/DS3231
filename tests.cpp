#include "tests.h"
Tests::Tests(hwlib::i2c_bus_bit_banged_scl_sda & i2c, const uint8_t chipaddres, unsigned char Bin, unsigned char DecToBin,int Dec,int BinToDec):
    DS3231(i2c,chipaddres), Bin(Bin),DecToBin(DecToBin),Dec(Dec),BinToDec(BinToDec){}

bool Tests::Test_Bin_to_dec(){
    if (convert_bin_to_dec(Bin) == BinToDec){
        hwlib::cout<<"Passed ";
        return true;
    }
    else{hwlib::cout<<"Failed "<<convert_bin_to_dec(Bin)<<" ";
        return false;}
}
    
bool Tests::Test_Dec_to_bin(){
    if(convert_dec_to_bin(Dec) == DecToBin){
        hwlib::cout<<"Passed ";
        return true;
    }
    else{hwlib::cout<<"Failed "<<convert_dec_to_bin(Dec)<<" ";
        return false;}
    
}

void Tests::PrintTestResults(){
    hwlib::cout<<"Running Tests"<<hwlib::endl;
    hwlib::cout<<"Test convert bin to dec: "<<Test_Bin_to_dec()<<hwlib::endl;
    hwlib::cout<<"Test convert dec to bin: "<<Test_Dec_to_bin()<<hwlib::endl;
    hwlib::cout<<"Finished running Tests";
    hwlib::cout<<hwlib::endl;
}