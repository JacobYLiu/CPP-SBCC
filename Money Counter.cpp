//============================================================================
// Name        : Money.cpp
// Author      : Jacob Liu
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <sstream>
using namespace std;

class Counter {
	const static int MAXIMUM = 9999;
	int maxValue;
	int counter;
public:
	Counter() {
		maxValue = MAXIMUM;
		counter = 0;
		cout << "Maximum value of the counter is " << maxValue << endl;
		cout << " Current value of the counter is " << counter << endl;
	}
	Counter(int max) {
		maxValue = max;
		counter = 0;
		cout << "Maximum value of the counter is " << maxValue << endl;
		cout << " Current value of the counter is " << counter << endl;
	}
	void cent(int num);
	void dimes(int num);
	void dollars(int num);
	void tensOfDollars(int num);
	void overflow();
	void money();

};
/////////////////////////////////////////////////////////////////////////////

void Counter::cent(int num) {
	counter = counter + num;
}
void Counter::dimes(int num) {
	counter = counter + (10 * num);
}
void Counter::dollars(int num) {
	counter = counter + (100 * num);
}
void Counter::tensOfDollars(int num) {
	counter = counter + (1000 * num);
}
void Counter::overflow() {
	if (counter > maxValue) {
		cout << "There is overflow in your system" << endl;
	} else {
		cout << "You're safe! No overflow." << endl;
	}
}
void Counter::money() {
	string input = "";
	int exit = 0;
	int num = 0;
	cout << "Enter a key, either a, s, d, f, followed by 1-9. or overflow."
			<< endl;

	while (exit == 0) {
		cin >> input;
		string one = input.substr(0, 1);
		string two = input.substr(1, input.length() - 1);
		stringstream convert(two);
		convert >> num;

		switch (input[0]) {
		case 'a':  // cents
			cent(num);
			break;
		case 's':  // dimes
			dimes(num);
			break;
		case 'd': // dollars
			dollars(num);
			break;
		case 'f': // tens of dollars
			tensOfDollars(num);
			break;
		case 'o': // overflow
			overflow();
			break;
		case 'x':
			exit = 1;
			break;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
int main() {
	int pin = 0;
	Counter doIt;
	doIt.money();

	cout
			<< "Please enter an integer amount less than 9999 to initialize the counter."
			<< endl;
	cin >> pin;
	Counter counter(pin);
	counter.money();

}
