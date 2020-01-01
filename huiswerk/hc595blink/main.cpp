// ==========================================================================
//
// This file is in the public domain.
//
// ==========================================================================

#include "hwlib.hpp"

class pin_out_invert : public hwlib::pin_out{
private:
  hwlib::pin_out & slave;

public:
  pin_out_invert( hwlib::pin_out & slave ):
    slave( slave )
  {}

  void write( bool x ) override {
    slave.write( ! x );
  }

  void flush() override {
    slave.flush();
  }
};

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
  auto invert3 = pin_out_invert( hc595.p1 );
  auto invert4 = pin_out_invert( hc595.p2 );
  auto invert5 = pin_out_invert( hc595.p3 );
  auto leds = hwlib::all( led0, led1, led2, invert3, invert4, invert5 );
  hwlib::blink( leds );
}
