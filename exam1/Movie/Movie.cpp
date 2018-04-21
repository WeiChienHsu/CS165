#include <iostream>
#include "Movie.hpp"
#include <string>

Movie::Movie() {
  setMovieName("");
  setYear(0000);
}

Movie::Movie(std::string thisName, int thisYear) {
  setMovieName(thisName);
  setYear(thisYear);
}

void Movie::setMovieName(std::string thisName) {
  name = thisName;
}

std::string Movie::getMovieName() {
  return name;
}

void Movie::setYear(int thisYear) {
  year = thisYear;
}

int Movie::getYear() {
  return year;
}

void Movie::printInfo() {
  std::cout << "Name: " << name << std::endl;
  std::cout << "Year: " << year << std::endl;
}

