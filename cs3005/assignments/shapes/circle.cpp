#include "circle.h"
#include "glut.h"
#include <iostream>
#include <cmath>

Circle::Circle(double x1_in, double y1_in, double x2_in, double y2_in, std::vector<double> colors)
  : Shape(colors)
{
  shape_id = 60;
  points.push_back(x1_in);
  points.push_back(y1_in);
  points.push_back(x2_in);
  points.push_back(y2_in);
}

void Circle::draw()
{
  double x1 = points[0];
  double y1 = points[1];
  double x2 = points[2];
  double y2 = points[3];
  double radius = sqrt(pow((x2-x1),2)+pow((y2-y1),2));

  glColor3d(colors[0], colors[1], colors[2]);
  glBegin(GL_POLYGON);
  for(int i=0; i<32; i++)
    {
      double theta = (double)i/32.0 * 2.0 * 3.1415926;
      double x = x1 + radius * cos(theta);
      double y = y1 + radius * sin(theta);
      glVertex2d(x, y);
    }
  glEnd();
}