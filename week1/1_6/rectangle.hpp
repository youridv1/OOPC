//Classes for a rectangle, a circle and a composition named kar, which vaguely resembles a car.
#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "line.hpp"

class rectangle {
private:
   hwlib::window & w;
   int start_x, start_y, end_x, end_y, red, blue, green;
public:
   rectangle( hwlib::window & w, int start_x, int start_y, int end_x, int end_y, int red, int blue, int green );
   void print();
   void weg();
};

class circle {
private:
  hwlib::window & w;
  int mid_x, mid_y, radius, red, blue, green;
public:
  circle( hwlib::window & w, int mid_x, int mid_y, int radius, int red, int green, int blue);
  void print();
  void weg();
};

class kar {
private:
  hwlib::window & w;
  rectangle body, cabin, window1, window2, bestuurder;
  circle fw, rw, hoofd;
  bool aanwezig;
public:
  kar( hwlib::window & w, const bool & aanwezig );
  void print();
};

#endif // RECTANGLE_HPP
