#include <iostream>
#include "DTrack.h"

void other_test()
{
  DTrack t(17*60+5, "In-A-Gadda-Da-Vida");
  DTrack u(t);
  DTrack v(178, "One Hit by a Wonder");
  v = t;

  std::cout << "t" << std::endl;
  std::cout << "Length: %f" << t.GetLength() << std::endl;
  std::cout << "Title: %s" << t.GetTitle() << std::endl;
  std::cout << "u\n" << std::endl;
  std::cout << "Length: %f" << u.GetLength() << std::endl;
  std::cout << "Title: %s" << u.GetTitle() << std::endl;
  std::cout << "v\n" << std::endl;
  std::cout << "Length: %f" << v.GetLength() << std::endl;
  std::cout << "Title: %s" << v.GetTitle() << std::endl;

  u.SetTitle("U's new title");
  v.SetTitle("Other title");
  std::cout << "t" << std::endl;
  std::cout << "Length: %f" << t.GetLength() << std::endl;
  std::cout << "Title: %s" << t.GetTitle() << std::endl;
  std::cout << "u\n" << std::endl;
  std::cout << "Length: %f" << u.GetLength() << std::endl;
  std::cout << "Title: %s" << u.GetTitle() << std::endl;
  std::cout << "v\n" << std::endl;
  std::cout << "Length: %f" << v.GetLength() << std::endl;
  std::cout << "Title: %s" << v.GetTitle() << std::endl;

}

void test_is_equal()
{
  DTrack t(1,  "Short song");
  DTrack u(10, "Less short song");
  DTrack v(t);
  
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
  DTrack t(1,  "Short song");
  DTrack u(10, "Less short song");
  DTrack v(t);
  
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
  DTrack t(1,  "Short song");
  DTrack u(10, "Less short song");
  DTrack v(t);
  
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
  DTrack t(1,  "Short song");
  DTrack u(10, "Less short song");
  DTrack v(t);
  DTrack w(.5, "Mini song");
  
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


int main(int argc, char **argv)
{
  DTrack t(17*60+5, "In-A-Gadda-Da-Vida");

  std::cout << "Length: " << t.GetLength() << std::endl;
  std::cout << "Title: " << t.GetTitle() << std::endl;

  t.SetLength(2*60+2);
  t.SetTitle("In-A-Gadda-Da-Vida (Wimpy Version)");
  
  std::cout << "Length: " << t.GetLength() << std::endl;
  std::cout << "Title: " << t.GetTitle() << std::endl;
  
  other_test();

  test_is_equal();
  test_not_equal();
  test_less_than();
  test_less_than_equal();
  
  return 0;
}