#include <iostream>
#include <vector>
#include <string>

int main()
{
  std::string word;
  std::vector<char> letters;
  std::vector<char> reversed_letters;

  std::cout << "Give me a string";
  std::cin >> word;


  // stick each letter of word into vector
  for(unsigned int i=0; i< word.size()); i++)
    {
      letter.push_back(word[i]);
    }

  for(unsigned int i=word.size(); i>0; i--)
    {
      reversed_letters.push_back(word[i-1]);
    }

  bool is_palindrome;
  for(i=0; i< letter.size(); i++)
    {
      if(letters[i] != reversed_letters[i])
        {
          is_palindrome = false;
          break;
        }
    }
  if(is_palindrome)
    {
      std::cout << word << " is a palindrome" << std::endl;
    }
  else
    {
      std::cout << word << " is not a palindrome" << std::endl;
    }

  return 0;

}