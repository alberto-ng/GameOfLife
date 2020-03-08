# include "grid.h"
# include "classic.h"
# include <iostream>
# include <cmath>

// default constructor
grid::grid(){
    currGrid = new char *[5];
    nextGrid = new char *[5];
    for (int i = 0; i < 5; ++i){
        currGrid[i] = new char[5];
        nextGrid[i] = new char[5];
    }

    for (int m = 0; m < 5; ++m){
        for (int n = 0; n < 5; ++n){
            currGrid[m][n] = '-';
            nextGrid[m][n] = '-';
        }
    }
    row = 5;
    column = 5;
    currRow = 0;
    currCol = 0;
}

// overloaded constructor
grid::grid(int num1, int num2){
    row = num1;
    column = num2;
    currGrid = new char *[row];
    nextGrid = new char *[row];
    for (int i = 0; i < row; ++i){
        currGrid[i] = new char[column];
        nextGrid[i] = new char[column];
    }

    for (int m = 0; m < row; ++m){
        for (int n = 0; n < column; ++n){
            currGrid[m][n] = '-';
            nextGrid[m][n] = '-';
        }
    }
    currRow = 0;
    currCol = 0;
}

void grid::resetNextGen(){
    currGrid = nextGrid;
    nextGrid = new char *[row];
    for (int i = 0; i < row; ++i){
        nextGrid[i] = new char[column];
    }

    for (int m = 0; m < row; ++m){
        for (int n = 0; n < column; ++n){
            nextGrid[m][n] = '-';
        }
    }
}

grid::~grid(){
    delete currGrid;
}

void grid::setGrid(double d){
    int Xcounter = 0;
    double arraySize = (double)row * column;
    cout << "array size: " << arraySize << endl;
    double Xdecimal = arraySize * d;

    cout << "Xdecimal: " << Xdecimal << endl;
    if (remainder(Xdecimal, 1) >= 0.5){
        Xdecimal += (1 - remainder(Xdecimal, 1));
    }
    else {
        Xdecimal -= remainder(Xdecimal, 1);
    }

    cout << "Xdecimal: " << Xdecimal << endl;

    Xcounter = (int)Xdecimal;
    cout << "Xcounter: " << Xcounter << endl;

    while (Xcounter != 0){
        for (int i = 0; i < row; ++i){
            if (Xcounter == 0){
                break;
            }
            for (int j = 0; j < column; ++j){
                if (Xcounter == 0){
                    break;
                }
                double random = ((double)rand()/RAND_MAX);
                if (random < d){
                    if (currGrid[i][j] == '-'){
                        currGrid[i][j] = 'X';
                        --Xcounter;
                    }
                }
            }
        }
    }
}


