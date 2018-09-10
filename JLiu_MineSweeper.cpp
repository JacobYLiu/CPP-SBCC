
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <time.h>
#include <vector>
#include <sstream>
using namespace std;


class Minesweeper {

public:

    int inputSize;
	int inputLevel;
	int minesCount;
    vector< vector<string> > row;
    vector< vector<bool> > kaboom;

    void create(int size, int level);
    void print();
    bool checkGameOver(int x, int y);
    void checkSurround(int x, int y);
    bool checkWin();
};
Minesweeper m;

void Minesweeper::create(int size, int level){
    inputSize=size;
    inputLevel=level;
    srand(time(NULL));

    //Create the minefield to be displayed
    for (int i=0; i<size; i++) {
        vector<string> col(size);
        row.push_back(col);
    }

    //Create the boolean minefield (not displayed)
    for (int i=0; i<size; i++) {
        vector<bool> kaboomCol(size);
        kaboom.push_back(kaboomCol);
    }

    //Switch statement places mines on random (x,y) coordinates of boolean field
    int xMines; //Target # of mines

    switch (level) {
        case 1://easy
            xMines=((size*size)/8)+3;
            for (int i=0; i<xMines; i++) {
                int randmX=(rand()%size+0);
                int randmY=(rand()%size+0);
                kaboom[randmX][randmY]=true;
            }
            break;
        case 2://medium
            xMines=((size*size)/4)+3;
            for (int i=0; i<xMines; i++) {
                int randmX=(rand()%size+0);
                int randmY=(rand()%size+0);
                kaboom[randmX][randmY]=true;
            }
            break;
        default:
            break;
    }

    //Determine # of mines generated and populate minefiled for display
    minesCount=0;
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            if (kaboom[i][j]) {
                minesCount++;
                row[i][j]="O";
            } else {
                row[i][j]="O";
            }
        }
    }

}

void Minesweeper::print(){
    //Print column header
    cout<<"\n \t";
    for (int i=1; i<inputSize+1; i++) {
        cout<<"*"<<i<<"*\t";
    }
    cout<<"\n\n";

    //Print rows with headers and footers
    for (int i=0; i<inputSize; i++) {
        cout<<"*"<<i+1<<"* \t";
        for (int j=0; j<inputSize; j++) {
            cout<<" "<<row[i][j];
            cout<<"\t";
        }
        cout<<"*"<<i+1<<"*\n\n";
    }

    //Print column footer
    cout<<" \t";
    for (int i=1; i<inputSize+1; i++) {
        cout<<"*"<<i<<"*\t";
    }
    cout<<"\n\nNumber of mines: "<<minesCount<<"\n\n";
}

bool Minesweeper::checkGameOver(int x, int y){
    x=x-1;
    y=y-1;
    //Checks for "Game Over"
    if (kaboom[x][y]) {
        for (int i=0; i<inputSize; i++) {
            for (int j=0; j<inputSize; j++) {
                if (kaboom[i][j]) {
                    row[i][j]="X";
                }
            }
        }

    } else {
        checkSurround(x, y);
    }
    return kaboom[x][y];
}

void Minesweeper::checkSurround(int x, int y){
    //Check cells surrounding the cell selected by the user
    int x2, y2;
    int count=0; //count of mines found around selected cell
    for (int i=-1; i<2; i++) {
        for (int j=-1; j<2; j++) {
            x2=x+i;
            y2=y+j;
            if ((x2>=0)&&(x2<inputSize)&&(y2>=0)&&(y<inputSize)) {
                if (kaboom[x2][y2]) {
                    count++;
                }
            }
        }
    }
  string temp;
  ostringstream convert;
  convert << count;
  temp = convert.str();
    row[x][y]=temp;
}

bool Minesweeper::checkWin(){
    int winCount=0; //count used to determine if all safe cells have been discovered
    for (int i=0; i<inputSize; i++) {
        for (int j=0; j<inputSize; j++) {
            if (!kaboom[i][j]) {
                if (row[i][j]!="O") {
                    winCount++;
                }
            }
        }
    }
    if (winCount==((inputSize*inputSize)-minesCount)) {
        return true;
    } else{
        return false;
    }
}

int main(int argc, const char * argv[]) {
    int size;
    int level;
    int x, y;
    Minesweeper game;

    cout<<"What size do you want your map to be?\n";
    cin>>size;
    cout<<"What difficulty do you want?" <<endl;
    cout<<"1. Easy?"<<endl;
    cout<<"2. Medium?"<<endl;
    cin>>level;
    game.create(size, level);
    game.print();
    x=0;
    y=0;
    while ((x!=25)&&(y!=25)) {
        cout<<"What cell would you like to check?\nRow: ";
        cin>>x;
        cout<<"Column: ";
        cin>>y;
        if(game.checkGameOver(x, y)){
            game.print();
            cout<<"Game Over"<<endl;
            x=25;
            y=25;
        } else if (game.checkWin()){
            game.print();
            cout<<"You won!"<< endl;
            x=25;
            y=25;
        } else{
            game.print();
        }
    }

    return 0;
}
