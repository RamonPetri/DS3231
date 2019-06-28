#include "user.h"

user::user(hwlib::i2c_bus_bit_banged_scl_sda & i2c,const uint8_t chipaddres,hwlib::target::pin_in&saveSetting,hwlib::target::pin_in&startSetting,hwlib::target::pin_in&addNum,hwlib::terminal_from&display):
           DS3231(i2c,chipaddres),saveSetting(saveSetting),startSetting(startSetting), addNum(addNum),display(display){}

void user::set_date_time(){
    int save = 0;
    int month = 0;
    int date = 0;
    int year = 0;
    int sec = 0;
    int min = 0;
    int hr = 0;
    display<<"\f";
        for(;;){
            
                if(save == 0){
                    display<<"\t0301";
                    display<<"seconds: ";
                    if(addNum.read()){
                        sec++;
                    }
                    else if(sec == 60) { sec = 0;};
                    display<<sec;
                    display<<hwlib::flush;
                    if(saveSetting.read()){
                        save++;
                    }
                }
                
                if(save == 1){
                    display<<"\t0301";
                    display<<"minutes: ";
                    if(addNum.read()){
                        min++;
                    }
                    else if(min == 60) { min = 0;};
                    display<<min;
                    display<<hwlib::flush;
                    if(saveSetting.read()){
                        save++;
                    }
                }
                
                if(save == 2){
                    display<<"\t0301";
                    display<<"hours: ";
                    if(addNum.read()){
                        hr++;
                    }
                   if(hr == 24) { hr = 0;};
                    display<<hr;
                    display<<hwlib::flush;
                    if(saveSetting.read()){
                        save++;
                    }
                }
            
                if(save == 3){
                    display<<"\t0301";
                    display<<"date: ";
                    
                    if(addNum.read()){
                        date++;
                    }
                    else if(date >= 31) { date = 0;};
                    display<<date;
                    display<<hwlib::flush;
                    if(saveSetting.read()){
                        save++;
                    }
                }
                
                if(save == 4){
                    display<<"\t0301";
                    display<<"month: ";
                    if(addNum.read()){
                        month++;
                    }
                    else if(month == 13) { month = 0;};
                    display<<month;
                    display<<hwlib::flush;
                    if(saveSetting.read()){
                        save++;
                    }
                }
                
                if(save == 5){
                    display<<"\t0301";
                    display<<"year: ";
                    if(addNum.read()){
                        year++;
                    }
                    else if(year == 100) { year = 0;};
                    display<<year;
                    display<<hwlib::flush;
                    if(saveSetting.read()){
                        save++;
                    }
                }
                
                if(save == 6){
                    set_Date(date,month,year);
                    set_Time(hr,min,sec);
                    display<<"\t0301";
                    display<<"saved!";
                    display<<hwlib::flush;
                    break;
                }
                
        }
}


void user::BeginSetting(){
    if(startSetting.read()){
        set_date_time();
    }
}

