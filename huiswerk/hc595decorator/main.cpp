// ==========================================================================
//
// This file is in the public domain.
//
// ==========================================================================

#include "hwlib.hpp"

class pin_in_and : public hwlib::pin_in {
private:
  hwlib::pin_in & one;
  hwlib::pin_in & two;

public:
  pin_in_and( hwlib::pin_in & one, hwlib::pin_in & two ):
    one( one ),
    two( two )
  {}

  bool read() override {
    return !(!one.read() && !two.read());
  }
  void refresh() override {
    one.refresh();
    two.refresh();
  }
};

void functionality(hwlib::port_out & leds, pin_in_and & buttons){
  for(;;)
  {
    buttons.refresh();
    if(!buttons.read())
    {
      leds.write( (1 << 6) - 1 );
    }else{
      leds.write( 0 );
    }
    leds.flush();
    hwlib::wait_ms( 100 );
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
  auto buttons = pin_in_and( but0, but1 );

  functionality( leds, buttons );
}
