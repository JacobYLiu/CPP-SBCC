//============================================================================
// Name        : Red-Yellow-Green.cpp
// Author      : Jacob Liu
// Version     :
// Copyright   : Novemeber 2016
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

class Lights {
	int green;
	int yellow;
	int red;
	int choice;
	int input;
	vector<int> random;
	vector<int> copy;
	vector<int> userGuess;
public:
	Lights() {
		red = green = yellow = 0;
	}
	void reset(){
		for(int i = 0; i<3; i++){
			copy.at(i) = random.at(i);
		}
	}
	void guess() {
		choice = rand() % 899 + 100;
		cout << choice << endl;
		int last = choice % 10;
		int temp = choice / 10;
		int middle = temp % 10;
		int first = temp / 10;
		random.push_back(first);
		random.push_back(middle);
		random.push_back(last);
		copy.push_back(first);
		copy.push_back(middle);
		copy.push_back(last);
	}
	void getInput() {
		//int input = 0;
		red = yellow = green = 0;
		userGuess.clear();
		cout << "Please enter a guess?" << endl;
		cin >> input;
		int last = input % 10;
		int temp = input / 10;
		int middle = temp % 10;
		int first = (temp - middle) / 10;
		userGuess.push_back(first);
		userGuess.push_back(middle);
		userGuess.push_back(last);
	}

	int Green() {

		if (input != choice) {
			if (userGuess.at(0) == random.at(0)) {
				green++;
				userGuess.at(0) = -1;
				copy.at(0) = -2;
			}
			if (userGuess.at(1) == random.at(1)) {
				green++;
				userGuess.at(1) = -1;
				copy.at(1) = -2;
			}
			if (userGuess.at(2) == random.at(2)) {
				green++;
				userGuess.at(2) = -1;
				copy.at(2) = -2;
			}
		}
		if (input == choice) {
			cout << "Congratulations, you win....." << endl;
			green = 3;
		}
		return green;

	}
	int Yellow() {
		for (int i = 0; i < userGuess.size(); i++) {
			for (int j = 0; j < copy.size(); j++) {
				if (userGuess.at(i) == copy.at(j) && i != j) {
					yellow++;
					userGuess.at(i) = -1;
					copy.at(j) = -2;
				}
			}
		}
		return yellow;
	}
	int Red() {
		red = 3 - green - yellow;
		return red;
	}
};

int main() {
	srand(time(NULL));

	Lights hi;
	hi.guess();
	hi.getInput();
	int g = hi.Green();
	int y = hi.Yellow();
	int r = hi.Red();
	while (g != 3) {
		g = hi.Green();
		y = hi.Yellow();
		r = hi.Red();
		cout << r << " red\n" << g << " green\n" << y << " yellow" << endl;
		hi.reset();
		hi.getInput();
	}
}
