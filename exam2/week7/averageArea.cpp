#include <cmath>
#include <vector>

#include "Shape.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"

using std::vector;

double averageArea(vector<Shape*> shapes)
{
    double average = -1;

    for (int i=0; i < shapes.size(); i++)
    {
        average += shapes[i]->area();
    }
    average /= shapes.size();
    return average;
}
