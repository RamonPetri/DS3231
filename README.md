# DS3231
this library was set up as project to finish my first year of my study ITC at Utrecht Hogeschool.
There for this repository contains two Word documents a poster and a document that discribes 
the way you will make youre library before you start building it.

This library is written for The DS3231. 

The DS3231 is a low-cost, extremely accurate I2C
real-time clock (RTC) 
The device incorporates a battery input, and maintains
accurate timekeeping when main power to the device
is interrupted. The integration of the crystal resonator
enhances the long-term accuracy of the device.

For more technical details please refer to the datasheet of the DS3231. 

The body of the two function below where reused from a diffrent project 
 as written by:
 
// Andrew W. on  15th July 2015, - arwhitus.weebly.com
// Credits to Andrew W. For sharing his sketch at https://www.instructables.com/id/Arduino-DS3231-RTC-Clock/ wich contains the origin of  the functions 

//original functions as found in the sketch written by Andrew W:
-----------------------------------------------------------------
byte decToBcd(byte val)
{
  return ( (val / 10 * 16) + (val % 10) );
}

byte bcdToDec(byte val)
{
  return ( (val / 16 * 10) + (val % 16) );
}

//Functions as found in my DS3231 library
---------------------------------------------------------------
int DS3231::convert_bin_to_dec(unsigned char value){
        return ((value/16*10) + (value%16));
}

uint8_t DS3231::convert_dec_to_bin(int value){
        return ( ( value/10*16)+(value%10));
}
