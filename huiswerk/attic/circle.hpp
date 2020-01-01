// example:
// declaration of a circle class that stores its window

#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "hwlib.hpp"
#include "xy.hpp"

class circle {
private:
   hwlib::window & w;
   xy midpoint;
   int radius;
 
public:

   circle( hwlib::window & w, const xy & midpoint, int radius ):
      w( w ),
      midpoint( midpoint ),
      radius( radius )
   {}
   
   void draw(){
      hwlib::circle c( midpoint, radius );
      c.draw( w );
      w.flush();
   }
};

#endif // CIRCLE_HPP
