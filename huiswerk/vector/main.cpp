#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "ostream"
#include "ADTvector.hpp"

TEST_CASE( "constructor, two_parameters" ){
   victor v( 3, 4 );
   std::stringstream s;
   s << v;
   REQUIRE( s.str() == "<3, 4>" );
}

TEST_CASE( " addition of two victors" ){
  victor v( 1, 4 );
  victor x( 2, 3 );
  victor z = v + x;
  REQUIRE( z == victor( 3, 7 ) );
}

TEST_CASE( " addition of an integer to a victor " ){
  victor v( 1, 4 );
  victor z = v + 1;
  REQUIRE( z == victor( 2, 5 ) );
}

TEST_CASE( " increasing a victor by adding a victor " ){
  victor v( 1, 4 );
  victor z( 3, 7 );
  z += v;
  REQUIRE( z == victor( 4, 11 ) );
}

TEST_CASE( " multiplying by an integer "){
  victor v( 1, 4 );
  victor z = v * 25;
  REQUIRE( z == victor( 25, 100 ) );
}

TEST_CASE( " multiplying by a victor "){
  victor v( 13, 37 );
  auto x = 2;
  auto z = x * v;
  REQUIRE( z == victor( 26, 74 ) );
}

TEST_CASE( "constructor, no parameters" ){
  victor v;
  std::stringstream s;
  s << v;
  REQUIRE( s.str() == "<0, 0>" );
}
