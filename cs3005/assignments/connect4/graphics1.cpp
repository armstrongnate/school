// OpenGL/GLUT starter kit for Windows 7 and Visual Studio 2010
// Created spring, 2011
//
// This is a starting point for OpenGl applications.
// Add code to the "display" function below, or otherwise
// modify this file to get your desired results.
//
// For the first assignment, add this file to an empty Windows Console project
//		and then compile and run it as is.
// NOTE: You should also have glut.h,
// glut32.dll, and glut32.lib in the directory of your project.
// OR, see GlutDirectories.txt for a better place to put them.

#include "board.h"
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>
#include <fstream>
#include "shapes.h"
#include "rectangle.h"
#include "circle.h"
#include "triangle.h"
#ifdef _WIN32
#include "glut.h"
#else
#include <GL/glut.h>
#endif


// Global Variables (Only what you need!)
double screen_x = 1000;
double screen_y = 500;

std::string filename = "out.txt";
std::vector<Shape*> shapes_vector;
std::vector<int> clicks;
std::vector<Shape*> feedback;
double red = 1;
double green = 0;
double blue = 0;
std::vector<double> button_colors;
unsigned int i;
Board* board = new Board();

//
// Functions that draw basic primitives
//
void DrawCircle(double x1, double y1, double radius)
{
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

void DrawRectangle(double x1, double y1, double x2, double y2)
{
  glBegin(GL_QUADS);
  glVertex2d(x1,y1);
  glVertex2d(x2,y1);
  glVertex2d(x2,y2);
  glVertex2d(x1,y2);
  glEnd();
}

void DrawTriangle(double x1, double y1, double x2, double y2, double x3, double y3)
{
  glBegin(GL_TRIANGLES);
  glVertex2d(x1,y1);
  glVertex2d(x2,y2);
  glVertex2d(x3,y3);
  glEnd();
}

// Outputs a string of text at the specified location.
void DrawText(double x, double y, const char *string)
{
  void *font = GLUT_BITMAP_9_BY_15;

  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_BLEND);

  int len, i;
  glRasterPos2d(x, y);
  len = (int) strlen(string);
  for (i = 0; i < len; i++)
    {
      glutBitmapCharacter(font, string[i]);
    }

  glDisable(GL_BLEND);
}

void createButtons()
{
  int left = 25;
  int length = 100;
  int height= 30;
  int rectangle_x = 25;
  int circle_x = 75;
  int triangle_x = 125;

  Shapes::buttons[0] = new Button(screen_x-25-100, 25, screen_x-25, 55, "Quit", 3);
  Shapes::buttons[1] = new Button(screen_x-25-100, 65, screen_x-25, 95, "Clear", 4);
  Shapes::buttons[2] = new Button(screen_x-25-100, 105, screen_x-25, 145, "Undo", 9);
  Shapes::buttons[3] = new Button(screen_x-25-100, 155, screen_x-25, 185, "Load", 13);
  Shapes::buttons[4] = new Button(screen_x-25-100, 195, screen_x-25, 225, "Save", 25);
}

void drawButtons()
{
  int left = 25;
  int text_padding_left = 5;
  int text_padding_bottom = 10;

  for(i=0; i<Shapes::buttons.size(); i++)
  {
    glColor3d(2,0,0);
    Shapes::buttons[i]->draw();
    if (Shapes::buttons[i]->active)
    {
      glColor3d(0,1,0);
    }
    else
    {
      glColor3d(0,0,0);
    }
    DrawText(Shapes::buttons[i]->points[0]+text_padding_left, Shapes::buttons[i]->points[1]+text_padding_bottom, Shapes::buttons[i]->title);
  }
}

void drawFeedback()
{
  glColor3d(0,0,0);
  for(i=0; i<feedback.size(); i++)
  {
    feedback[i]->draw();
  }
}

void drawShapes()
{
  glColor3d(red, green, blue);
  for(i=0; i<shapes_vector.size(); i++)
  {
    if(shapes_vector[i]->active)

    {
      shapes_vector[i]->draw();
    }
  }
}

