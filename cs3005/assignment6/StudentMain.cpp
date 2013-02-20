#include <iostream>
#include "Student.h"

void other_test()
{
  Student t(21, "Gracia", "Josh", "josh.gracia8@gmail.com", "123-45-6789");
  Student u(t);
  Student v(22, "Stout", "Christee", "christeearmstrong@gmail.com", "847-22-3212");
  v = t;

  std::cout << "Josh" << std::endl;
  std::cout << "Age: %f" << t.GetAge() << std::endl;
  std::cout << "SSN: %s" << t.GetSsn() << std::endl;
  std::cout << "Josh_Copy\n" << std::endl;
  std::cout << "Age: %f" << u.GetAge() << std::endl;
  std::cout << "SSN: %s" << u.GetSsn() << std::endl;
  std::cout << "Christee\n" << std::endl;
  std::cout << "Age: %f" << v.GetAge() << std::endl;
  std::cout << "SSN: %s" << v.GetSsn() << std::endl;

  u.SetSsn("Josh_copy's new SSN");
  v.SetSsn("Other title");
  std::cout << "t" << std::endl;
  std::cout << "Age: %f" << t.GetAge() << std::endl;
  std::cout << "SSN: %s" << t.GetSsn() << std::endl;
  std::cout << "Josh_copy\n" << std::endl;
  std::cout << "Age: %f" << u.GetAge() << std::endl;
  std::cout << "SSN: %s" << u.GetSsn() << std::endl;
  std::cout << "Christee\n" << std::endl;
  std::cout << "Age: %f" << v.GetAge() << std::endl;
  std::cout << "SSN: %s" << v.GetSsn() << std::endl;

}

void test_is_equal()
{
  Student t(21,  "Armstrong", "Rob", "rob@awesome.com", "222-33-1111");
  Student u(40, "Joe", "Grandpa", "old@old.com", "000-00-0000");
  Student v(t);
  
  if(t == u)
    {
      std::cout << "Error: " << t << " == " << u << std::endl;
    }
  else
    {
      std::cout << "OK   : " << t << " not == " << u << std::endl;
    }
  
  if(t == v)
    {
      std::cout << "OK   : " << t << " == " << v << std::endl;
    }
  else
    {
      std::cout << "Error: " << t << " not == " << v << std::endl;
    }
}

void test_not_equal()
{
  Student t(21,  "Armstrong", "Rob", "rob@awesome.com", "222-33-1111");
  Student u(40, "Joe", "Grandpa", "old@old.com", "000-00-0000");
  Student v(t);
  
  if(t != u)
    {
      std::cout << "OK   : " << t << " != " << u << std::endl;
    }
  else
    {
      std::cout << "Error: " << t << " not != " << u << std::endl;
    }
  
  if(t != v)
    {
      std::cout << "Error: " << t << " != " << v << std::endl;
    }
  else
    {
      std::cout << "OK   : " << t << " not != " << v << std::endl;
    }
}

void test_less_than()
{
  Student t(21,  "Armstrong", "Rob", "rob@awesome.com", "222-33-1111");
  Student u(40, "Joe", "Grandpa", "old@old.com", "000-00-0000");
  Student v(t);
  
  if(t < u)
    {
      std::cout << "OK   : " << t << " < " << u << std::endl;
    }
  else
    {
      std::cout << "Error: " << t << " not < " << u << std::endl;
    }
  
  if(t < v)
    {
      std::cout << "Error: " << t << " < " << v << std::endl;
    }
  else
    {
      std::cout << "OK   : " << t << " not < " << v << std::endl;
    }
}

void test_less_than_equal()
{
  Student t(21,  "Armstrong", "Rob", "rob@awesome.com", "222-33-1111");
  Student u(40, "Joe", "Grandpa", "old@old.com", "000-00-0000");
  Student v(t);
  Student w(.5, "Baby", "Goo-Goo", "baba@babies.com", "999-99-9999");
  
  if(t <= u)
    {
      std::cout << "OK   : " << t << " <= " << u << std::endl;
    }
  else
    {
      std::cout << "Error: " << t << " not <= " << u << std::endl;
    }
  
  if(t <= v)
    {
      std::cout << "OK   : " << t << " <= " << v << std::endl;
    }
  else
    {
      std::cout << "Error: " << t << " not <= " << v << std::endl;
    }
  
  if(t <= w)
    {
      std::cout << "Error: " << t << " <= " << w << std::endl;
    }
  else
    {
      std::cout << "OK   : " << t << " not <= " << w << std::endl;
    }
}


int main(int argc, char** argv)
{
  Student s(21, "Armstrong", "Nate", "nate@example.com", "555-32-1234");

  std::cout << "Last Name: " << s.GetLastName() << std::endl;
  std::cout << "First Name: " << s.GetFirstName() << std::endl;

  s.SetAge(22);
  s.SetSsn("333-22-6666");
  
  std::cout << "Age: " << s.GetAge() << std::endl;
  std::cout << "SSN: " << s.GetSsn() << std::endl;
  
  other_test();

  test_is_equal();
  test_not_equal();
  test_less_than();
  test_less_than_equal();
  
  return 0;
}