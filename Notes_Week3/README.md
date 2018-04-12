# Introduction to Class and Objects

- Classes provide a higher level of abstraction.

- They allow us to bundle together data that define the state of an object together with the functions that act on that data to form a self-contained unit.  

- Encapsulation: Making units (whether functions or classes) as self-contained as possible.  

- Abstraction and Encapsulation are closely related concepts and are recurring themes in the field of computer science.

Once you've finished defining a class, a programmer should be able to use it as a "black box", where all they need to know about is the publicly accessible member functions that make up the interface of the class.  They should not need to know anything about the private members of the class in order to use it.  

If you later decided to change the internal data or algorithms of the class (without changing the interface), that shouldn't cause any problems for any code that uses that class.


If a file needs to use a class that is defined in another file, then it needs to #include the header (.hpp) file for that class.  In the example below, both Movie.cpp and the file that contains the main function need to know about the interface for the Movie class, so both of those files need to #include "Movie.hpp".  You should never #include any .cpp files - only header files.

#### Movie.hpp
```c
#ifndef MOVIE_HPP
#define MOVIE_HPP

#include <string>

// Defines the interface of the Movie class
class Movie
{
private:
    std::string title;
    std::string director;
    int yearReleased;
    int lengthInMinutes;
public:
    Movie();
    Movie(std::string, std::string, int, int);
    void setTitle(std::string);
    std::string getTitle();
    void setDirector(std::string);
    std::string getDirector();
    void setYearReleased(int);
    int getYearReleased();
    void setLengthInMinutes(int);
    int getLengthInMinutes();
    void printInfo();
};
#endif
```
#### Movie.cpp
```c
#include <iostream>
#include <string>
#include "Movie.hpp"

Movie::Movie()
{
    setTitle("");
    setDirector("");
    setYearReleased(0);
    setLengthInMinutes(0);
}

Movie::Movie(std::string titleIn, std::string directorIn, int yearIn, int lengthIn)
{
    setTitle(titleIn);
    setDirector(directorIn);
    setYearReleased(yearIn);
    setLengthInMinutes(lengthIn);
}

void Movie::setTitle(std::string titleIn)
{
    title = titleIn;
}

std::string Movie::getTitle()
{
    return title;
}

void Movie::setDirector(std::string directorIn)
{
    director = directorIn;
}

std::string Movie::getDirector()
{
    return director;
}

void Movie::setYearReleased(int yearIn)
{
    yearReleased = yearIn;
}

int Movie::getYearReleased()
{
    return yearReleased;
}

void Movie::setLengthInMinutes(int lengthIn)
{
    lengthInMinutes = lengthIn;
}

int Movie::getLengthInMinutes()
{
    return lengthInMinutes;
}

void Movie::printInfo()
{
    std::cout << "Title: " << title << std::endl;
    std::cout << "Director: " << director << std::endl;
    std::cout << "Year released: " << yearReleased << std::endl;
    std::cout << "Length in minutes: " << lengthInMinutes << std::endl;
    std::cout << std::endl;  // just to get a blank line
}
```

#### main method
```c
#include <iostream>
#include "Movie.hpp"

int main()
{
    Movie mov1("Sharktopus", "Charlie Chaplin", 1000, 503);
    mov1.printInfo();
    
    mov1.setDirector("Winston Churchill");
    mov1.printInfo();
    
    Movie mov2;
    mov2.printInfo();
    
    return 0;
}
```
- 如果要直接new出一個新的mov2(使用 default constructor)
- 不需要後面的括號
```
movieList.cpp:9:15: warning: empty parentheses interpreted as a function declaration [-Wvexing-parse]
    Movie mov2();
              ^~
movieList.cpp:9:15: note: remove parentheses to declare a variable
    Movie mov2();
```

#### default constructor - Movie()
This default constructor sets the data members to values that won't cause printInfo to crash, but probably shouldn't be used anyway until the set methods are used to give data members reasonable values.

The values of the data members could be set directly within the constructor, but if we keep the "setting" code localized in one place, that means any changes to that code only have to happen in one place.

Please keep straight the difference between the parameters of a constructor and the data members of an object. 

The parameters of the constructor only exist for the duration of the function call.  The data members of an object persist for the lifetime of that object. 



