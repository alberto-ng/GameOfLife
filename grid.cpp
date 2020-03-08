# include "grid.h"
# include "classic.h"
# include <iostream>
# include <cmath>
# include <fstream>

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
    trueCounter = 0;
    generation = 1;
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
    trueCounter = 0;
    generation = 1;
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
    double Xdecimal = arraySize * d;

    if (remainder(Xdecimal, 1) >= 0.5){
        Xdecimal += (1 - remainder(Xdecimal, 1));
    }
    else {
        Xdecimal -= remainder(Xdecimal, 1);
    }

    Xcounter = (int)Xdecimal;

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
    cout << "Current generation: " << endl;
    for (int i = 0; i < row; ++i){
        currRow = i;
        for (int j = 0; j < column; ++j){
            currCol = j;
            cout << currGrid[i][j];
        }
        cout << endl;
    }
}

void grid::getFileGrid(ofstream& x){

    x << "Current generation: " << endl;
    for (int i = 0; i < row; ++i){
        currRow = i;
        for (int j = 0; j < column; ++j){
            currCol = j;
            x << currGrid[i][j];
        }
        x << endl;
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



void grid::getFileNextGen(ofstream& x){
    x << "Generation: " << generation++ << endl;

    for (int i = 0; i < row; ++i){
        currRow = i;
        for (int j = 0; j < column; ++j){
            currCol = j;
            changeStat();
            x << nextGrid[i][j];
        }
        x << endl;
    }
}

void grid::setFileGrid(ifstream& x){
    string line = "";
    x >> line;
    for (int i = 0; i < row; ++i){
        for (int j = 0; j < column; ++j){
            if (line.at(j) == '-'){
                currGrid[i][j] = '-';
            }
            else if (line.at(j) == 'X'){
                currGrid[i][j] = 'X';
            }
        }
        x >> line;
    }
}

bool grid::isStable(){
    for (int m = 0; m < row; ++m){
        for (int n = 0; n < column; ++n){
            if (nextGrid[m][n] != currGrid[m][n]){
                return false;
            }
        }
    }
    ++trueCounter;
    if (trueCounter == 3){
        trueCounter = 0;
        return true;
    }
    return false;
}

bool grid::isEmpty(){
    for (int m = 0; m < row; ++m){
        for (int n = 0; n < column; ++n){
            if (nextGrid[m][n] == 'X'){
                return false;
            }
        }
    }

    return true;
}
