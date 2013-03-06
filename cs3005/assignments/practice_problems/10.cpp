#include <iostream>
using namespace std;

int main () {
	int num = 1;
	int sum = 0;
	while (num != 0)
	{
		cin >> num;
		sum += num;
	}
	cout << sum;
	return 0;
}