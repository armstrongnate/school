#include <iostream>
#include "Student.h"

int main(int argc, char** argv)
{
  Student s(21, "Armstrong", "Nate", "nate@example.com", "555-32-1234", "Natertots");

  std::cout << "Last Name: " << s.GetLastName() << std::endl;
  std::cout << "First Name: " << s.GetFirstName() << std::endl;

  s.SetAge(22);
  s.SetSsn("333-22-6666");
  
  std::cout << "Age: " << s.GetAge() << std::endl;
  std::cout << "SSN: " << s.GetSsn() << std::endl;
  std::cout << "Nickname: " << s.GetNickname() << std::endl;
  
  return 0;
}
