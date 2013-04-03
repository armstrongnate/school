#include <iostream>
#include <stack>
#include <queue>
#include <string>

int main()
{
  std::string word;
  std::queue<char> letters;
  std::stack<char> reversed_letters;

  std::cout << "Give me a string";
  std::cin >> word;


  // stick each letter of word into stack
  for(unsigned int i=0; i< word.size()); i++)
    {
      letters.push_back(word[i]);
      reversed_letters.push(word[i]);
    }

  bool is_palindrome;
  for(i=0; i< letter.size(); i++)
    {
      char q;
      char s;
      q = letters.front();
      s = reversed_letters.top();
      letters.pop();
      reversed_letters.pop();

      if(q != s)
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