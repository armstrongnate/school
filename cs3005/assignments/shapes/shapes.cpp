#include <iostream>
#include <string>
#include "shape.h"
#include "shapes.h"
#include "button.h"
#include "circle.h"
#include "glut.h"
#include <cmath>

std::vector<Button*> Shapes::buttons (8);
int Shapes::mode;
std::vector<double> Shapes::colors (3);

Shapes::Shapes()
{
  mode = -1;
  colors.push_back(1);
  colors.push_back(0);
  colors.push_back(0);
}

void Shapes::setMode(int id_in)
{
  mode = id_in;
  for(unsigned int i=0; i<buttons.size(); i++)
  {
    if(buttons[i]->id == id_in)
      buttons[i]->active = true;
    else
      buttons[i]->active = false;
  }
}

bool Shapes::setColors(double index, double color)
{
  colors[index] = color;
  return true;
}