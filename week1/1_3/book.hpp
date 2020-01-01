#ifndef BOOK_HPP
#define BOOK_HPP

#include <iostream>
#include <string>


class book {
private:
   std::string text;
   std::string author;
   std::string title;

   void print_text();
   void print_author();
   void print_title();

public:

   book(
      const std::string & text,
      const std::string & author,
      const std::string & title
   ):

      text( text ),
      author( author ),
      title( title )
   {}

   void print();
};

#endif // BOOK_HPP
