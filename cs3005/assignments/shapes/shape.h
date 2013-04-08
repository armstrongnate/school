#ifndef _SHAPE_H_
#define _SHAPE_H_

#include <iostream>
#include <vector>
#include <string>

class Shape
{

public:
  Shape(std::vector<double> colors_in);
  virtual void draw() = 0;
  std::vector<double> points;
  bool active;
  std::vector<double> colors;
  int shape_id;
};

#endif