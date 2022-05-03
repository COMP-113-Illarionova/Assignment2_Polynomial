//Program to add two string polynomials through arrays
#include <iostream>
#include <string>
#include <cassert>
using namespace std;
bool checkSign(char c);

int main() {

	double polynomial1[10] = {};
	double polynomial2[10] = {};
	double sum[10] = {};
	char c;
	double coefficient = 0;
	int power = 0;
	int count = 0;
	bool nextPower = false;//set to false
	bool isSignNeg = false;


	cout << "\nEnter first polynomial: ";
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
				//do {
					//cout << "Power must be an integer!";
				cin >> power;
				//}while (power %1!=0);

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
		if (nextPower) {
			if (polynomial1[1] != 0) polynomial1[1] += coefficient;
			else polynomial1[1] = coefficient;
		}
		else
			if (polynomial1[0] != 0) polynomial1[0] += coefficient;
			else polynomial1[0] = coefficient;
	}

	for (int i =0; i<10;i++)
		cout << polynomial1[i] << ' ';

	cout << "\nEnter second polynomial: ";
	coefficient = 0;
	power = 0;
	nextPower = false;
	isSignNeg = false;
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
				//assert(power > 0); @todo remove
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
		if (nextPower) {
			if (polynomial2[1] != 0) polynomial2[1] += coefficient;
			else polynomial2[1] = coefficient;
		}
		else
			if (polynomial2[0] != 0) polynomial2[0] += coefficient;
			else polynomial2[0] = coefficient;
	}

	for (int i = 0; i < 10; i++)
		cout << polynomial2[i] << ' ';
	cout << endl;//@todo remove

	for (int i = 0; i < 10; i++) {
			sum[i] = polynomial1[i] + polynomial2[i];
		}

	cout << "\nSum of polynomials = ";
	for (int i = 9; i >= 0; i--) {
		if (sum[i] != 0) {
			if (i == 0) {
				if (sum[i] > 0 && count != 0)
					cout << '+' << sum[i];
				else cout << sum[i];
				count++;
			}

			else if (i == 1) {
				if (sum[i] > 0 && count != 0) cout << '+' << sum[i] << 'x';
				else if (sum[1] == 1) cout << 'x';
				else if (sum[1] == -1) cout << '-x';
				else cout << sum[i] << 'x';
				count++;
			}
			else {
				if (sum[i] > 0 && count != 0) cout << '+' << sum[i] << 'x' << i;//@todo ignore '+' for the first term
				else cout << sum[i] << 'x' << i;
				count++;
			}
		}
	}
	return 0;
}

bool checkSign(char c) {
	if (c == '+') return false;
	else if (c == '-') return true;
}