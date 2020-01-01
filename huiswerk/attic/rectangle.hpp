// example:
// declaration of a rectangle object that is contains four line objects

#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "hwlib.hpp"
#include "xy.hpp"

class rectangle {
private:
   window & w;
   vector start;
   vector end;
   line left;
   line right;
   line top;
   line bottom;
public:
   rectangle( window & w, const vector & start, const vector & end )
      w( w ),
      start( start ),
      end( end ),
      left(   w, vector( start.x, start.y ), vector( start.x, end.y   ) ),
      right(  w, vector( end.x,   start.y ), vector( end.x,   end.y   ) ),
      top(    w, vector( start.x, start.y ), vector( end.x,   start.y ) ),
      bottom( w, vector( start.x, end.y   ), vector( end.x,   end.y   ) )
   {}
   
   void print(){
      left.draw();
      right.draw();
      top.draw();
      bottom.draw();  
      w.flush();    
   }
};


#endif // RECTANGLE_HPP
