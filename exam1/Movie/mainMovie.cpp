#include <iostream>
#include "Movie.hpp"
#include <string>

int main() {
  Movie mv1;
  Movie mv2("Hello World", 2012);

  mv1.printInfo();
  mv1.setMovieName("Hell!!");
  mv1.setYear(123);
  mv1.printInfo();
  mv2.printInfo();
}