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
double screen_x = 700;
double screen_y = 500;

std::vector<Shape*> shapes_vector;
std::vector<Button*> sliders_vector;
std::vector<int> clicks;
std::vector<Shape*> feedback;
double red = 1;
double green = 0;
double blue = 0;
std::vector<double> button_colors;
unsigned int i;
std::string filename = "out.txt";

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

  Shapes::buttons[0] = new Button(left, rectangle_x, rectangle_x+length, rectangle_x+height, "Rectangle", 0, button_colors);
  Shapes::buttons[1] = new Button(left, circle_x, left+length, circle_x+height, "Circle", 1, button_colors);
  Shapes::buttons[2] = new Button(left, triangle_x, left+length, triangle_x+height, "Triangle", 2, button_colors);
  Shapes::buttons[3] = new Button(screen_x-25-100, 25, screen_x-25, 55, "Quit", 3, button_colors);
  Shapes::buttons[4] = new Button(screen_x-25-100, 65, screen_x-25, 95, "Clear", 4, button_colors);
  Shapes::buttons[5] = new Button(screen_x-25-100, 105, screen_x-25, 145, "Undo", 9, button_colors);
  Shapes::buttons[6] = new Button(screen_x-25-100, 155, screen_x-25, 185, "Load", 13, button_colors);
  Shapes::buttons[7] = new Button(screen_x-25-100, 195, screen_x-25, 225, "Save", 25, button_colors);
}

void createSliders()
{
  // draw slider posts
  sliders_vector.push_back(new Button(30, 205, 50, 305, "", 5, button_colors));
  sliders_vector.push_back(new Button(85, 205, 105, 305, "", 6, button_colors));
  sliders_vector.push_back(new Button(140, 205, 160, 305, "", 7, button_colors));
  // draw slider dials
  sliders_vector.push_back(new Button(15, 205, 65, 215, "", 4, button_colors));
  sliders_vector.push_back(new Button(70, 205, 120, 215, "", 4, button_colors));
  sliders_vector.push_back(new Button(125, 205, 175, 215, "", 4, button_colors));

}

