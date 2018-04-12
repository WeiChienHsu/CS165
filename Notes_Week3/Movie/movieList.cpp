#include <iostream>
#include "Movie.hpp"
#include "Movie.cpp"
using namespace std;

int main() {
    Movie mov1("Happy Feet", 2012);
    mov1.printInfo();

    Movie mov2;
    mov2.printInfo();

    mov2.setTitle("Apple King");
    cout << mov2.getTitle() << endl;

    return 0;
}