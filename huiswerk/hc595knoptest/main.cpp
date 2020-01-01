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
    if(!plus.read() && counter < 6){counter++;}
    if(!min.read() && counter > 0){counter--;}
    waarde = ( 1 << counter ) - 1;
    leds.write( waarde );
    leds.flush();
    hwlib::wait_ms(100);
  }
}

int main( void ){
   // hwlib will kill the watchdog
  auto ds   = hwlib::target::pin_out( 0, 10  );
  auto stcp = hwlib::target::pin_out( 0, 11  );
  auto shcp = hwlib::target::pin_out( 0, 12  );
  auto spi_bus  = hwlib::spi_bus_bit_banged_sclk_mosi_miso(
   shcp,
   ds,
   hwlib::pin_in_dummy
  );
  auto hc595 = hwlib::hc595( spi_bus, stcp );
  auto led0 = hwlib::target::pin_out( 2, 29 );
  auto led1 = hwlib::target::pin_out( 3, 7  );
  auto led2 = hwlib::target::pin_out( 3, 8  );
  auto but0 = hwlib::target::pin_in( 0, 15 );
  auto but1 = hwlib::target::pin_in( 3, 1 );
  auto leds = hwlib::port_out_from( hc595.p1, hc595.p2, hc595.p3, led0, led1, led2);
  functionality(leds, but0, but1);
}
