#ifndef _SHAPE_H_
#define _SHAPE_H_

#include <iostream>
#include <vector>
#include <string>

class Shape
{

public:
  virtual void draw() = 0;
  std::vector<double> points;
};

#endif