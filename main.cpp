#include "hwlib.hpp"
#include "DS3231.h"
int main( void ){
    namespace target = hwlib::target;
 
    auto scl = target::pin_oc( target::pins::scl );
    auto sda = target::pin_oc( target::pins::sda );
    uint8_t chipAddres = 0x68;
    unsigned char time[3];
    DS3231 clock(sda,scl,chipAddres);
    
    clock.set_Time(0,0,0);
    
    for(;;){
         clock.get_Time(time);
         clock.print_Time(time); // dit kan in de get time functie
         hwlib::wait_ms(1000);
    }
}
