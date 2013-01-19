#include <iostream>
using namespace std;

int main () {
	int num = 1;
	int sum = 0;
	int amount = 0;
	int highest = 0;
	while (num != 0)
	{
		cin >> num;
		sum += num;
		amount++;
	}
	cout << "The sum is: " << sum << endl;
	cout << "The average is: " << sum / amount;
	return 0;
}