void drawSliders()
{
  for(i=0; i<sliders_vector.size(); i++)
  {
    sliders_vector[i]->drawSlider(Shapes::colors[0], Shapes::colors[1], Shapes::colors[2]);
  }
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
    if(shapes_vector[i]->active)std::string filename = "out.txt";

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

void write_to_file(std::string &filename)
{
  unsigned int j;
  std::ofstream fout(filename.c_str());
  if(!fout)
    {
      std::cerr << "unable to open " << "out.txt" << std::endl;
      return;
    }
  for(i=0; i<shapes_vector.size(); i++)
  {
    if(shapes_vector[i]->shape_id == 30)
    {
      fout << "Triangle";
      fout << "\n";
      for(j=0; j<shapes_vector[i]->points.size(); j++)
      {
        fout << shapes_vector[i]->points[j] << " ";
      }
      fout << "\n";
      for(j=0; j<shapes_vector[i]->colors.size(); j++)
      {
        fout << shapes_vector[i]->colors[j] << " ";
      }
      fout << "\n";
    }
    if(shapes_vector[i]->shape_id == 60)
    {
      fout << "Circle";
      fout << "\n";
      for(j=0; j<shapes_vector[i]->points.size(); j++)
      {
        fout << shapes_vector[i]->points[j] << " ";
      }
      fout << "\n";
      for(j=0; j<shapes_vector[i]->colors.size(); j++)
      {
        fout << shapes_vector[i]->colors[j] << " ";
      }
      fout << "\n";
    }
    if(shapes_vector[i]->shape_id == 40)
    {
      fout << "Rectangle";
      fout << "\n";
      for(j=0; j<shapes_vector[i]->points.size(); j++)
      {
        fout << shapes_vector[i]->points[j] << " ";
      }
      fout << "\n";
      for(j=0; j<shapes_vector[i]->colors.size(); j++)
      {
        fout << shapes_vector[i]->colors[j] << " ";
      }
      fout << "\n";
    }
  }
}

void load_file(std::string &filename)
{
	std::string shape_type;
	double x1, y1, x2, y2, x3, y3;
	double r, g, b;
  std::vector<double> colors_in (3);

  std::ifstream fin(filename.c_str());
  if(!fin)
    {
      std::cerr << "unable to open " << "out.txt" << std::endl;
      return;
    }
	while(! fin.eof())
	{
		 fin >> shape_type >> std::ws;
			if (shape_type == "Triangle")	{
				fin>>x1>>y1>>x2>>y2>>x3>>y3>>std::ws;
				fin >> r >> g >> b >> std::ws;

        colors_in[0] = r;
        colors_in[1] = g;
        colors_in[2] = b;
        shapes_vector.push_back(new Triangle(x1, y1, x2, y2, x3, y3, colors_in));
			}
			else if (shape_type == "Rectangle")	{
				fin>>x1>>y1>>x2>>y2>>std::ws;
				fin >> r >> g >> b >> std::ws;

        colors_in[0] = r;
        colors_in[1] = g;
        colors_in[2] = b;
        shapes_vector.push_back(new Rectangle(x1, y1, x2, y2, colors_in));
			}

			else if (shape_type == "Circle")	{
				fin>>x1>>y1>>x2>>y2>>std::ws;
				fin >> r >> g >> b >> std::ws;

        colors_in[0] = r;
        colors_in[1] = g;
        colors_in[2] = b;
        shapes_vector.push_back(new Circle(x1, y1, x2, y2, colors_in));
			}
	}

}

//
// GLUT callback functions
//

// This callback function gets called by the Glut
// system whenever it decides things need to be redrawn.
void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  drawFeedback();
  drawShapes();
  drawButtons();
  drawSliders();
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


        if(Shapes::buttons[i]->contains(xdisplay, ydisplay) && Shapes::buttons[i]->id == 25)
        {
          write_to_file(filename);
          return;
        }

        if(Shapes::buttons[i]->contains(xdisplay, ydisplay) && Shapes::buttons[i]->id == 13)
        {
          load_file(filename);
          return;
        }

        if(Shapes::buttons[i]->contains(xdisplay, ydisplay))
          return;
      }

      // check if clicking slider
      for(i=0; i<sliders_vector.size(); i++)
      {
        if(sliders_vector[i]->id > 4 && sliders_vector[i]->id < 8 && sliders_vector[i]->contains(xdisplay, ydisplay))
        {
          sliders_vector[i+3]->points[1] = ydisplay-5;
          sliders_vector[i+3]->points[3] = ydisplay+5;

          switch (sliders_vector[i]->id)
          {
            case 5:
              red = (ydisplay-205)/100;
              Shapes::colors[0] = red;
              return;
            case 6:
              green = (ydisplay-205)/100;
              Shapes::colors[1] = green;
              return;
            case 7:
              blue = (ydisplay-205)/100;
              Shapes::colors[2] = blue;
              return;
          }
        }
      }

      if(Shapes::mode >= 0)
      {
        feedback.push_back(new Circle(xdisplay, ydisplay, xdisplay+5, ydisplay+5, button_colors));
        clicks.push_back(x);
        clicks.push_back(ydisplay);
      }
      // otherwise, gather points for mode
      if(Shapes::mode == 0)
      {
        if(clicks.size() == 4)
        {
          feedback.clear();
          shapes_vector.push_back(new Rectangle(clicks[0], clicks[1], clicks[2], clicks[3], Shapes::colors));
          clicks.clear();
        }
      }
      else if (Shapes::mode == 1)
      {
        if(clicks.size() == 4)
        {
          feedback.clear();
          shapes_vector.push_back(new Circle(clicks[0], clicks[1], clicks[2], clicks[3], Shapes::colors));
          clicks.clear();
        }
      }
      else if (Shapes::mode == 2)
      {
        if(clicks.size() == 6)
        {
          feedback.clear();
          shapes_vector.push_back(new Triangle(clicks[0], clicks[1], clicks[2], clicks[3], clicks[4], clicks[5], Shapes::colors));
          clicks.clear();
        }
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
  createSliders();
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
