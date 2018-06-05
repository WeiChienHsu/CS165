#ifndef HOUSEPAINT_HPP
#define HOUSEPAINT_HPP
#include <stdio.h>

enum Color {maroon, ivory, sage, periwinkle, chartreuse, cobalt, lemon};

class HousePaint {
  private:
    Color siding;
    Color trim;
  public:
    HousePaint(Color sColor, Color tColor);
    void setSiding(Color sColor);
    Color getSiding();
    void setTrim(Color tColor);
    Color getTrim();
};

#endif