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
	int counter = 0;
	bool nextPower = false; //set to false

	cout << "Enter first polynomial: ";

	while (c = cin.get(), c != '\n') {

		if (c == '+' || c == '-') {
			if (nextPower && coefficient == NULL) {
				polynomial1[1] = 1;
			}
			else if (nextPower && coefficient!=NULL) {
				polynomial1[1] = coefficient;
			}
			else if (!nextPower && coefficient != NULL) {
				polynomial1[0] = coefficient;
			}
			else
				nextPower=false;
		}
		else if (c == 'x' || c == 'X')
			nextPower=true;
		else if (c >= '0' && c <= '9') {
			cin.unget();

			if (nextPower) {
				cin >> power;
				if (polynomial1[power]!=0)
					polynomial1[power] += coefficient;
				else 
					polynomial1[power] = coefficient;
				nextPower=false;
				coefficient = NULL;
			}
			
			else {
				cin >> coefficient;
			}
		}
	}

	if (c == '\n' && coefficient != NULL) {
		if(nextPower) polynomial1[1] = coefficient;
		else polynomial1[0] = coefficient;
	}

	for (int i = 9; i >= 0; i--) {
		if (polynomial1[i] != 0)
			cout << "coefficient = " << polynomial1[i] << "   power = " << i << endl;
	}
	return 0;
}