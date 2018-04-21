#ifndef MOVIE_HPP
#define MOVIE_HPP
#include <string>

class Movie {
  private:
    std::string name;
    int year;
  public:
    Movie();
    Movie(std::string, int);
    void setMovieName(std::string);
    std::string getMovieName();
    void setYear(int);
    int getYear(); 
    void printInfo();
};

#endif