// risk

// pull in command line args

// first arg (not including execution param), is attackers (A), second arg is defenders (D)
// third arg is number of simulations (N)

// one simulation consists of rolling a 6 sided die A times, inputting each roll into a vector then,
// rolling a 6 sided die D times, inputting each roll into a separate vector.

// sort each vector, record winners and losers. 

// divide amount of defender losses by N getting a float value.

#include <iostream>  /* cout, endl, etc. */
#include <vector>    /* vector */
#include <algorithm> /* random_shuffle(), sort(), reverse() */
#include <cstdlib>   /* srand() */
#include <ctime>     /* time() */

/* display the contents of the vector */
void display_vector(std::vector<int> v)
{
  unsigned int i;
  for(i = 0; i < v.size(); i++)
    {
      std::cout << v[i] << " ";
    }
  std::cout << std::endl;
}

std::vector<int> roll(int num_of_rolls, int sides)
{
	std::vector<int> v;
	for(int i=0; i<num_of_rolls; i++)
	{
		int roll = std::rand() % sides + 1;
		v.push_back(roll);
	}
	return v;
}
int main(int argc, char *argv[])
{
	// Catch command line params
	int ATTACKERS = std::atoi(argv[1]); // converts 2nd parameter to integer
	int DEFENDERS = std::atoi(argv[2]);
	int sides = std::atoi(argv[3]);
	int NUMBER_OF_SIMULATIONS = std::atoi(argv[4]);
	int simulation = 0;
	int d_losses = 0;
	
	// Seed random number
	std::srand( time(NULL) );

	while (simulation < NUMBER_OF_SIMULATIONS)
	{
		// instantiate vectors
		std::vector<int> attacker_rolls;
		std::vector<int> defender_rolls;

		// rolls
		attacker_rolls = roll(ATTACKERS, sides); // attacker vector
		defender_rolls = roll(DEFENDERS, sides); // defender vector

		// who rolled the least amount?
		int smallest = DEFENDERS;
		if (ATTACKERS < DEFENDERS);
		{
			smallest = ATTACKERS;
		}

		// sort vectors
		std::sort(attacker_rolls.begin(), attacker_rolls.end());
		std::sort(defender_rolls.begin(), defender_rolls.end());

		// compare dice
		for(int i=0; i<smallest; i++)
		{
			if(attacker_rolls[i] > defender_rolls[i])
			{
				d_losses ++;
			}
		}

		simulation++;
	} 
	double d_losses_new = (double)d_losses/(NUMBER_OF_SIMULATIONS*2) * 100;
	std::cout << ATTACKERS << " vs " << DEFENDERS << " with " << sides << " sided die" << " = " << d_losses_new << "%" << std::endl; 
	return 0;
}
