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
	int boolNextPower = 0; //set to false

	cout << "Enter first polynomial: ";
	while (c = cin.get(), c != '\n') {
		if (c == '+' || c == '-') {
			if (boolNextPower == 1 && coefficient==NULL) {
				polynomial1[1] = 1;
			}

			else if (boolNextPower == 1 && coefficient!=NULL) {
				polynomial1[1] = coefficient;
			}
			//else if (boolNextPower == 0)
				//polynomial1[0] = coefficient;
			else boolNextPower = 0;
		}
		else if (c == 'x' || c == 'X')
			boolNextPower = 1;
		else if (c >= '0' && c <= '9') {
			cin.unget();
			if (boolNextPower == 1) {
				cin >> power;
				polynomial1[power] = coefficient;
				boolNextPower=0;
				coefficient = NULL;
			}
			//else if (boolNextPower == 0 && c == '+' || boolNextPower == 0 && c == '-') {
				//polynomial1[1] = coefficient;
			//}

			else {
				cin >> coefficient;
			}
		}
	}

	for (int i = 9; i >= 0; i--) {
		if (polynomial1[i] != 0)
			cout << "coefficient = " << polynomial1[i] << "   power = " << i << endl;
	}
	return 0;
}