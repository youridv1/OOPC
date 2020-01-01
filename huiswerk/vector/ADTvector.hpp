#ifndef ADTVECTOR_HPP
#define ADTVECTOR_HPP

/// @file

/// \brief
/// victor ADT
/// \details
/// This is an ADT that implements complex values.
/// The x and y are stored as two signed integers.
/// The appropriate constructors and operators are provided.

class victor {
private:
  int x;
  int y;

public:
  /// \brief
  /// constructor from explicit values
  /// \details
  /// This constructor initializes a victor from its x and y.
  victor( const int & x, const int & y ):
    x( x ), y( y )
  {}

  /// \brief
  /// constructor without explicit values
  /// \details
  /// This constructor initializes a victor with value 0 for x and y.
  victor():
    x( 0 ), y( 0 )
  {}

  /// \brief
  /// add a victor to another victor
  /// \details
  /// This operator+ adds a victor to a victor and returns the victor.
  victor operator+( const victor & rhs ) const {
    return victor(
      x + rhs.x,
      y + rhs.y
    );
  }

  /// \brief
  /// add an integer to a victor
  /// \details
  /// This operator+ adds an integer to both components of a victor and returns the victor.
  victor operator+( const int & rhs ) const {
    return victor(
      x + rhs,
      y + rhs
    );
  }

  /// \brief
  /// add a victor to another victor
  /// \details
  /// This operator+= adds the x's and y's of two victors to their respective counterparts.
  victor operator+=( const victor & rhs ){
    x += rhs.x;
    y += rhs.y;
    return *this;
  }

  /// \brief
  /// add an integer to a victor
  /// \details
  /// This operator+= adds an integer to the x and y components of a victor.
  victor operator+=( const int & rhs ){
    x += rhs;
    y += rhs;
    return *this;
  }

  /// \brief
  /// multiply a victor by an integer
  /// \details
  /// This operator* multiplies the x and y components of a victor by an integer
  /// and returns the victor.
  victor operator*( const int & rhs ) const {
    return victor(
      x * rhs,
      y * rhs
    );
  }

  /// \brief
  /// multiply an integer by a victor
  /// \details
  /// This operator multiplies an integer by the x and y components of a victor
  /// and returns the resulting victor.
  friend victor operator*( const int & lhs, const victor & rhs ) {
    return rhs * lhs;
  }

  /// \brief
  /// multiply a victor by an integer
  /// \details
  /// This operator *= multiplies a victor by an integer.
  victor operator*=( const int & rhs ){
    x *= rhs;
    y *= rhs;
    return *this;
  }

  /// \brief
  /// output operator for a victor
  /// \details
  /// This operator<< prints a victor in the format
  /// <x, y> where both values are printed as
  /// decimal values.
  friend std::ostream & operator<<( std::ostream & lhs, const victor & rhs ){
     return lhs
        << "<"
        << rhs.x
        << ", "
        << rhs.y
        << ">";
  }

  /// \brief
  /// compare two victors
  /// \details
  /// This operator tests for equality. It returns true
  /// if and only if the x and y of both
  /// operands are equal.
  bool operator==( const victor & rhs ) const {
    return ( x == rhs.x ) && ( y == rhs.y );
  }

};

#endif
