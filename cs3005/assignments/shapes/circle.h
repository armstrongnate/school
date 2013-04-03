#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include "shape.h"
#include <string>

class Circle : public Shape
{

public:
  Circle(double x1_in, double y1_in, double x2_in, double y2_in, std::vector<double> colors);
  void draw();

};

#endif