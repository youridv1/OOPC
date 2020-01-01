// example:
// declaration of a line class that stores its window

#ifndef LINE_HPP
#define LINE_HPP

#include "hwlib.hpp"
#include "xy.hpp"

class line {
private:
   window & w;
   vector start;
   vector end;
 ublic:

   line( window & w, const vector & start, const vector & end ):
      w( w ),
      start( start ),
      end( end )
   {}
   void draw(){
      hwlib::line line( w, start, end );
      line.draw();
      w.flush();      
   }
};

#endif // LINE_HPP
