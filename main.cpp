# include "grid.h"
# include "header.h"
# include <iostream>
# include <fstream>
# include <unistd.h>

using namespace std;

int main (int argc, char **argv) {

    int generation = 1;
    int first = 0;
    string door, mode, out, fileName;
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

        // classic
        if (mode == "1") {
            grid1 -> changeMode(1);
            if (out == "1") {
                grid1 -> getGrid();
                sleep(1);

                while (true) {
                    cout << "Generation: " << generation++ << endl;
                    grid1 -> getNextGen();

                    if (grid1 -> isStable() || grid1 -> isEmpty()) {
                        if (grid1 -> isEmpty()){
                            cout << "Empty." << endl;
                            if (cin.get() == '\n'){
                                break;
                            }
                        }
                        else {
                            cout << "Stable." << endl;
                            if (cin.get() == '\n'){
                                break;
                            }
                        }
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
                            if (grid1 -> isEmpty()){
                                cout << "Empty." << endl;
                                if (cin.get() == '\n'){
                                    break;
                                }
                            }
                            else {
                                cout << "Stable." << endl;
                                if (cin.get() == '\n'){
                                    break;
                                }
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
        }
        // donut
        else if (mode == "2") {
            grid1 -> changeMode(2);
            if (out == "1") {
                grid1 -> getGrid();
                sleep(1);

                while (true) {
                    cout << "Generation: " << generation++ << endl;
                    grid1 -> getNextGen();

                    if (grid1 -> isStable() || grid1 -> isEmpty()) {
                        if (grid1 -> isEmpty()){
                            cout << "Empty." << endl;
                            if (cin.get() == '\n'){
                                break;
                            }
                        }
                        else {
                            cout << "Stable." << endl;
                            if (cin.get() == '\n'){
                                break;
                            }
                        }
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
                            if (grid1 -> isEmpty()){
                                cout << "Empty." << endl;
                                if (cin.get() == '\n'){
                                    break;
                                }
                            }
                            else {
                                cout << "Stable." << endl;
                                if (cin.get() == '\n'){
                                    break;
                                }
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
        }
        // mirror
        else {
            grid1 -> changeMode(3);
            if (out == "1") {
                grid1 -> getGrid();
                sleep(1);

                while (true) {
                    cout << "Generation: " << generation++ << endl;
                    grid1 -> getNextGen();

                    if (grid1 -> isStable() || grid1 -> isEmpty()) {
                        if (grid1 -> isEmpty()){
                            cout << "Empty." << endl;
                            if (cin.get() == '\n'){
                                break;
                            }
                        }
                        else {
                            cout << "Stable." << endl;
                            if (cin.get() == '\n'){
                                break;
                            }
                        }
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
                            if (grid1 -> isEmpty()){
                                cout << "Empty." << endl;
                                if (cin.get() == '\n'){
                                    break;
                                }
                            }
                            else {
                                cout << "Stable." << endl;
                                if (cin.get() == '\n'){
                                    break;
                                }
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
        }

        inFile.close();
        delete grid1;
    }
    // random assignment
    else {
        h.setRow();
        h.setCol();
        h.setDen();
        row = h.getRow();
        column = h.getCol();
        d = h.getDen();

        grid *grid1 = new grid(row, column);

        grid1 -> setGrid(d);
        // classic
        if (mode == "1") {
            grid1 -> changeMode(1);

            if (out == "1") {
                grid1 -> getGrid();
                sleep(1);

                while (true) {
                    cout << "Generation: " << generation++ << endl;
                    grid1 -> getNextGen();

                    if (grid1 -> isStable() || grid1 -> isEmpty()) {
                        if (grid1 -> isEmpty()){
                            cout << "Empty." << endl;
                            if (cin.get() == '\n'){
                                break;
                            }
                        }
                        else {
                            cout << "Stable." << endl;
                            if (cin.get() == '\n'){
                                break;
                            }
                        }
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
                            if (grid1 -> isEmpty()){
                                cout << "Empty." << endl;
                                if (cin.get() == '\n'){
                                    break;
                                }
                            }
                            else {
                                cout << "Stable." << endl;
                                if (cin.get() == '\n'){
                                    break;
                                }
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
        }
        // donut
        else if (mode == "2") {
            grid1 -> changeMode(2);
            if (out == "1") {
                grid1 -> getGrid();
                sleep(1);

                while (true) {
                    cout << "Generation: " << generation++ << endl;
                    grid1 -> getNextGen();

                    if (grid1 -> isStable() || grid1 -> isEmpty()) {
                        if (grid1 -> isEmpty()){
                            cout << "Empty." << endl;
                            if (cin.get() == '\n'){
                                break;
                            }
                        }
                        else {
                            cout << "Stable." << endl;
                            if (cin.get() == '\n'){
                                break;
                            }
                        }
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
                            if (grid1 -> isEmpty()){
                                cout << "Empty." << endl;
                                if (cin.get() == '\n'){
                                    break;
                                }
                            }
                            else {
                                cout << "Stable." << endl;
                                if (cin.get() == '\n'){
                                    break;
                                }
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
                        if (grid1 -> isEmpty()){
                            cout << "Empty." << endl;
                            if (cin.get() == '\n'){
                                break;
                            }
                        }
                        else {
                            cout << "Stable." << endl;
                            if (cin.get() == '\n'){
                                break;
                            }
                        }
                    }

                    grid1 -> resetNextGen();

                }
                outFile.close();
            }
        }
        // mirror
        else {
            grid1 -> changeMode(3);
            if (out == "1") {
                grid1 -> getGrid();
                sleep(1);

                while (true) {
                    cout << "Generation: " << generation++ << endl;
                    grid1 -> getNextGen();

                    if (grid1 -> isStable() || grid1 -> isEmpty()) {
                        if (grid1 -> isEmpty()){
                            cout << "Empty." << endl;
                            if (cin.get() == '\n'){
                                break;
                            }
                        }
                        else {
                            cout << "Stable." << endl;
                            if (cin.get() == '\n'){
                                break;
                            }
                        }
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
                            if (grid1 -> isEmpty()){
                                cout << "Empty." << endl;
                                if (cin.get() == '\n'){
                                    break;
                                }
                            }
                            else {
                                cout << "Stable." << endl;
                                if (cin.get() == '\n'){
                                    break;
                                }
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
                        if (grid1 -> isEmpty()){
                            cout << "Empty." << endl;
                            if (cin.get() == '\n'){
                                break;
                            }
                        }
                        else {
                            cout << "Stable." << endl;
                            if (cin.get() == '\n'){
                                break;
                            }
                        }
                    }

                    grid1 -> resetNextGen();

                }
                outFile.close();
            }
        }

        delete grid1;
    }

    return 0;
}
