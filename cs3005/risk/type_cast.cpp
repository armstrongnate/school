#include <iostream> /* cout, endl, etc. */

/*
 * This is a simple program to demonstrate
 * basic type casting (changing the representation
 * of values in memory).
 */


int main(int argc, char *argv[])
{
  int i = 5;
  int j = 10;
  
  // integer division -> 0
  int k = i / j;
  // integer division -> 0, converted to double -> 0
  double f = i / j;
  // integer division -> 0, converted to double -> 0
  double g = (double)(i / j);
  // i converted to double -> j automatically promoted to double -> double division -> 0.5
  double h = (double)i / j;

  std::cout << "i = " << i << std::endl;
  std::cout << "j = " << j << std::endl;
  std::cout << "k = i / j = " << k << std::endl;
  std::cout << "f = i / j = " << f << std::endl;
  std::cout << "g = (double)(i / j) = " << g << std::endl;
  std::cout << "h = (double)i / j = " << h << std::endl;
  
  return 0;
}