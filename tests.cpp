#include "tests.h"
Tests::Tests(unsigned char Bin, unsigned char DecToBin,int Dec,int BinToDec):
    Bin(Bin),DecToBin(DecToBin),Dec(Dec),BinToDec(BinToDec){}

bool Tests::Test_Bin_to_dec(){
    if (Bin == BinToDec){
        return true;
    }
    return false;
}
    
bool Tests::Test_Dec_to_bin(){
    if(Dec == DecToBin){
        return true;
    }
    return false;
}

void Tests::PrintTestResults(){
    hwlib::cout<<"Running Tests"<<hwlib::endl;
    hwlib::cout<<"Passed Test convert bin to dec"<<Test_Bin_to_dec()<<hwlib::endl;
    hwlib::cout<<"Passed Test convert dec to bin"<<Test_Dec_to_bin()<<hwlib::endl;
    hwlib::cout<<"Finished running Tests";
    hwlib::cout<<hwlib::endl;
}