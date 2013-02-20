#include <iostream>
#include "Track.h"

int main(int argc, char **argv)
{
  Track t(17*60+5, "In-A-Gadda-Da-Vida");

  std::cout << "Length: " << t.GetLength() << std::endl;
  std::cout << "Title: " << t.GetTitle() << std::endl;

  t.SetLength(2*60+2);
  t.SetTitle("In-A-Gadda-Da-Vida (Wimpy Version)");
  
  std::cout << "Length: " << t.GetLength() << std::endl;
  std::cout << "Title: " << t.GetTitle() << std::endl;
  
  return 0;
}