//============================================================================
// Name        : Dictionary.cpp
// Author      : Jacob Liu
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <set>
#include <map>
#include <iomanip>
#include <sstream>
#include <fstream>
using namespace std;

class Diction {
	set<string> count;
	set<string>::iterator itr;
public:
	Diction(set<string> count2) {
		count = count2;
	}
	void printDictionary() {
		for(itr = count.begin(); itr != count.end(); itr++) {
			cout << *itr << endl;
		}
	}
	void addAWord() {
		string word;
		int counter = 0;
		cout << "Enter the word you want to add: ";
		cin >> word;
		for(size_t i = 0; i < word.length(); ++i) {
			word[i] = tolower(word[i]);
		}
		for(itr = count.begin(); itr != count.end(); itr++) {
			if(word == *itr) {
				counter++;
			}
		}
		if (counter == 0) {
			count.insert(word);
			cout << "Word added." <<endl;
		} else {
			cout<< "Word already exists, you dummy." << endl;
		}
	}

	void deleteAWord() {
		string deleteWord;
		int counter2 = 0;
		cout << "Enter the word you want to delete: ";
		cin >> deleteWord;
		for(size_t i = 0; i < deleteWord.length(); ++i) {
			deleteWord[i] = tolower(deleteWord[i]);
		}
		for(itr = count.begin(); itr != count.end(); itr++){
			if(deleteWord == *itr) {
				count.erase(itr);
				counter2++;
			}
		}
		if(counter2 != 0) {
			cout << "Word deleted." <<"\n";
		} else {
			cout << "Word does not exist, you dummy." <<endl;
		}
	}
	void checkWord() {
		string checkThis;
		int counter3 = 0;
		cout << "Enter the word you want to check: " << endl;
		cin >> checkThis;
		for(size_t i = 0; i < checkThis.length(); ++i) {
			checkThis[i] = tolower(checkThis[i]);
		}
		for(itr = count.begin(); itr != count.end(); itr++) {
			if (checkThis ==*itr) {
				counter3++;
			}
		}
		if (counter3 == 0){
			cout << "The word doesn't exist, sorry you dummy." <<endl;
		} else {
			cout << "The word does exist." <<endl;
		}
	}
};
int main() {
	ifstream stringFile;
	string word;
	string name;
	char letter;
	set<string> count3;
	stringFile.open("test.txt");
	cout << "Here is the list for the dictionary: " <<endl;
	while(!stringFile.eof()) {
		stringFile >> word;
		for(size_t i = 0; i < word.length(); ++i){
			word[i] = tolower(word[i]);
		}
		count3.insert(word);
	}
	Diction d(count3);
	d.printDictionary();

	cout<< "1 for add, 2 for check, 3 for delete, Q to quit(please quit): "<<endl;
	cin >> letter;
	while (letter != 'Q') {
		if(letter == '1') {
			d.addAWord();
		}
		if(letter == '2') {
			d.checkWord();
		}
		if(letter == '3') {
			d.deleteAWord();
		}
		cout<< "1 for add, 2 for check, 3 for delete, Q to quit(please quit): "<<endl;
		cin>> letter;
	}
	d.printDictionary();

	return 0;
}
