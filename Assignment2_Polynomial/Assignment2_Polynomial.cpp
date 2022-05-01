//Program to add two polynomials represented in linkedlist using recursion
#include<iostream>
#include <string>
using namespace std;

void addPolynomial(string poly1, string poly2);

int main(){

	string p1 = "7x5+3x";
	cout << p1 << endl;
	string p2 = "7x5+2x5+7x";
	cout << p2 << endl;
	char* str1 = &p1[0];
	char* str2 = &p2[0];


	int coeff, expo, size;
	string tempC, tempE;
	cout << strncmp(str1, str2, 3) << endl;


	//char *ptr;

	//cout << "First polynomial: ";
	//getline(cin, p1);
	for (size = 0; p1[size] !='\0'; size++);
	for (int i = 0; i < size;i++) {
		if (p1[i] == 'x')
		tempC = 1;
		else if (p1[i] != 'x' && p1[i + 1] == 'x') {
			tempC = p1[i];
			//tempC[1=

		}
		
	}
	//getline(cin, p1);

	//cout << "Second polynomial: ";
	//getline(cin, p2);
	for (size = 0; p2[size] != '\0'; size++);
	addPolynomial(p1, p2);


	return 0;
}

void addPolynomial(string poly1, string poly2) {

	string p3;
	p3.clear();
	int i = 0, j = 0;

	


}