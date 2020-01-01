// ==========================================================================
//
// This file is in the public domain.
//
// ==========================================================================

#include "hwlib.hpp"
#include <array>

int main( void ){
  int counter = 0;
  bool direction = 1;
   // hwlib will kill the watchdog

  auto a = hwlib::target::pin_in_out( 0, 10 );
  auto b = hwlib::target::pin_in_out( 0, 11 );
  auto c = hwlib::target::pin_in_out( 0, 12 );
  auto d = hwlib::target::pin_in_out( 0, 13 );

  std::array< hwlib::target::pin_in_out*, 4 > leds = { &a, &b, &c, &d };

   for( hwlib::target::pin_in_out* & p : leds )
   {
       p->direction_set_output();
       p->direction_flush();
   }

   for(;;)
   {
      leds[counter]->write( 1 );
      leds[counter]->flush();
      leds[counter + 1]->write( 1 );
      leds[counter + 1]->flush();
      hwlib::wait_ms( 200 );
      leds[counter]->write( 0 );
      leds[counter]->flush();
      leds[counter + 1]->write( 0 );
      leds[counter + 1]->flush();
      if(direction)
      {
        counter++;
      }else
      {
        counter--;
      }
      if(counter == 0 || counter == leds.size()-2)
      {
        direction = !direction;
      }
   }
}
