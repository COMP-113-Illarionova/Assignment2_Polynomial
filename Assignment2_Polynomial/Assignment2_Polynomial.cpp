/**
* file Assignment2_polynomial.cpp
* \brief Program to add two string polynomials through arrays
* \details 
* \author Alisa Illarionova
* \date 3/5/2022
*/
#include <iostream>
#include <string>
#include <cassert>
using namespace std;
bool checkSign(char c); //bool function that flags negative sign

/**
*Function <code>main</code> this is the driver of the program
*<BR>
* @return Returns 0
*/
int main() {
	double polynomial1[10] = {}; //Array with coefficients of first polynomial
	double polynomial2[10] = {}; //                        of second polynomial
	double sum[10] = {};		 //                        of the sum
	char c;                      // Symbol  
	double coefficient = 0;      // Coefficient of polynomial terms
	int power = 0;				 // Power(exponent) of polynomial terms
	int count = 0;               // Counter
	bool nextPower = false;      // set to false
	bool isSignNeg = false;      // set to false

	cout << "\nEnter first polynomial: ";
	while (c = cin.get(), c != '\n') {  // Start reading input character by character until '\n' is reached 
		if (c == '+' || c == '-') {
			isSignNeg = checkSign(c);   // Returns true if sign is '-'

			if (nextPower && coefficient == NULL) { // If we expect the power and coeffiecient = 0 
				polynomial1[1] = 1;
				nextPower = false;      // resetting nextPower to false; moving to the next term
										// we put coefficient of the current term in the array
			}
			else if (nextPower && coefficient != NULL) {  // If we expect the power and coefficient!=0
				polynomial1[1] = coefficient;
				coefficient = NULL;     // resetting coefficent
				nextPower = false;      // resetting nextPower, moving on to the next term
			}
			else if (!nextPower && coefficient != NULL) { // Finding constant: We don't expect power and we have coefficient stored
				polynomial1[0] = coefficient;	//x^0 is just constant
				coefficient = NULL;		// resetting coefficient 
			}
			else
				nextPower = false;		// new term, next umber will be coefficient not power  
		}
		else if (c == 'x' || c == 'X') {
			if (coefficient == NULL)    // no number before x, i.e. x=1x
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

				if (polynomial1[power] != 0 && isSignNeg) {  // Addition of coefficients for multiple terms of same exponents 
					if (coefficient < 0) {					 
						polynomial1[power] += coefficient;
					}
					else {
						if (polynomial1[power] > coefficient)
							polynomial1[power] -= coefficient;
						else polynomial1[power] = coefficient - polynomial1[power];
					}
				}
				else if (polynomial1[power] != 0 && !isSignNeg)	
					polynomial1[power] += coefficient;
				else
					polynomial1[power] = coefficient;		// First time entering coefficient for the exponent
				nextPower = false;							// Resetting nextPower and coefficient
				coefficient = NULL;
			}

			else {
				if (isSignNeg) {							// Make coefficent negative if sign is '-'
					cin >> coefficient;
					coefficient *= -1;
				}
				else cin >> coefficient;					// Store number as coefficient
			}
		}
	}

	if (c == '\n' && coefficient != NULL) {					// Reached the end of the line and have unused coefficient
		if (nextPower) {									// Expect a power, then we have coefficient for x^1 
			if (polynomial1[1] != 0) polynomial1[1] += coefficient;
			else polynomial1[1] = coefficient;
		}
		else												// Don't expect a power, have a constant, i.e. x^0 coefficient
			if (polynomial1[0] != 0) polynomial1[0] += coefficient; 
			else polynomial1[0] = coefficient;
	}

	for (int i =0; i<10;i++)
		cout << polynomial1[i] << ' ';			//print out coefficients @todo remove

	cout << "\nEnter second polynomial: ";		//Ask for second polynomial
	coefficient = 0;
	power = 0;
	nextPower = false;
	isSignNeg = false;							// Reset all the variables to zero/false
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

	for (int i = 0; i < 10; i++) {						// Fill in sum array by adding coefficients of 2 polynomials
			sum[i] = polynomial1[i] + polynomial2[i];
		}

	cout << "\nSum of polynomials = ";                  // Print out sum array
	for (int i = 9; i >= 0; i--) {
		if (sum[i] != 0) {								// Print only non-zero terms
			if (i == 0) {								// Printing constant
				if (sum[i] > 0 && count != 0)			// Only print '+' for positive term only when not first term
					cout << '+' << sum[i];
				else cout << sum[i];
			}
			else if (i == 1) {							// Print x^1	
				if (sum[i] > 0 && count != 0) cout << '+' << sum[i] << 'x';
				else if (sum[1] == 1) cout << 'x';
				else if (sum[1] == -1) cout << '-x';
				else cout << sum[i] << 'x';
			}
			else {
				if (sum[i] > 0 && count != 0) cout << '+' << sum[i] << 'x' << i;
				else cout << sum[i] << 'x' << i;
			}
			count++;									// Needed to print out first positive term without '+'
		}
	}
	return 0;
}

/**
*Function <code>checkSign</code> checks if the character is '-' and so coefficient is negative
* <BR>
* @param char Symbol to check 
* @return Returns <code>false</code> if char is '+' and <code>true</code> if char is '-'
*/
bool checkSign(char c) {
	if (c == '+') return false;
	else if (c == '-') return true;
}