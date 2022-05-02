//Program to add two polynomials represented in linkedlist using recursion
#include<iostream>
#include <string>
#include <malloc.h>
using namespace std;

struct Polynomial {
	int coeff;
	int expo;
	Polynomial* next;
	Polynomial(int coeff, int expo)
	{
		this->coeff = coeff;
		this->expo = expo;
		this->next = NULL;
	}
};

void addPolynomials(Polynomial* head1, Polynomial* head2);
void insert(Polynomial* head, int coeff, int power);
void printList(Polynomial* head);
int findCoeff(string s, int size, int coeff);


int main() {

	string p1, p2, tempC, tempE;
	int size, coeff, expo;
	//Polynomial* head;
	//Polynomial* head2;
	cout << "First polynomial: ";
	getline(cin, p1);
	for (size = 0; p1[size] != '\0'; size++);

	for (int i = 0; i < size; i++) {
		if (p1[i] == 'x') {
			coeff = 1;
			return coeff; //retun coeff =1;
		}
		else if (p1[i] != 'x' && p1[i + 1] == 'x') {
			tempC = p1[i];
			coeff = stoi(tempC);
			return coeff;
		}

		expo = stoi(tempE);
		Polynomial* head = new Polynomial(coeff, expo);
	}
	//cout << "Second polynomial: ";
	//getline(cin, p2);
	//Polynomial* head = new Polynomial(5, 2);
	insert(head, 4, 1);
	Polynomial* head2 = new Polynomial(6, 2);
	insert(head2, 4, 1);
	//printList(head);
	cout << endl;
	printList(head2);
	cout << endl <<
		"Addition:" << endl;
	addPolynomials(head, head2);
}

void addPolynomials(Polynomial* head1, Polynomial* head2) {
	if (head1 == NULL && head2 == NULL)
		return ;
	else if (head1->expo == head2->expo) {
		cout << " " << head1->coeff + head2->coeff <<
			"x^" << head1->expo << " ";
		addPolynomials(head1->next, head2->next);
	}
	else if (head1->expo > head2->expo) {
		cout << " " << head1->coeff <<
			"x^" << head1->expo << " ";
		addPolynomials(head1->next, head2);
	}
	else {
		cout << " " << head2->coeff <<
			"x^" << head2->expo << " ";
		addPolynomials(head1, head2->next);
	}
}

void insert(Polynomial* head, int coeff, int power) {
	Polynomial* new_node = new Polynomial(coeff, power);

	while (head->next != NULL)
		head = head->next;
	head->next = new_node;
}

void printList(Polynomial* head) {
	cout << "Linked List" << endl;
	while (head != NULL) {
		cout << " " << head->coeff <<
			"x" << "^" << head->expo;
		head = head->next;
	}
}

int findCoeff(string s, int size, int coeff)
{

	return coeff;
}
