// example:
// a rectangle object that is contains four line objects

#include <iostream>
#include "rectangle.hpp"

int main(int argc, char **argv){
   // the window in which we want to print the line
   hwlib::target::window w( 128, 128 );

   rectangle square( w, 20, 20, 35, 70 );
   square.print();

   rectangle balk( w, 40, 50, 60, 70 );
   balk.print();

   rectangle lang( w, 65, 20, 80, 115 );
   lang.print();

   rectangle onderkant( w, 20, 100, 60, 115 );
   onderkant.print();

   // keep the window around until we close it
   for(;;){ w.poll(); }
}
