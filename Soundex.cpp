//============================================================================
// Name        : Soundex.cpp
// Author      : Jacob Liu
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <string.h>
#include <algorithm>
using namespace std;

string name = "";
string translate = "";
void getNum() {
	translate.append(name, 0, 1);
	for(int i = 1; i< name.length(); i++){
		switch (name[i]) {
		case 'b': case 'f': case 'p': case 'v':
	//case 'B': case 'F': case 'P': case 'V':
		translate.append("1");
		break;
		case 'c': case 'g': case 'j': case 'k': case 'q': case 's': case 'x': case 'z':
	//case 'C': case 'G': case 'J': case 'K': case 'Q': case 'S': case 'X': case 'Z':
		translate.append("2");
		break;
		case 'd': case 't':
	//case 'D': case 'T':
		translate.append("3");
		break;
		case 'l':
	//case 'L':
		translate.append("4");
		break;
		case 'm': case 'n':
	//case 'M': case 'N':
		translate.append("5");
		break;
		case 'r':
	//case 'R':
		translate.append("6");
		break;
		case 'a': case 'e': case 'i': case 'o': case 'u': case 'y':
		translate.append("*");
		break;
		case 'h': case 'w':
			translate.append("_");
			break;
		}
	}

}
void process() {
	for(int i = translate.length()-1; i> 1 ; i-- ){
		if(translate[i] == translate[i-1]){
			translate.erase(i,1);
		}
		else if(translate[i] == '_' && translate[i-1] == translate[i+1]){
			translate.erase(i,2);
		}
	}
	for(int i = translate.length()-1; i > 0; i--){
		if(translate.at(i) == '*' || translate.at(i) == '_'){
			translate.erase(i,1);
		}
	}
	while(translate.length() < 4){
		translate.append("0");
		}
	while(translate.length() > 4){
		translate.erase(translate.length()-1);
	}
	cout << translate <<endl;
}
int main() {
	while(1){
		name = "";
		translate = "";
		cout << "Enter the last name:" << endl;
		cin >> name;
		transform(name.begin(), name.end(), name.begin(), ::tolower);
		name[0] = toupper(name[0]);
		cout << name <<endl;
		getNum();
		process();
	}
}
