//============================================================================
// Name        : METS.cpp
// Author      : Jacob Liu
// Version     :
// Description : METS Assignment (First assignment in CS140)
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int main() {
	int numMET = 0;
	int numMin;
	int weightlb;
	double weightkg;
	double calories;
	string input;
	char choice;
	string action;

	cout << "Which one of the three activity did you do?" << endl;
	cout << "Three options: sleeping, walking, and basketball!" << endl;
	cin >> input;
	choice = input[0];
	switch (choice) {
	case 's':
	case 'S':
		cout << "You chose sleeping";
		numMET = 1;
		break;
	case 'w':
	case 'W':
		cout << "You chose walking";
		numMET = 2;
		break;
	case 'b':
	case 'B':
		cout << "You chose basketball";
		numMET = 8;
		break;
	default:
		cout << "No activities";
	}
	cout << endl << "How long did you spent on the activity?";
	cin >> numMin;
	cout << endl << "What's your weight in pounds?" << endl;
	cin >> weightlb;
	weightkg = weightlb / 2.2;
	calories = 0.0175 * numMET * weightkg * numMin;

	cout << calories;

	return 0;
}
