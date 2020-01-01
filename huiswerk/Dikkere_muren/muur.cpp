#include "muur.hpp"
#include <hwlib.hpp>

rectangle::rectangle( hwlib::window & w, const hwlib::xy & location, const hwlib::xy & size, hwlib::xy bounce):
  drawable( w, location, size, bounce )
{}

void rectangle::draw() {
  for(int i = location.x; i <= size.x; i++)
  {
    for(int j = location.y; j <= size.y; j++)
    {
      w.write( hwlib::xy(i, j) );
    }
  }
  w.flush();
}
 //============================================================================

 drawable::drawable( hwlib::window & w, const hwlib::xy & location, const hwlib::xy & size, hwlib::xy bounce ):
    w( w ),
    location( location ),
    size( size ),
    bounce( bounce )
 {}

 void drawable::draw(){}
 void drawable::update(){}
 void drawable::interact( drawable & other ){}

 hwlib::ostream & drawable::print( hwlib::ostream & out ) const {
    return out << location << " " << ( location + size );
 }

 hwlib::ostream & operator<<( hwlib::ostream & lhs, const drawable & rhs ){
   return rhs.print( lhs );
 }

 bool drawable::within( int x, int a, int b ){
   return ( x >= a ) && ( x <= b );
 }

 bool drawable::overlaps( const drawable & other ){

   bool x_overlap = within(
     location.x,
     other.location.x,
     other.location.x + other.size.x
   ) || within(
     other.location.x,
     location.x,
     location.x + size.x
   );

   bool y_overlap = within(
     location.y,
     other.location.y,
     other.location.y + other.size.y
   ) || within(
     other.location.y,
     location.y,
     location.y + size.y
   );

   return x_overlap && y_overlap;
}

//=============================================================================

line::line( hwlib::window & w, const hwlib::xy & location, const hwlib::xy & end ):
   drawable( w, location, end - location ),
   end( end )
{}

void line::draw() {
   hwlib::line x( location, end );
   x.draw( w );;
}

//=============================================================================

circle::circle( hwlib::window & w, const hwlib::xy & midpoint, int radius ):
   drawable( w,
      midpoint - hwlib::xy( radius, radius ),
      hwlib::xy( radius, radius ) * 2 ),
   radius( radius )
{}

void circle::draw() {
   hwlib::circle c( location + hwlib::xy( radius, radius ), radius );
   c.draw( w );
}

//=============================================================================

ball::ball(
   hwlib::window & w,
   const hwlib::xy & midpoint,
   int radius,
   const hwlib::xy & speed
):
   circle( w, midpoint, radius ),
   speed( speed )
{}

void ball::update() {
   location = location + speed;
}

void ball::interact( drawable & other ) {
   if( this != & other){
      if( overlaps( other )){
         speed.x *= other.bounce.x;
         speed.y *= other.bounce.y;
      }
   }
}

//=============================================================================

wall::wall( hwlib::window & w, const hwlib::xy & location, const hwlib::xy & size, hwlib::xy bounce = hwlib::xy(1, 1) ):
  rectangle( w, location, size, bounce ),
  filled( 0 ),
  update_interval( 20 ),
  update_count( 0 )
{}

void wall::draw(){
  for(int i = location.x; i <= size.x; i++)
  {
    for(int j = location.y; j <= size.y; j++)
    {
      if(i == location.x || i == size.x || j == location.y || j == size.y || filled)
      {
        w.write( hwlib::xy(i, j) );
      }
    }
  }
  w.flush();
}

void wall::update(){
  if(update_count == update_interval){
    filled = !filled;
    update_count = 0;
  }else{
    update_count++;
  }
}