int grid::checkNclassic(){
    int Ntotal = 0;

    if (currRow == 0 || currRow == (row - 1)){
        if (currRow == 0){
            if (currCol == 0){
                if (currGrid[currRow][currCol + 1] == 'X'){
                    ++Ntotal;
                }
                if (currGrid[currRow + 1][currCol] == 'X'){
                    ++Ntotal;
                }
                if (currGrid[currRow + 1][currCol + 1] == 'X'){
                    ++Ntotal;
                }
            }
            else if (currCol == (column - 1)){
                if (currGrid[currRow][currCol - 1] == 'X'){
                    ++Ntotal;
                }
                if (currGrid[currRow + 1][currCol - 1] == 'X'){
                    ++Ntotal;
                }
                if (currGrid[currRow + 1][currCol] == 'X'){
                    ++Ntotal;
                }
            }
            else {
                if (currGrid[currRow][currCol - 1] == 'X'){
                    ++Ntotal;
                }
                if (currGrid[currRow][currCol + 1] == 'X'){
                    ++Ntotal;
                }
                if (currGrid[currRow + 1][currCol - 1] == 'X'){
                    ++Ntotal;
                }
                if (currGrid[currRow + 1][currCol] == 'X'){
                    ++Ntotal;
                }
                if (currGrid[currRow + 1][currCol + 1] == 'X'){
                    ++Ntotal;
                }
            }
        }

        else if (currRow == (row - 1)){
            if (currCol == 0){
                if (currGrid[currRow][currCol + 1] == 'X'){
                    ++Ntotal;
                }
                if (currGrid[currRow - 1][currCol] == 'X'){
                    ++Ntotal;
                }
                if (currGrid[currRow - 1][currCol + 1] == 'X'){
                    ++Ntotal;
                }
            }
            else if (currCol == (column - 1)){
                if (currGrid[currRow][currCol - 1] == 'X'){
                    ++Ntotal;
                }
                if (currGrid[currRow - 1][currCol - 1] == 'X'){
                    ++Ntotal;
                }
                if (currGrid[currRow - 1][currCol] == 'X'){
                    ++Ntotal;
                }
            }
            else {
                if (currGrid[currRow][currCol - 1] == 'X'){
                    ++Ntotal;
                }
                if (currGrid[currRow][currCol + 1] == 'X'){
                    ++Ntotal;
                }
                if (currGrid[currRow - 1][currCol - 1] == 'X'){
                    ++Ntotal;
                }
                if (currGrid[currRow - 1][currCol] == 'X'){
                    ++Ntotal;
                }
                if (currGrid[currRow - 1][currCol + 1] == 'X'){
                    ++Ntotal;
                }
            }
        }

    }

    else if (currCol == 0 || currCol == (column - 1)){
        if (currCol == 0){
            if (currGrid[currRow][currCol + 1] == 'X'){
                ++Ntotal;
            }
            if (currGrid[currRow - 1][currCol] == 'X'){
                ++Ntotal;
            }
            if (currGrid[currRow - 1][currCol + 1] == 'X'){
                ++Ntotal;
            }
            if (currGrid[currRow + 1][currCol] == 'X'){
                ++Ntotal;
            }
            if (currGrid[currRow + 1][currCol + 1] == 'X'){
                ++Ntotal;
            }
        }

        else if (currCol == (column - 1)){
            if (currGrid[currRow - 1][currCol] == 'X'){
                ++Ntotal;
            }
            if (currGrid[currRow - 1][currCol - 1] == 'X'){
                ++Ntotal;
            }
            if (currGrid[currRow][currCol - 1] == 'X'){
                ++Ntotal;
            }
            if (currGrid[currRow + 1][currCol - 1] == 'X'){
                ++Ntotal;
            }
            if (currGrid[currRow + 1][currCol] == 'X'){
                ++Ntotal;
            }
        }
    }

    else {
        if (currGrid[currRow][currCol - 1] == 'X'){
            ++Ntotal;
        }
        if (currGrid[currRow][currCol + 1] == 'X'){
            ++Ntotal;
        }
        if (currGrid[currRow - 1][currCol - 1] == 'X'){
            ++Ntotal;
        }
        if (currGrid[currRow - 1][currCol] == 'X'){
            ++Ntotal;
        }
        if (currGrid[currRow - 1][currCol + 1] == 'X'){
            ++Ntotal;
        }
        if (currGrid[currRow + 1][currCol - 1] == 'X'){
            ++Ntotal;
        }
        if (currGrid[currRow + 1][currCol] == 'X'){
            ++Ntotal;
        }
        if (currGrid[currRow + 1][currCol + 1] == 'X'){
            ++Ntotal;
        }
    }
    return Ntotal;
}

void grid::getGrid(){
    cout << "current gen: " << endl;
    for (int i = 0; i < row; ++i){
        currRow = i;
        for (int j = 0; j < column; ++j){
            currCol = j;
            cout << currGrid[i][j];
        }
        cout << endl;
    }
}

void grid::changeStat(){
    int Ntotal = checkNclassic();

    if (Ntotal <= 1){
        nextGrid[currRow][currCol] = '-';
    }
    else if (Ntotal == 2){
        if (currGrid[currRow][currCol] == 'X'){
            nextGrid[currRow][currCol] = 'X';
        }
        else {
            nextGrid[currRow][currCol] = '-';
        }
    }
    else if (Ntotal == 3){
        nextGrid[currRow][currCol] = 'X';
    }
    else{
        nextGrid[currRow][currCol] = '-';
    }
}

void grid::getNextGen(){

    cout << "new gen: " << endl;
    for (int i = 0; i < row; ++i){
        currRow = i;
        for (int j = 0; j < column; ++j){
            currCol = j;
            changeStat();
            cout << nextGrid[i][j];
        }
        cout << endl;
    }
}
