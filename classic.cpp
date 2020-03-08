# include "classic.h"
# include "grid.h"
# include <iostream>

// default constructor

classic::classic(){
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



classic::classic(int num1, int num2){
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


classic::~classic(){
    delete myGrid;
}

void classic::setGrid(double d){
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

void classic::getGrid(){
    for (int i = 0; i < row; ++i){
        for (int j = 0; j < column; ++j){
            cout << myGrid[i][j];
        }
        cout << endl;
    }
}

void classic::changeStat(){
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




int classic::checkN(){
    Ntotal = 0;

    if (currRow == 0 || currRow == (row - 1)){
        if (currRow == 0){
            if (currCol == 0){
                if (myGrid[currRow][currCol + 1] == 'X'){
                    ++Ntotal;
                }
                if (myGrid[currRow + 1][currCol] == 'X'){
                    ++Ntotal;
                }
                if (myGrid[currRow + 1][currCol + 1] == 'X'){
                    ++Ntotal;
                }
            }
            else if (currCol == (column - 1)){
                if (myGrid[currRow][currCol - 1] == 'X'){
                    ++Ntotal;
                }
                if (myGrid[currRow + 1][currCol - 1] == 'X'){
                    ++Ntotal;
                }
                if (myGrid[currRow + 1][currCol] == 'X'){
                    ++Ntotal;
                }
            }
            else {
                if (myGrid[currRow][currCol - 1] == 'X'){
                    ++Ntotal;
                }
                if (myGrid[currRow][currCol + 1] == 'X'){
                    ++Ntotal;
                }
                if (myGrid[currRow + 1][currCol - 1] == 'X'){
                    ++Ntotal;
                }
                if (myGrid[currRow + 1][currCol] == 'X'){
                    ++Ntotal;
                }
                if (myGrid[currRow + 1][currCol + 1] == 'X'){
                    ++Ntotal;
                }
            }
        }

        else if (currRow == (row - 1)){
            if (currCol == 0){
                if (myGrid[currRow][currCol + 1] == 'X'){
                    ++Ntotal;
                }
                if (myGrid[currRow - 1][currCol] == 'X'){
                    ++Ntotal;
                }
                if (myGrid[currRow - 1][currCol + 1] == 'X'){
                    ++Ntotal;
                }
            }
            else if (currCol == (column - 1)){
                if (myGrid[currRow][currCol - 1] == 'X'){
                    ++Ntotal;
                }
                if (myGrid[currRow - 1][currCol - 1] == 'X'){
                    ++Ntotal;
                }
                if (myGrid[currRow - 1][currCol] == 'X'){
                    ++Ntotal;
                }
            }
            else {
                if (myGrid[currRow][currCol - 1] == 'X'){
                    ++Ntotal;
                }
                if (myGrid[currRow][currCol + 1] == 'X'){
                    ++Ntotal;
                }
                if (myGrid[currRow - 1][currCol - 1] == 'X'){
                    ++Ntotal;
                }
                if (myGrid[currRow - 1][currCol] == 'X'){
                    ++Ntotal;
                }
                if (myGrid[currRow - 1][currCol + 1] == 'X'){
                    ++Ntotal;
                }
            }
        }

    }

    else if (currCol == 0 || currCol == (column - 1)){
        if (currCol == 0){
            if (myGrid[currRow][currCol + 1] == 'X'){
                ++Ntotal;
            }
            if (myGrid[currRow - 1][currCol] == 'X'){
                ++Ntotal;
            }
            if (myGrid[currRow - 1][currCol + 1] == 'X'){
                ++Ntotal;
            }
            if (myGrid[currRow + 1][currCol] == 'X'){
                ++Ntotal;
            }
            if (myGrid[currRow + 1][currCol + 1] == 'X'){
                ++Ntotal;
            }
        }

        else if (currCol == (column - 1)){
            if (myGrid[currRow - 1][currCol] == 'X'){
                ++Ntotal;
            }
            if (myGrid[currRow - 1][currCol - 1] == 'X'){
                ++Ntotal;
            }
            if (myGrid[currRow][currCol - 1] == 'X'){
                ++Ntotal;
            }
            if (myGrid[currRow + 1][currCol - 1] == 'X'){
                ++Ntotal;
            }
            if (myGrid[currRow + 1][currCol] == 'X'){
                ++Ntotal;
            }
        }

        else {
            if (myGrid[currRow][currCol - 1] == 'X'){
                ++Ntotal;
            }
            if (myGrid[currRow][currCol + 1] == 'X'){
                ++Ntotal;
            }
            if (myGrid[currRow - 1][currCol - 1] == 'X'){
                ++Ntotal;
            }
            if (myGrid[currRow - 1][currCol] == 'X'){
                ++Ntotal;
            }
            if (myGrid[currRow - 1][currCol + 1] == 'X'){
                ++Ntotal;
            }
            if (myGrid[currRow + 1][currCol - 1] == 'X'){
                ++Ntotal;
            }
            if (myGrid[currRow + 1][currCol] == 'X'){
                ++Ntotal;
            }
            if (myGrid[currRow + 1][currCol + 1] == 'X'){
                ++Ntotal;
            }
        }
    }
    return Ntotal;
}
