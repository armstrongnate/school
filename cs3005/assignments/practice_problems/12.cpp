#include <iostream>
using namespace std;

int main () {
	int num = 1;
	int sum = 0;
	int amount = 0;
	int highest = 0;
	cout << "Start entering numbers:" << endl;
	while (num != 0)
	{
		cin >> num;
		sum += num;
		amount++;
		if (num>highest)
		{
			highest = num;
		}
	}
	cout << "The sum is: " << sum << endl;
	cout << "The average is: " << sum / amount << endl;
	cout << "The highest number was: " << highest;
	return 0;
}