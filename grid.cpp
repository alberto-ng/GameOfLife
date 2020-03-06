# include "grid.h"
# include "classic.h"
# include <iostream>
# include <cmath>

// default constructor
grid::grid(){
    myGrid = new char *[5];
    for (int i = 0; i < 5; ++i){
        myGrid[i] = new char[5];
    }

    for (int m = 0; m < 5; ++m){
        for (int n = 0; n < 5; ++n){
            myGrid[m][n] = '-';
        }
    }
    row = 5;
    column = 5;
    currRow = 0;
    currCol = 0;
    Ntotal = 0;
}

// overloaded constructor
grid::grid(int num1, int num2){
    row = num1;
    column = num2;
    myGrid = new char *[row];
    for (int i = 0; i < row; ++i){
        myGrid[i] = new char[column];
    }

    for (int m = 0; m < row; ++m){
        for (int n = 0; n < column; ++n){
            myGrid[m][n] = '-';
        }
    }
    currRow = 0;
    currCol = 0;
    Ntotal = 0;
}

grid::~grid(){
    delete myGrid;
}

void grid::setGrid(double d){
    for (int i = 0; i < row; ++i){
        for (int j = 0; j < column; ++j){
            double randNum = ((double)rand() / RAND_MAX);
            if (randNum > d){
                myGrid[i][j] = '-';
            }
            else {
                myGrid[i][j] = 'X';
            }
        }
    }
}

void grid::changeStat(char **cell){
    checkN();
    if (Ntotal < 2){
        myGrid[currRow][currCol] = '-';
    }
    else if (Ntotal == 2){
        myGrid[currRow][currCol] = myGrid[currRow][currCol];
    }
    else if (Ntotal == 3){
        myGrid[currRow][currCol] = 'X';
    }
    else{
        myGrid[currRow][currCol] = '-';
    }
}



void grid::getGrid(){
    for (int i = 0; i < row; ++i){
        for (int j = 0; j < column; ++j){
            cout << myGrid[i][j];
        }
        cout << endl;
    }
}

void grid::getNextGrid(){
    for (int i = 0; i < row; ++i){
        currRow = i;
        for (int j = 0; j < column; ++j){
            currCol = j;
            changeStat(myGrid);
            cout << myGrid[i][j];
        }
        cout << endl;
    }
}
