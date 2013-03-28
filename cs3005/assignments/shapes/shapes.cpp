#include <iostream>
#include <string>
#include "shape.h"
#include "shapes.h"
#include "button.h"
#include "circle.h"
#include "glut.h"
#include <cmath>

std::vector<Button*> Shapes::buttons (3);
int Shapes::mode;

Shapes::Shapes()
{
  mode = -1;
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
