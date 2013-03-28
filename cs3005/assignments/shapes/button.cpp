#include "button.h"
#include "glut.h"
#include "shapes.h"
#include <iostream>
#include <string>

Button::Button(double x1_in, double y1_in, double x2_in, double y2_in, char *title_in, int id_in)
  : Rectangle(x1_in, y1_in, x2_in, y2_in)
{
  title = title_in;
  active = false;
  id = id_in;
}

bool Button::contains(double x, double y)
{
  bool clicked = false;
  if(x > points[0] && x < points[2] && y > points[1] && y < points[3])
  {
    std::cout << "clicked inside button" << std::endl;
    clicked = true;
    Shapes::setMode(this->id);
  }

  return clicked;
}