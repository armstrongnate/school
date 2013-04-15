#include "board.h"
#include "rectangle.h"
#include "circle.h"
#include <iostream>
#include <cmath>

std::vector<Rectangle*> h_lines (7);
std::vector<Rectangle*> v_lines (8);
std::vector<Circle*> circles (42);
int Board::turn = 1;
int Board::pieces[8][7]; // 0 for empty, 1 for red, 2 for black
int points_count;
bool counted[8][7];

void ResetCounted()
{
  for(unsigned int c=0; c<8; c++)
  {
    for(unsigned int r=0; r<7; r++)
      counted[c][r] = false;
  }
}

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

int getBottomRow(int col)
{
  for(int i=1; i<7; i++)
  {
    if(!Board::pieces[i][col])
      return i;
  }
}

bool Board::DrawCircle(double x1, double y1)
{
  int row = ceil((y1-50)/70);
  int col = ceil((x1-200)/70);
  row = getBottomRow(col);
  Board::pieces[row][col] = Board::turn;
  double top = row*70+50;
  double right = col*70+200;
  circles.push_back(new Circle(right-35, top-35, right-15, top-15));
  ResetCounted();
  Board::CheckForWin(row, col);
}

void Board::DrawCircles()
{
  for(unsigned int i=0; i<circles.size(); i++)
  {
    circles[i]->draw();
  }
}

bool CheckForWin_R(int row, int col, int dir)
{
  if(row < 1 || row > 6 || col < 1 || col > 7)
  {
    return false;
  }
  if(Board::pieces[row][col] == Board::turn)
  {
    if(points_count == 3)
    {
      std::cout << "WINNER FOUND" << std::endl;
      return true;
    }
    if(!counted[row][col])
    {
      points_count += 1;
      counted[row][col] = true;
      switch (dir)
      {
        case 0:
          CheckForWin_R(row+1, col, dir);
          break;
        case 1:
          CheckForWin_R(row-1, col+1, dir);
          break;
        case 2:
          CheckForWin_R(row, col+1, dir);
          break;
        case 3:
          CheckForWin_R(row+1, col+1, dir);
          break;
        case 4:
          CheckForWin_R(row+1, col, dir);
          break;
        case 5:
          CheckForWin_R(row-1, col-1, dir);
          break;
        case 6:
          CheckForWin_R(row, col-1, dir);
          break;
        case 7:
          CheckForWin_R(row+1, col-1, dir);
          break;
      }
    }
  }
  //std::cout << "points count: " << points_count << std::endl;
  return false;
}

void Board::CheckForWin(int row, int col)
{
  bool win;
  if(pieces[row+1][col] == Board::turn)
  {
    points_count = 1;
    win = CheckForWin_R(row+1, col, 0);
  }
  if(pieces[row-1][col+1] == Board::turn)
  {
    points_count = 1;
    win = CheckForWin_R(row+1, col+1, 1);
  }
  if(pieces[row][col+1] == Board::turn)
  {
    points_count = 1;
    win = CheckForWin_R(row, col+1, 2);
  }
  if(pieces[row+1][col+1] == Board::turn)
  {
    points_count = 1;
    win = CheckForWin_R(row-1, col+1, 3);
  }
  if(pieces[row-1][col] == Board::turn)
  {
    points_count = 1;
    win = CheckForWin_R(row-1, col, 4);
  }
  if(pieces[row-1][col-1] == Board::turn)
  {
    points_count = 1;
    win = CheckForWin_R(row-1, col-1, 5);
  }
  if(pieces[row][col-1] == Board::turn)
  {
    points_count = 1;
    win = CheckForWin_R(row, col-1, 6);
  }
  if(pieces[row+1][col-1] == Board::turn)
  {
    points_count = 1;
    win = CheckForWin_R(row+1, col-1, 7);
  }
}