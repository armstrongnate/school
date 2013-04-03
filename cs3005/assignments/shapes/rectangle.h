#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include "shape.h"
#include <string>

class Rectangle : public Shape
{

public:
  Rectangle(double x1_in, double y1_in, double x2_in, double y2_in, std::vector<double> colors);
  void draw();

};

#endif