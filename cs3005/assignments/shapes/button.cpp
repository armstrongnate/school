#include "button.h"
#include "glut.h"
#include <iostream>
#include <string>

Button::Button(double x1_in, double y1_in, double x2_in, double y2_in, char *title_in)
  : Rectangle(x1_in, y1_in, x2_in, y2_in)
{
  title = title_in;
}

bool Button::contains(double x, double y)
{
  bool clicked = false;
  std::cout << (x > points[0] && x < points[2] && y > points[1] && y < points[3]) << std::endl;
  if(x > points[0] && x < points[2] && y > points[1] && y < points[3])
  {
    std::cout << "clicked!!!" << std::endl;
    active = true;
  }

  return clicked;
}