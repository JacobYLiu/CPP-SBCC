#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <cstring>
#include <string.h>
#include <iomanip>
using namespace std;
// A function to generate odd sized magic squares
class Squares {
	int n;
	vector<vector<int> > box;
public:
	Squares(int o) {
		n = o;
		box.resize(n, vector<int>(n, 0)); // setting all "rooms" to 0

		int i = 0;
		int j = n / 2;
		for (int num = 1; num <= n * n; ++num) { //1st condition helper if next number is goes to out of square's upper side
			if (i < 0) {
				i = n - 1; //1st condition helper if next number goes to out of square's right side
			} else if (j == n) { // when columns is n
				j = 0;
			} else if (box[i][j] != 0) {
				j -= 1;
				i += 2;
			} else if (i == 0 && j == (n - 1)) {
				box[i][j] = num;
				i++;
				//continue;
				num++;
			}
		box[i][j] = num;

			j++;
			i--;
		}

//		int formula = n * (n * n + 1) / 2;
	}
	void display() {
		int expsq = n * n;
		int sum = n * (expsq + 1) / 2;
		cout << "The sum of the integers: " << sum << endl;
		int rowAdd = 0;
		int colAdd = 0;
		for (int i = 0; i < n; i++) { // row
			for (int j = 0; j < n; j++) { // column
				cout << setw(6);
				rowAdd += box[i][j];
				cout << box[i][j];
				colAdd += box[0][j];

			}
			cout << "\t" << rowAdd << "\n";
			rowAdd = 0;
		}
		cout << colAdd << endl;
		colAdd = 0;
	}

};
int main() {
	int n;
	cout << "What is the number of sides do you want to make?" << endl;
	cin >> n;
	Squares magic(n);
	magic.display();
	return 0;
}
