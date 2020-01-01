//All function definitions needed to create the rectangle, circle and kar.
#include "rectangle.hpp"

//Constructor for rectangle
rectangle::rectangle( hwlib::window & w, int start_x, int start_y, int end_x, int end_y, int red, int blue, int green ):
   w( w ),
   start_x( start_x ),
   start_y( start_y ),
   end_x( end_x ),
   end_y( end_y ),
   red( red ),
   blue( blue ),
   green( green )
{}

//Rectangle printer which uses a for loop to scan past all given pixels to colour them.
void rectangle::print()
{
   for(int i = start_x; i <= end_x; i++)
   {
     for(int j = start_y; j <= end_y; j++)
     {
       hwlib::color col(red, blue, green);
       hwlib::xy coord(i, j);
       w.write(coord, col);
     }
   }
   w.flush();
}

//Constructor for circle.
circle::circle( hwlib::window & w, int mid_x, int mid_y, int radius, int red, int green, int blue):
  w( w ),
  mid_x( mid_x ),
  mid_y( mid_y ),
  radius( radius ),
  red( red ),
  blue( blue ),
  green( green )
{}

//Printer for circle which uses two for loops and an if statement.
//It determines whether a given pixel is within the given radius from the given center coordinate.
//A pixel gets coloured when within the boundaries of this condition.
void circle::print()
{
  for(int i = mid_x - radius; i <= mid_x + radius; i++)
  {
    for(int j = mid_y - radius; j <= mid_y + radius; j++)
    {
      if(abs(i-mid_x)*abs(i-mid_x) + abs(j-mid_y)*abs(j-mid_y) < radius*radius)
      {
        hwlib::color col(red, blue, green);
        hwlib::xy coord(i, j);
        w.write(coord, col);
      }
    }
  }
  w.flush();
}

//Printer for kar.
//Calls all print functions needed to draw the kar.
void kar::print()
{
  body.print();
  cabin.print();
  window1.print();
  window2.print();
  fw.print();
  rw.print();
  bestuurder.print();
  hoofd.print();
}

//Constructor for kar.
//Uses an if statement to evaluate the given "aanwezig" boolean.
//Determines if the driver should be shown.
kar::kar( hwlib::window & w, const bool & aanwezig ):
  w( w ),
  body( w, 50, 70, 200, 100, 0, 0, 255),
  cabin( w, 75, 50, 200, 75, 0, 0, 255),
  window1( w, 80, 55, 140, 70, 255, 255, 255),
  window2( w, 145, 55, 195, 70, 255, 255, 255),
  bestuurder( w, 105, 67, 115, 70, 1, 1, 1),
  fw( w, 75, 100, 20, 1, 1, 1),
  rw( w, 175, 100, 20, 1, 1, 1),
  hoofd( w, 110, 60, 5, 1, 1, 1)
{
  if(!aanwezig)
  {
    hoofd.weg();
    bestuurder.weg();
  }
}

//Makes circles white.
void circle::weg()
{
  red = 255;
  blue = 255;
  green =255;
}

//Makes rectangles white
void rectangle::weg()
{
  red = 255;
  blue = 255;
  green =255;
}