void clearShapes()
{
  for(i=0; i<shapes_vector.size(); i++)
    shapes_vector.pop_back();
}

//
// GLUT callback functions
//

// This callback function gets called by the Glut
// system whenever it decides things need to be redrawn.
void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  board->Draw();
  board->DrawCircles();
  drawFeedback();
  drawShapes();
  drawButtons();
  glutSwapBuffers();
}

// This callback function gets called by the Glut
// system whenever a key is pressed.
void keyboard(unsigned char c, int x, int y)
{
  switch (c)
    {
    case 'q':
    case 27: // escape character means to quit the program
      exit(0);
      break;
    case 'b':
      // do something when 'b' character is hit.
      break;
      /*
    case 'r':
      switch_to_rectangle_mode();
      break;
      */
    default:
      return; // if we don't care, return without glutPostRedisplay()
    }

  glutPostRedisplay();
}


// This callback function gets called by the Glut
// system whenever the window is resized by the user.
void reshape(int w, int h)
{
  // Reset our global variables to the new width and height.
  screen_x = w;
  screen_y = h;

  // Set the pixel resolution of the final picture (Screen coordinates).
  glViewport(0, 0, w, h);

  // Set the projection mode to 2D orthographic, and set the world coordinates:
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, w, 0, h);
  glMatrixMode(GL_MODELVIEW);

}

void changeTurn()
{
  if(Board::turn == 1)
  {
    Board::turn = 2;
  }
  else if(Board::turn == 2)
  {
    Board::turn = 1;
  } else {
    std::cout << "Wrong turn number: " << Board::turn << std::endl;
  }
}

// This callback function gets called by the Glut
// system whenever any mouse button goes up or down.
void mouse(int mouse_button, int state, int x, int y)
{
  // translate pixel coordinates to display coordinates
  double xdisplay = x;
  double ydisplay = screen_y - y;
  if (mouse_button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
      // check if it was a button click
      for(i=0; i<Shapes::buttons.size(); i++)
      {
        // if it was the clear button, clear shapes from screen
        if(Shapes::buttons[i]->contains(xdisplay, ydisplay) && Shapes::buttons[i]->id == 4)
        {
          shapes_vector.clear();
          return;
        }
        // if it was the undo button, de-activate last shape in shapes_vector
        if(Shapes::buttons[i]->contains(xdisplay, ydisplay) && Shapes::buttons[i]->id == 9)
        {
          shapes_vector.pop_back();
          return;
        }

        if(Shapes::buttons[i]->contains(xdisplay, ydisplay))
          return;
      }

      if(xdisplay > 200 && xdisplay < 690 && ydisplay > 50 && ydisplay < 470)
      {
        board->DrawCircle(xdisplay, ydisplay);
        changeTurn();
      }

    }
  if (mouse_button == GLUT_LEFT_BUTTON && state == GLUT_UP)
    {
    }
  if (mouse_button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
    {
    }
  if (mouse_button == GLUT_MIDDLE_BUTTON && state == GLUT_UP)
    {
    }
  glutPostRedisplay();
}

// Your initialization code goes here.
void InitializeMyStuff()
{
  Shapes::mode = -1;
  button_colors.push_back(1);
  button_colors.push_back(0);
  button_colors.push_back(0);
  createButtons();
}


int main(int argc, char **argv)
{
  glutInit(&argc, argv);

  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(screen_x, screen_y);
  glutInitWindowPosition(50, 50);

  int fullscreen = 0;
  if (fullscreen)
    {
      glutGameModeString("800x600:32");
      glutEnterGameMode();
    }
  else
    {
      glutCreateWindow("This appears in the title bar");
    }

  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutReshapeFunc(reshape);
  glutMouseFunc(mouse);

  glColor3d(0,0,0); // forground color
  glClearColor(1, 1, 1, 0); // background color
  InitializeMyStuff();

  glutMainLoop();

  return 0;
}
