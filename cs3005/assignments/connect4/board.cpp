#include "board.h"
#include "rectangle.h"

std::vector<Rectangle*> h_lines (7);
std::vector<Rectangle*> v_lines (8);
Board::Board()
{
  double x1 = 200;
  double y1 = 50;
  double x2 = 202;
  double y2 = 470;
  for(unsigned int i=0; i<8; i++)
  {
    v_lines.push_back(new Rectangle(x1, y1, x2, y2));
    x1 = x1 + 70;
    x2 = x2 + 70;
  }
  x1 = 200;
  y1 = 50;
  x2 = 690;
  y2 = 52;
  for(unsigned int j=0; j<7; j++)
  {
    h_lines.push_back(new Rectangle(x1, y1, x2, y2));
    y1 = y1 + 70;
    y2 = y2 + 70;
  }
}

bool Board::Draw()
{
  for(unsigned int i=0; i<v_lines.size(); i++)
  {
    v_lines[i]->draw();
  }
  for(unsigned int j=0; j<h_lines.size(); j++)
  {
    h_lines[j]->draw();
  }
  return true;
}