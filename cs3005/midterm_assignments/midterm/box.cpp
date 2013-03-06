#include <iostream>

int main() 
{
	int width;
  int height;
  std::cout << "Enter a width: ";
  std::cin >> width;
  std::cout << std::endl << "Enter a height: ";
  std::cin >> height;

  int i;
  int h;
  int w;
  for (h=1; h<=height; h++)
  {
    std::cout << '*';
    for(w=1; w<=width; w++)
    {
      if(w==width)
      {
        std::cout << '*' << std::endl;
        continue;
      }
      if(h==1 or h==height)
      {
        std::cout << '*';
      }
      else
        std::cout << ' ';
    }
  }
}


