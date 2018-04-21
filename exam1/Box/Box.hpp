#ifndef BOX_HPP
#define BOX_HPP

class Box {
  private: 
    int height;
    int width;
    int length;
  public:
    Box();
    Box(int, int, int);
    void setHeight(int);
    void setWidth(int);
    void setLength(int);
    int calcVolume();
    int calcSurfaceArea();
};

#endif