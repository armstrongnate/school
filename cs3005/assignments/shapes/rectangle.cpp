#include "rectangle.h"
#include "glut.h"
#include <iostream>

Rectangle::Rectangle(double x1_in, double y1_in, double x2_in, double y2_in, std::vector<double> colors)
  : Shape(colors)
{
  shape_id = 40;
  points.push_back(x1_in);
  points.push_back(y1_in);
  points.push_back(x2_in);
  points.push_back(y2_in);
}

void Rectangle::draw()
{
  double x1, x2, y1, y2;
  x1 = points[0];
  y1 = points[1];
  x2 = points[2];
  y2 = points[3];
  glColor3d(colors[0], colors[1], colors[2]);
  glBegin(GL_QUADS);
  glVertex2d(x1,y1);
  glVertex2d(x2,y1);
  glVertex2d(x2,y2);
  glVertex2d(x1,y2);
  glEnd();
}