# include "grid.h"
# include "classic.h"
# include "header.h"
#include <iostream>
#include <fstream>

using namespace std;

int main (int argc, char **argv){
    int generation = 0;
    string door, mode, out, word, fileName;
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
            ifstream inFile;

            inFile.open(h.getFileName());
            if (inFile.fail()){
                // while fail, kept prompting unil user quits or enter a valid file
                while (inFile.fail()){
                    cout << "Failed. Enter a valid file." << endl;
                    inFile.open(h.getFileName());
                }
            }

            inFile >> row;
            inFile >> column;

            grid *grid1 = new grid(row, column);
            grid1 -> setFileGrid(inFile);

            grid1 -> getGrid();


            while (word != "quit"){
                grid1 -> getNextGen();

                if (grid1 -> isStable()){
                    break;
                }

                grid1 -> resetNextGen();
                // grid1 -> getNextGen();

                cout << "continue?" << endl;
                cin >> word;
            }

            inFile.close();
            delete grid1;
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

            grid *grid1 = new grid(row, column);

            grid1 -> setGrid(d);

            grid1 -> getGrid();

            while (word != "quit"){
                grid1 -> getNextGen();

                if (grid1 -> isStable()){
                    break;
                }

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
