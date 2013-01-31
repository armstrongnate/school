#include <iostream>  /* cout, endl, etc. */

int exponentiate(int num, int exponent)
{
	int new_num = 1;
	for (int i=0; i<exponent; i++)
		new_num *= num;
	return new_num;
}

main()
{	
	int number_of_exponents = 10;
	int exponents[10];
	for (int i=0; i<number_of_exponents; i++)
		exponents[i] = i;
	
	for (int i=0; i<number_of_exponents; i++)
	{
		std::cout << "2^" << i << " equals: " << exponentiate(2, i) << std::endl;
	}
}