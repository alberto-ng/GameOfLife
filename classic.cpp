# include "classic.h"
# include "grid.h"
# include <iostream>
# include <cmath>

// default constructor

classic::classic(){

}


classic::~classic(){

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
