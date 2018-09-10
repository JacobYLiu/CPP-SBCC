//============================================================================
// Name        : JLiu_PersonStudent.cpp
// Author      : Jacob Liu
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//============================================================================
// Name        : JLiu_Parent.cpp
// Author      : Jacob Liu
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
using namespace std;

class Person {
public:
	virtual ~Person() {
	}
	void setName(string name) {
		deName = name;
	}
	void setBirthday(string dateOfBirth) {
		birthday = dateOfBirth;
	}
	string deName;
	string birthday;
	virtual void display() {
		cout << "Name      : " << deName << endl;
		cout << "Birthday  : " << birthday << endl;
	}

};
class Instructor: public Person {
public:
	//following the format
	double income;
	~Instructor(){}
	void setSalary(int salary) {
		income = salary;
	}
	virtual void display() {
		cout << "Name      : " << deName << endl;
		cout << "Birthday  : " << birthday << endl;
		cout << "Income    : " << income << endl;
	}
};

class Student: public Person {
public:
	string major;
	~Student(){}
	void setMajor(string myMajor) {
		major = myMajor;
	}
		virtual void display() {
				cout << "Name      : " << deName << endl;
				cout << "Birthday  : " << birthday << endl;
				cout << "Major     : " << major << endl;
			}
};

int main() {
// constructors
	Person fedor;
	Instructor sam;
	Student guilio;

//setting the names and info for the student, instructor, and person.
	fedor.setName("Fedor Kostritsa");
	fedor.setBirthday("November 11, 1992");

	sam.setName("Salmaun Massoman");
	sam.setBirthday("October 12,1984");
	sam.setSalary(90000);

	guilio.setName("Guilio Colleluori");
	guilio.setBirthday("April 25,1992");
	guilio.setMajor("Computer Science");

// Displaying all them
	fedor.display();
	sam.display();
	guilio.display();
	return 0;
}
