#include <iostream>  /* cout, endl, etc. */
#include <vector>    /* vector */
#include <algorithm> /* random_shuffle(), sort(), reverse() */
#include <cstdlib>   /* srand() */
#include <ctime>     /* time() */

int find_smallest_item(int numbers[], int length)
{
  int smallest = 100;
  for (int i=0; i<length; i++)
  {
    if (numbers[i] < smallest)
      smallest = numbers[i];
  }
  return smallest;
} 

int linear_search(int numbers[], int length, int lost)
{
  for (int i=0; i<length; i++)
  {
    if (numbers[i] == lost)
      return i;
    }
  }
  return -1;
}

int main(int argc, char *argv[])
{
  // ----- Create list n long with numbers 0-50 ----- //
  std::srand( time(NULL) );

  int length = std::atoi(argv[1]);
  int numbers[length];              // numbers array
  std::vector<int> numbers_vector;  // numbers vector

  for (int i=0; i<length;i++)
  {
    numbers[i] = (std::rand() % 10) + 1;
    std::cout << numbers[i] << ", ";
  }

  // ----- Find the smallest item in an array ----- //
  int smallest = find_smallest_item(numbers, length);
  std::cout << "Smallest item in array: " << smallest << std::endl;

  // ----- Linear search an array ----- //
  int lost;
  std::cout << "What number would you like to search for? ";
  std::cin >> lost;
  int found_at = linear_search(numbers, length, lost);
  std::cout << "Your number is at index: " << found_at << std::endl;
}