#include <iostream>
#include "Student.h"

int main(int argc, char** argv)
{
  Student s(21, "Armstrong", "Nate", "nate@example.com", "555-32-1234");

  std::cout << "Last Name: " << s.GetLastName() << std::endl;
  
  return 0;
}