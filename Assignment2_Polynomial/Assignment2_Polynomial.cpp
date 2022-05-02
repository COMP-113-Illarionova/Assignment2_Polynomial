//Program to add two string polynomials through arrays
#include <iostream>
#include <string>
using namespace std;
bool checkSign(char c);

bool checkSign(char c) {
	if (c == '+') return false;
	else if (c == '-') return true;
}

int main() {

	double polynomial1[10] = {};
	double polynomial2[10] = {};
	char c;
	double coefficient = 0;
	int power = 0;
	bool nextPower = false;//set to false
	bool isSignNeg = false;


	cout << "Enter first polynomial: ";
	while (c = cin.get(), c != '\n') {

		if (c == '+' || c == '-') {

			isSignNeg = checkSign(c);

			if (nextPower && coefficient == NULL) {
				polynomial1[1] = 1;
				nextPower = false;
			}
			else if (nextPower && coefficient != NULL) {
				polynomial1[1] = coefficient;
				coefficient = NULL;
				nextPower = false;
			}
			else if (!nextPower && coefficient != NULL) {
				polynomial1[0] = coefficient;
				coefficient = NULL;
			}
			else
				nextPower = false;
		}
		else if (c == 'x' || c == 'X') {
			if (coefficient == NULL)
				if (isSignNeg) coefficient = -1;
				else coefficient = 1;
			nextPower = true;

		}
		else if (c >= '0' && c <= '9') {
			cin.unget();

			if (nextPower) {
				cin >> power;
				if (polynomial1[power] != 0 && isSignNeg) {
					if (coefficient < 0) {
						polynomial1[power] += coefficient;
					}
					else {
						if (polynomial1[power] > coefficient)
							polynomial1[power] -= coefficient;
						else polynomial1[power] = coefficient - polynomial1[power];
					}
					coefficient = NULL;
				}
				else if (polynomial1[power] != 0 && !isSignNeg)
					polynomial1[power] += coefficient;
				else
					polynomial1[power] = coefficient;
				nextPower = false;
				coefficient = NULL;
			}

			else {
				if (isSignNeg) {
					cin >> coefficient;
					coefficient *= -1;
				}
				else cin >> coefficient;
			}
		}
	}

	if (c == '\n' && coefficient != NULL) {
		if (nextPower) polynomial1[1] = coefficient;
		else polynomial1[0] = coefficient;
	}

	for (int i = 9; i >= 0; i--) {
		if (polynomial1[i] != 0)
			cout << "coefficient = " << polynomial1[i] << "   power = " << i << endl;
	}

	cout << "Enter second polynomial: ";
	coefficient = 0;
	power = 0;
	nextPower = false;
	while (c = cin.get(), c != '\n') {

		if (c == '+' || c == '-') {

			isSignNeg = checkSign(c);

			if (nextPower && coefficient == NULL) {
				polynomial2[1] = 1;
				nextPower = false;
			}
			else if (nextPower && coefficient != NULL) {
				polynomial2[1] = coefficient;
				coefficient = NULL;
				nextPower = false;
			}
			else if (!nextPower && coefficient != NULL) {
				polynomial2[0] = coefficient;
				coefficient = NULL;
			}
			else
				nextPower = false;
		}
		else if (c == 'x' || c == 'X')
			nextPower = true;
		else if (c >= '0' && c <= '9') {
			cin.unget();

			if (nextPower) {
				cin >> power;
				if (polynomial2[power] != 0 && isSignNeg) {
					if (coefficient < 0) {
						polynomial2[power] += coefficient;
					}
					else {
						if (polynomial2[power] > coefficient)
							polynomial2[power] -= coefficient;
						else polynomial2[power] = coefficient - polynomial2[power];
					}
					coefficient = NULL;
				}
				else if (polynomial2[power] != 0 && !isSignNeg)
					polynomial2[power] += coefficient;
				else
					polynomial2[power] = coefficient;
				nextPower = false;
				coefficient = NULL;
			}

			else {
				if (isSignNeg) {
					cin >> coefficient;
					coefficient *= -1;
				}
				else cin >> coefficient;
			}
		}
	}

	if (c == '\n' && coefficient != NULL) {
		if (nextPower) polynomial2[1] = coefficient;
		else polynomial2[0] = coefficient;
	}

	for (int i = 9; i >= 0; i--) {
		if (polynomial2[i] != 0)
			cout << "coefficient = " << polynomial2[i] << "   power = " << i << endl;
	}

	return 0;
}