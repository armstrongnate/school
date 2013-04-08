#ifndef _BUTTON_H_
#define _BUTTON_H_

#include "rectangle.h"

class Button : public Rectangle
{

public:

  Button(double x1_in, double y1_in, double x2_in, double y2_in, char *title_in, int id, std::vector<double> colors);
  char * title;
  bool contains(double x, double y);
  void drawSlider(double red, double green, double blue);
  bool active;
  int id;
};

#endif