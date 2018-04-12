#ifndef MOVIE_HPP
#define MOVIE_HPP

#include <string>
using namespace std;

// Define the interface of Movie

class Movie{
  private:
    string title;
    int yearReleased;
  public:
    Movie();
    Movie(string, int);
    void setTitle(string);
    string getTitle();
    void setYearReleased(int);
    int getYearReleased();
    void printInfo();
};

#endif