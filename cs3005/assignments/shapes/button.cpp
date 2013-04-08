#include "button.h"
#include "glut.h"
#include "shapes.h"
#include <iostream>
#include <string>

Button::Button(double x1_in, double y1_in, double x2_in, double y2_in, char *title_in, int id_in, std::vector<double> colors)
  : Rectangle(x1_in, y1_in, x2_in, y2_in, colors)
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
    clicked = true;
    if(id == 3)
    {
      exit(0);
    }
    if(id < 3)
      Shapes::setMode(this->id);
  }

  return clicked;
}

void Button::drawSlider(double red, double green, double blue)
{
  double x1, x2, y1, y2;
  x1 = points[0];
  y1 = points[1];
  x2 = points[2];
  y2 = points[3];
    glColor3d(red, green, blue);
  if(id == 4)
  {
    glColor3d(1, 0, 0);
  }
  glBegin(GL_QUADS);
  glVertex2d(x1,y1);
  glVertex2d(x2,y1);
  glVertex2d(x2,y2);
  glVertex2d(x1,y2);
  glEnd();
}