#include "user.h"
///\brief ///user class constructor
///\details /// This takes a hwlib::i2c_bus_bit_banged_scl_sda
            /// wich represents the i2c bus communcation
            /// const unit8_t chipaddres wich represents the RTC i2c addres
            /// hwlib::target::pin_in&saveSetting wich represents a button,
            /// wich is used to switch to a diffrent setting Example: from minutes to hours,
            /// hwlib::target::pin_in&startSetting wich represents a button
            /// wich is used to start the set date time loop,
            /// hwlib::target::pin_in&addNum wich represents a button
            /// wich is used to increment a value Example: intrements hours with n presses of the button,
            /// hwlib::terminal_from & display wich represents the Oled display
            /// a common call to this constructor would look something like this:
            /// Display object(hwlib::i2c_bus_bit_banged_scl_sda & i2c,const uint8_t chipaddres,
            ///                hwlib::target::pin_in & saveSetting, hwlib::target::pin_in & startSetting,
            ///                hwlib::target::pin_in & addNum, hwlib::terminal_from & display);
user::user(hwlib::i2c_bus_bit_banged_scl_sda & i2c,const uint8_t chipaddres,hwlib::target::pin_in&saveSetting,hwlib::target::pin_in&startSetting,hwlib::target::pin_in&addNum,hwlib::terminal_from&display):
           DS3231(i2c,chipaddres),saveSetting(saveSetting),startSetting(startSetting), addNum(addNum),display(display){}

///\brief ///set date and time 
///\detail  /// This function will allow you to set the date and time 
            /// with a menu on the oled display you will be able to set the following:
            /// seconds,minutes,hours date,month and year.
            /// incrementation of these values is per button push or by holding down the
            /// button until de desiered value is reached values.
            /// a common call to this function would look something like this:
            /// Display object.Display_print_Date_Time(unsigned char Time[], unsigned char Date[], hwlib::terminal_from & display);
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

///\brief ///Start setting date & time 
///\detail  /// This function reads out the button that is 
            /// responsible for indicating a set date time start
            /// to an oled display as defined in the main.cpp
            /// if the function finds the button pressed
            /// it will call the set_date_time function to handle the setting
void user::BeginSetting(){
    if(startSetting.read()){
        set_date_time();
    }
}

