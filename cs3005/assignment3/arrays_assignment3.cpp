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
  int found;
  for (int i=0; i<length; i++)
  {
    if (numbers[i] == lost)
      return i;
  }
  return -1;
}

void sort_array(int numbers[], int length)
{
  bool switched = true;
  while (switched)
  {
    switched = false;
    for (int i=0; i<length-1; i++)
    {
      if (numbers[i] > numbers[i+1])
      {
        int temp = numbers[i];
        numbers[i] = numbers[i+1];
        numbers[i+1] = temp;
        switched = true;
      }
    }
  }
}

void display_list(int list[], int length)
{
  for (int i=0; i<length; i++)
    std::cout << list[i] << " ";
}

int binary_search(int list[], int length, int a, int high=5, int low=0, int m=3)
{
  high = length;
  low = 0;
  m = length/2;
  if (list[m] > a)
    binary_search(list, length, a, length, m+1);
  else if (list[m] < a)
    binary_search(list, length, a, m-1, 0);
  else
    return m;
  std::cout << "found at index: " << m << std::endl;

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

  // ----- Sort an array in ascending order ----- //
  sort_array(numbers, length);
  std::cout << "Sorted Array:" << std::endl;
  display_list(numbers, length);

  // ----- Binary search an ascending order sorted array ----- //
  int a;
  std::cout << "Binary search for what number? ";
  std::cin >> a;
  binary_search(numbers, length, a);
}