// example:
// a rectangle object that is contains four line objects

#include <iostream>
#include "rectangle.hpp"

int main(int argc, char **argv){
   // the window in which we want to print the line
   hwlib::target::window w( 256, 256 );
   hwlib::target::window n( 256, 256 );

   kar otto( w, 1 );
   otto.print();

   kar utto( n, 0 );
   utto.print();

   // keep the window around until we close it
   for(;;){ w.poll(); }
   for(;;){ n.poll(); }

}
