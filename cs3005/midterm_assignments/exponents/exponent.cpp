#include <iostream>  /* cout, endl, etc. */
#include <cstdlib>   /* srand() */
#include <ctime>     /* time() */
#include <vector>    /* vector */

void display_vector(std::vector<int> v)
{
  unsigned int i;
  for(i = 0; i < v.size(); i++)
    {
      std::cout << v[i] << " ";
    }
  std::cout << std::endl;
}

int parseInput(std::string input)
{
	// nothing here yet.
}

int getExponents(int number_of_exponents)
{
	int exponents[number_of_exponents];
	for (int i=0; i<number_of_exponents; i++)
		exponents[i] = i;
	return exponents[number_of_exponents];
}

int exponentiate(int num, int exponent)
{
	if (exponent == 0)
		return 0;
	int new_num = 1;
	for (int i=0; i<exponent; i++)
		new_num *= num;
	return new_num;
}

bool unique(int exponent, std::vector< int > used_exponents)
{
	if (used_exponents.size() == 0)
	{
		return true;
	}
	for (unsigned int i=0; i<used_exponents.size(); i++)
	{
		if (used_exponents[i] == exponent)
			return false;
	}
	return true;
}

bool rightAnswer(int exponent, int answer)
{
	int correct_answer = exponentiate(2, exponent);
	if (answer == correct_answer)
		return true;
	else
	{
		return false;
	}
}

main()
{	
	// seed random
	std::srand( time(NULL) );

	// ask for number of exponents to be tested on.
	int number_of_exponents;
	std::cout << "How many exponents would you like to be tested on? (e.g. 50)";
	std::cin >> number_of_exponents;

	// get list of exponents to be used
	int exponents[number_of_exponents];
	exponents[number_of_exponents] = getExponents(number_of_exponents);
	
	int random_exponent;

	int test = 0;

	std::vector< int > used_exponents;

	// begin main loop
	while (test < number_of_exponents)
	{
		// get random unique exponent

		bool unique_exponent = false;
		while (!unique_exponent)
		{
			random_exponent = (std::rand() % number_of_exponents);
			if (unique(random_exponent, used_exponents))
			{
				used_exponents.push_back(random_exponent);
				unique_exponent = true;
			}
		}

		// wait for correct answer
		bool question_correct = false;
		while (!question_correct)
		{
			// print question
			int answer;
			std::cout << "2^" << random_exponent << "? ";
			std::cin >> answer;

			// check answer
			if (rightAnswer(random_exponent, answer))
			{
				std::cout << "Correct!" << std::endl;
				question_correct = true;
			}
			else
				std::cout << "Try again." << std::endl;
		}
		test += 1;
	}
}