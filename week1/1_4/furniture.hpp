#ifndef BOOK_HPP
#define BOOK_HPP

#include <iostream>
#include <string>

class stool {
private:
   int n_legs;
   int n_seats;

   void print_n_legs();
   void print_n_seats();

public:

   stool(
      const int & n_legs,
      const int & n_seats
   ):

      n_legs( n_legs ),
      n_seats( n_seats )
   {}

   void print();

   int getLegs();

   void removeLeg();
};

class table {
private:
   int n_legs;
   int length;
   int width;

   void print_n_legs();
   void print_length();
   void print_width();

public:

   table(
      const int & n_legs,
      const int & length,
      const int & width
   ):

      n_legs( n_legs ),
      length( length ),
      width( width )
   {}

   void print();
   void addLegs(const int amount);
};

class furniture {
private:
   stool stoolVariable1;
   stool stoolVariable2;
   stool stoolVariable3;
   stool stoolVariable4;
   table tableVariable;

   //void print_text();

public:

   furniture():
      stoolVariable1 (4, 1),
      stoolVariable2 (4, 1),
      stoolVariable3 (4, 1),
      stoolVariable4 (4, 1),
      tableVariable  (4, 10, 10)
   {}

   void print();

   void makeMoreHipster();

};

#endif // BOOK_HPP
