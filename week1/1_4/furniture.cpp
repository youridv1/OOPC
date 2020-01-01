#include <iostream>
#include "furniture.hpp"

void stool::print(){
   print_n_legs();
   print_n_seats();
}

void stool::print_n_legs(){
   std::cout << n_legs << "\n";
}

void stool::print_n_seats(){
   std::cout << n_seats << "\n";
}

void table::print(){
   print_n_legs();
   print_length();
   print_width();
}

void table::print_n_legs(){
   std::cout << n_legs << "\n";
}

void table::print_length(){
   std::cout << length << "\n";
}

void table::print_width(){
   std::cout << width << "\n";
}

void furniture::print(){
  stoolVariable1.print();
  stoolVariable2.print();
  stoolVariable3.print();
  stoolVariable4.print();
  tableVariable.print();
}

void furniture::makeMoreHipster(){

  int accLegs = 0;

  if(stoolVariable1.getLegs() > 0)
  {
    stoolVariable1.removeLeg();
    accLegs++;
  }
  if(stoolVariable2.getLegs() > 0)
  {
    stoolVariable2.removeLeg();
    accLegs++;
  }
  if(stoolVariable3.getLegs() > 0)
  {
    stoolVariable3.removeLeg();
    accLegs++;
  }
  if(stoolVariable4.getLegs() > 0)
  {
    stoolVariable4.removeLeg();
    accLegs++;
  }

  tableVariable.addLegs(accLegs);
  std::cout << "MAKE OVER" << std::endl;

}

int stool::getLegs(){
  return n_legs;
}

void stool::removeLeg(){
  n_legs--;
}

void table::addLegs(const int amount){
  n_legs += amount;
}
