#include "DS3231.h"
#include "tests.h"
int main( void ){
    namespace target = hwlib::target;
 
    auto scl = target::pin_oc( target::pins::scl );
    auto sda = target::pin_oc( target::pins::sda );
    uint8_t chipAddres = 0x68;
    unsigned char time[3];
    unsigned char date[3];
    DS3231 clock(sda,scl,chipAddres);
    clock.set_Time(0,0,0);
    clock.set_Date(26,6,2019);
    for(;;){
         clock.get_Time(time);
         clock.get_Date(date);
         clock.print_Date_Time(date,time);
         hwlib::wait_ms(1000);
    }
}
