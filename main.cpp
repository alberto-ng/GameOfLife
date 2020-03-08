# include "grid.h"
# include "classic.h"
# include "header.h"
# include <iostream>
# include <fstream>
# include <unistd.h>

using namespace std;

int main (int argc, char **argv) {
    int generation = 1;
    int first = 0;
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
    if (door == "1") {
        // classic
        if (mode == "1") {
            ifstream inFile;

            inFile.open(h.getFileName());
            if (inFile.fail()) {
                // while fail, kept prompting unil user quits or enter a valid file
                while (inFile.fail()) {
                    cout << "Failed. Enter a valid file." << endl;
                    inFile.open(h.getFileName());
                }
            }

            inFile >> row;
            inFile >> column;

            grid *grid1 = new grid(row, column);
            grid1 -> setFileGrid(inFile);

            if (out == "1") {
                grid1 -> getGrid();
                sleep(1);

                while (true) {
                    cout << "Generation: " << generation++ << endl;
                    grid1 -> getNextGen();

                    if (grid1 -> isStable() || grid1 -> isEmpty()) {
                        break;
                    }

                    grid1 -> resetNextGen();
                    sleep(1);

                }

            }
            else if (out == "2") {
                grid1 -> getGrid();
                cout << "Press enter for next generation." << endl;
                if (cin.get() == '\n'){
                    ++first;
                }

                if (first == 1) {
                while (cin.get() == '\n') {
                        cout << "Generation: " << generation++ << endl;
                        grid1 -> getNextGen();

                        if (grid1 -> isStable() || grid1 -> isEmpty()){
                            cout << "press enter to quit. anything else to continue." << endl;
                            if (cin.get() == '\n'){
                                break;
                            }
                        }

                        grid1 -> resetNextGen();

                        cout << "Press enter for next generation.";
                    }
                }
            }
            else{
                ofstream outFile;
                outFile.open("albertoNg.out");

                grid1 -> getFileGrid(outFile);

                while (true) {

                    grid1 -> getFileNextGen(outFile);

                    if (grid1 -> isStable() || grid1 -> isEmpty()) {
                        break;
                    }

                    grid1 -> resetNextGen();

                }
                outFile.close();
            }

            inFile.close();
            delete grid1;
        }
        // donut
        else if (mode == "2") {

        }
        // mirror
        else {

        }
    }
    // random assignment
    else {
        // classic
        if (mode == "1") {
            h.setRow();
            h.setCol();
            h.setDen();
            row = h.getRow();
            column = h.getCol();
            d = h.getDen();

            grid *grid1 = new grid(row, column);

            grid1 -> setGrid(d);

            if (out == "1") {
                grid1 -> getGrid();
                sleep(1);

                while (true) {
                    cout << "Generation: " << generation++ << endl;
                    grid1 -> getNextGen();

                    if (grid1 -> isStable() || grid1 -> isEmpty()) {
                        break;
                    }

                    grid1 -> resetNextGen();
                    sleep(1);

                }
            }
            else if (out == "2") {
                grid1 -> getGrid();

                cout << "Press enter for next generation." << endl;
                if (cin.get() == '\n') {
                    ++first;
                }


                if (first == 1) {
                    while (cin.get() == '\n') {
                        cout << "Generation: " << generation++ << endl;
                        grid1 -> getNextGen();

                        if (grid1 -> isStable() || grid1 -> isEmpty()) {
                            cout << "press enter to quit. anything else to continue." << endl;
                            if (cin.get() == '\n') {
                                break;
                            }
                        }

                        grid1 -> resetNextGen();

                        cout << "Press enter for next generation.";
                    }
                }
            }
            else {
                ofstream outFile;
                outFile.open("albertoNg.out");

                grid1 -> getFileGrid(outFile);
                while (true) {
                    grid1 -> getFileNextGen(outFile);

                    if (grid1 -> isStable() || grid1 -> isEmpty()) {
                        break;
                    }

                    grid1 -> resetNextGen();

                }
                outFile.close();
            }

            delete grid1;
        }
        // donut
        else if (mode == "2") {

        }
        // mirror
        else {

        }
    }

    return 0;
}
