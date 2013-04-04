#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include "shape.h"
#include <string>

class Triangle : public Shape
{

public:
  Triangle(double x1_in, double y1_in, double x2_in, double y2_in, double x3_in, double y3_in, std::vector<double> colors);
  void draw();

};

#endif