#include <iostream>
#include <string>
#include "Movie.hpp"
using namespace std;

Movie::Movie() {
  setTitle("Default Title");
  setYearReleased(0);
}

Movie::Movie(string title, int yearReleased) {
    setTitle(title);
    setYearReleased(yearReleased);
}

void Movie::setTitle(string titleIn) {
  title = titleIn;
}

string Movie::getTitle() {
  return title;
}

void Movie::setYearReleased(int yearIn) {
  yearReleased = yearIn;
}

int Movie::getYearReleased() {
  return yearReleased;
}

void Movie::printInfo() {
  cout << "Title is: " << title << endl;
  cout << "Released Year is: " << yearReleased << endl;
}