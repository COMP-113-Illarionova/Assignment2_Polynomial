//Program to add two string polynomials through arrays
#include <iostream>
#include <string>
using namespace std;

int main() {

	double polynomial1[10] = {};
	double polynomial2[10] = {};
	char c;
	double coefficient = 0;
	int power = 0;
	bool nextPower = false;

	while (c = cin.get(), c != '\n') {
		if (c == '+' || c == '-')
			nextPower = false;
		else if (c == 'x' || c == 'X')
			nextPower = true;
		else if (c >= '0' && c <= '9') {
			cin.unget();
			if (nextPower) {
				cin >> power;
				polynomial1[power] = coefficient;
			}
			else
				cin >> coefficient;
		}
	}

	for (int i = 9; i >= 0; i--) {
		if (polynomial1[i] != 0)
			cout << "coefficient = " << polynomial1[i] << "   power = " << i << endl;
	}
	return 0;
}