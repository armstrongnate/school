#ifndef _SHAPES_H_
#define _SHAPES_H_

#include "button.h"
#include <iostream>
#include <vector>

class Shapes
{

public:
  Shapes();
  static void setMode(int id_in);
  static bool setColors(double index, double color);
  static int mode;
  static std::vector<Button*> buttons;
  static std::vector<double> colors;
};

#endif