#include <iostream>
using namespace std;

int main ()
{
	int num = 1;
	cout << "I'm thinking of a number. Can you guess it?" << endl;
	cin >> num;
	while (num != 0)
	{
		cout << "Nope, guess again.";
		cin >> num;
	}
	cout << "You got it!";
    return 0;
}