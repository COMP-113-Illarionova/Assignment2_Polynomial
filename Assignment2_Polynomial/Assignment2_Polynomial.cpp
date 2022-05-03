//Program to add two string polynomials through arrays
#include <iostream>
#include <string>
using namespace std;
const int MAX = 10;
bool nextPower = false;//set to false
bool isSignNeg = false;

double initialiseArray(double& array);

int main() {

	//char c;
	double polynomial1[MAX] = {};
	double polynomial2[MAX] = {};

	cout << "Enter first polynomial: ";
	initialiseArray(polynomial1[MAX - 1]);



	return 0;
}

double initialiseArray(double& array) {

	double coefficient = 0;
	int power = 0;
	char c;
	double* pointer = &array;
	while (c = cin.get(), c != '\n') {
		if (c == '+' || c == '-') {

			if (c == '+') isSignNeg = false;
			else if (c == '-') isSignNeg = true;

			else if (nextPower && coefficient == NULL) {
				*(pointer + 1) = 1;
			}
			else if (nextPower && coefficient != NULL) {
				*(pointer + 1) = coefficient;
			}
			else if (!nextPower && coefficient != NULL) {
				*pointer = coefficient;
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
				if (*pointer != 0 && isSignNeg) {
					if (coefficient < 0) {
						*(pointer + power) += coefficient;
					}
					else {
						if (*(pointer + power) > coefficient)
							*(pointer + power) -= coefficient;
						else *(pointer + power) = coefficient - *(pointer + power);
					}
				}
				else if (*(pointer + power) != 0 && !isSignNeg)
					*(pointer + power) += coefficient;
				else
					*(pointer + power) = coefficient;
				nextPower = false;
				coefficient = NULL;
			}

			else {
				if (isSignNeg) {
					cin >> coefficient;
					coefficient *= -1;
				}
				else cin >> coefficient;
				cout << "--> " << coefficient << endl;
			}
		}

		if (c == '\n' && coefficient != NULL) {
			if (nextPower) *(pointer + 1) = coefficient;
			else *pointer = coefficient;
		}

		

	}
	for (int i = 9; i >= 0; i--) {
		if (*(pointer + i) != 0)
			cout << "coefficient = " << *(pointer + i) << "   power = " << i << endl;
	}
	return array;
}