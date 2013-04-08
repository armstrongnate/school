#include "triangle.h"
#include "glut.h"
#include <iostream>
#include <cmath>

Triangle::Triangle(double x1_in, double y1_in, double x2_in, double y2_in, double x3_in, double y3_in, std::vector<double> colors)
  : Shape(colors)
{
  shape_id = 30;
  points.push_back(x1_in);
  points.push_back(y1_in);
  points.push_back(x2_in);
  points.push_back(y2_in);
  points.push_back(x3_in);
  points.push_back(y3_in);
}

void Triangle::draw()
{
  glColor3d(colors[0], colors[1], colors[2]);
  double x1 = points[0];
  double y1 = points[1];
  double x2 = points[2];
  double y2 = points[3];
  double x3 = points[4];
  double y3 = points[5];

  glBegin(GL_TRIANGLES);
  glVertex2d(x1,y1);
  glVertex2d(x2,y2);
  glVertex2d(x3,y3);
  glEnd();
}