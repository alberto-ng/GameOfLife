# include "grid.h"
# include "classic.h"
# include "header.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main (int argc, char **argv){
    int generation = 0;
    string door, mode, out, word;
    int row, column;
    float d;

    header h;
    h.setDoor();
    h.setMode();
    h.setOut();


    door = h.getDoor();
    mode = h.getMode();
    out = h.getOut();

    // file input
    if (door == "1"){
        // classic
        if (mode == "1"){

        }
        // donut
        else if (mode == "2"){

        }
        // mirror
        else {

        }
    }
    // random assignment
    else {
        // classic
        if (mode == "1"){
            h.setRow();
            h.setCol();
            h.setDen();
            row = h.getRow();
            column = h.getCol();
            d = h.getDen();

            cout << row << column;
            grid *grid1 = new grid(row, column);

            grid1 -> setGrid(d);

            grid1 -> getGrid();

            while (word != "quit"){
                grid1 -> getNextGen();
                grid1 -> resetNextGen();
                // grid1 -> getNextGen();

                cout << "continue?" << endl;
                cin >> word;
            }

            delete grid1;
        }
        // donut
        else if (mode == "2"){

        }
        // mirror
        else {

        }
    }




    return 0;
}
