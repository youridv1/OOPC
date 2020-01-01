// ==========================================================================
//
// This file is in the public domain.
//
// ==========================================================================

#include "hwlib.hpp"

int functionality(hwlib::port_out & leds, hwlib::target::pin_in & plus, hwlib::target::pin_in & min)
{
  int counter = 0;
  uint8_t waarde;
  for(;;)
  {
    plus.refresh();
    min.refresh();
    if(!plus.read() && counter < 4){counter++;}
    if(!min.read() && counter > 0){counter--;}
    waarde = ( 1 << counter ) - 1;
    leds.write( waarde );
    leds.flush();
    hwlib::wait_ms(100);
  }
}

int main( void ){
   // hwlib will kill the watchdog
  auto a = hwlib::target::pin_out( 0, 10 );
  auto b = hwlib::target::pin_out( 0, 11 );
  auto c = hwlib::target::pin_out( 0, 12 );
  auto d = hwlib::target::pin_out( 0, 13 );
  auto e = hwlib::target::pin_in( 0, 8 );
  auto f = hwlib::target::pin_in( 0, 9 );
  auto leds = hwlib::port_out_from( a, b, c, d );
  functionality(leds, e, f);

}
