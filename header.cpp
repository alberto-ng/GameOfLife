# include "grid.h"
# include "classic.h"
# include "header.h"
# include <iostream>
# include <fstream>

void header::setDoor(){

    cout << "Enter 1 for file input, enter 2 for random assignment: " << endl;
    cin >> door;

    while (door != "1" && door != "2"){
        cout << "Invalid input.\n Enter 1 for file input, enter 2 for random assignment: " << endl;
        cin >> door;
    }
}

string header::getDoor(){
    return door;
}

void header::setMode(){
    cout << "Enter 1 for classic mode, 2 for donut mode, 3 for mirror mode: " << endl;
    cin >> mode;

    while (mode != "1" && mode != "2" && mode != "3"){
        cout << "Invalid input.\n Enter 1 for classic mode, 2 for donut mode, 3 for mirror mode: " << endl;
        cin >> mode;
    }
}

string header::getMode(){
    return mode;
}

void header::setOut(){
    cout << "Enter 1 for brief pause before next generation." << endl;
    cout << "Enter 2 for enter to next generation." << endl;
    cout << "Enter 3 for output to file: " << endl;
    cin >> out;

    while (out != "1" && out != "2" && out != "3"){
        cout << "Invalid input." << endl;
        cout << " Enter 1 for brief pause before next generation." << endl;
        cout << " Enter 2 for enter to next generation." << endl;
        cout << " Enter 3 for output to file: " << endl;
        cin >> out;
    }
}

string header::getOut(){
    return out;
}

void header::setRow(){
    cout << "Enter an integer for length of row: " << endl;
    cin >> row;
}

int header::getRow(){
    return row;
}

void header::setCol(){
    cout << "Enter an integer for length of row: " << endl;
    cin >> col;
}

int header::getCol(){
    return col;
}


void header::setDen(){
    cout << "Enter an decimal from 0-1 for density: " << endl;
    cin >> den;
}

double header::getDen(){
    return den;
}

string header::getFileName(){
    cout << "Enter a file: " << endl;
    cin >> fileName;
    return fileName;
}
