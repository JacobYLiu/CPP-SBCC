//============================================================================
// Name        : Yummy.cpp
// Author      : Jacob Liu
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

class IC {
	const int MAXSCOOPS = 5;
	const int MAXCONES = 10;
	int cones;
	int scp;
	int scps;
	int cheap;
	char flav;
	float oneScp = 1.00;
	float twoScp = 2.00;
	float nxtScp = .50;
	float total = 0;
	vector<char> flavors;
public:
	void discount();
	void Omenu();
	void Dmenu();
	void newPrice();
	void numCones();
	void numScps();
	void getFlavor();
	void printScp();
	void printCone();
	void totalCost();
	void addTotal(int scps);
};
void IC::discount() {
	cheap = rand() % 6 + 1;
	if (cheap % 2 == 0) {
		cout << "You're a lucky winner! You are able to receive a discount!"
				<< endl;
		Dmenu();
		newPrice();
	} else {
		Omenu();
	}
}
void IC::Dmenu() {
	cout << "Welcome to Ice Monster!" << endl;
	cout << "First scoop:      $0.50" << endl;
	cout << "Second scoop:     $1.00" << endl;
	cout << "Each extra scoop after 2 is additional $.25" << endl;
	cout
			<< "Ice cream flavors: Only input one character to represent each flavors."
			<< endl;

}
void IC::newPrice() {
	oneScp = 0.50;
	twoScp = 1.00;
	nxtScp = .25;
}
void IC::Omenu() {

	cout << "Welcome to Ice Monster!" << endl;
	cout << "First scoop:      $1.00" << endl;
	cout << "Second scoop:     $2.00" << endl;
	cout << "Each extra scoop after 2 is additional $.50" << endl;
	cout
			<< "Ice cream flavors: Only input one character to represent each flavors."
			<< endl;
}
void IC::numCones() {
	cout << "How many cones do you want to purchase? (No more than 10)" << endl;
	cin >> cones;
	if (cin.fail()){
		cin.clear();
		cin.ignore(1024,'\n');
	}
	while (cones <= 0 || cones > MAXCONES) {
		cout << "Sorry, please input a valid number." << endl;
		cin >> cones;
		if (cin.fail()){
			cin.clear();
			cin.ignore(1024,'\n');
		}
	}
	numScps();
}
void IC::numScps() {
	for (int i = 1; i <= cones; i++) {
		cout << "How many scoops for cone " << i
				<< " ? (maximum of 5 scoops per cone)" << endl;
		cin >> scp;
		while (scp <= 0 || scp > MAXSCOOPS) {
			cout << "Please enter a larger number or lower number." << endl;
			cin >> scp;
		}
		addTotal(scps);
		getFlavor();
		printScp();
		printCone();
	}
}
void IC::getFlavor() {
	for (int i = 1; i <= scp; i++) {
		cout << "Specify the flavor for scoop " << i << ": " << endl;
		cin >> flav;
		flavors.push_back(flav);
	}
}
void IC::printScp() {
	cout << "Here is your cone! Enjoy!!" << endl;
	for (int i = 0; i < flavors.size(); i++) {
		cout << "( " << flavors.at(i) << " )" << endl;
	}
	flavors.clear();
}
void IC::printCone() {

	cout << "\\   /" << endl;
	cout <<	" \\ /" << endl;
	cout << "  * " << endl;
}
void IC::addTotal(int scps) {
	if (scp == 1) {
		total += oneScp;
	} else if (scp == 2) {
		total += twoScp;
	} else {
		total += twoScp + nxtScp * (scp - 2);
	}
}
void IC::totalCost() {
	cout << "Total charge: $" << total << endl;
}
int main() {
	srand(time(NULL));
	IC shop;
	shop.discount();
	shop.numCones();
	shop.totalCost();
	cout << "Have a nice day!" << endl;
	return 0;
}
