#include <hwlib.hpp>
#include <array>
#include "muur.hpp"

int main(){
   hwlib::target::window w( hwlib::xy( 128, 64 ), 2 );
   wall top( w, hwlib::xy( 0,  0 ), hwlib::xy( 127,  4 ), hwlib::xy(1, -1) );
   wall right( w, hwlib::xy( 123,  0 ), hwlib::xy( 127, 63 ), hwlib::xy(-1, 1) );
   wall bottom( w, hwlib::xy( 0, 59 ), hwlib::xy( 127, 63 ), hwlib::xy(1, -1) );
   wall left( w, hwlib::xy( 0,  0 ), hwlib::xy(   4, 63 ), hwlib::xy(-1, 1) );
   ball b( w, hwlib::xy( 50, 20 ), 9, hwlib::xy( 5, 2 ) );

   std::array< drawable *, 5 > objects = { &b, &top, &left, &right, &bottom };

   for(;;){
      w.clear();
      for( auto & p : objects ){
         p->draw();
      }
      w.flush();
      hwlib::wait_ms( 0 );
      for( auto & p : objects ){
          p->update();
      }
      for( auto & p : objects ){
         for( auto & other : objects ){
            p->interact( *other );
         }
      }
   }
}
