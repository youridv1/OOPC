#ifndef MUUR_HPP
#define MUUR_HPP

#include <hwlib.hpp>

class drawable {
protected:

   hwlib::window & w;
   hwlib::xy location;
   hwlib::xy size;

public:
   hwlib::xy bounce;
   drawable( hwlib::window & w, const hwlib::xy & location, const hwlib::xy & size, hwlib::xy bounce = hwlib::xy(-1, -1) );
   virtual void draw();
   virtual void update();
   bool overlaps( const drawable & other );
   virtual void interact( drawable & other );
   hwlib::ostream & print( hwlib::ostream & out ) const;
   bool within( int x, int a, int b );

};

hwlib::ostream & operator<<( hwlib::ostream & lhs, const drawable & rhs );

// ===========================================================================

class line : public drawable {
private:

   hwlib::xy end;

public:

   line( hwlib::window & w, const hwlib::xy & location, const hwlib::xy & end );
   void draw() override;
};

// ===========================================================================

class circle : public drawable {
protected:

   int radius;

public:

   circle( hwlib::window & w, const hwlib::xy & midpoint, int radius );
   void draw() override;
};

// ===========================================================================

class ball : public circle {
private:

   hwlib::xy speed;

public:

   ball(
      hwlib::window & w,
      const hwlib::xy & midpoint,
      int radius,
      const hwlib::xy & speed
   );
   void update() override;
   void interact( drawable & other ) override;
};

// ===========================================================================

class rectangle : public drawable {
public:
   rectangle( hwlib::window & w, const hwlib::xy & location, const hwlib::xy & size, hwlib::xy  bounce );
   void draw() override;
};

//============================================================================

class wall : public rectangle {
private:
  bool filled;
  int update_interval;
  int update_count;
public:
  wall( hwlib::window & w, const hwlib::xy & location, const hwlib::xy & size, hwlib::xy bounce );
  void draw() override;
  void update() override;
};

//============================================================================

class victim : public rectangle {
public:
  victim( hwlib::window & w, const hwlib::xy & location, const hwlib::xy & size, hwlib::xy  bounce );
  void draw() override;
  void interact( drawable & other ) override;
};

#endif
