# include "grid.h"
# include "classic.h"
#include <iostream>
#include <fstream>

using namespace std;

int main (int argc, char **argv){
    grid *grid1 = new grid();
    //grid *grid2 = new grid(6, 7);
    grid1 -> setGrid(0.5);
    //grid2 -> setGrid(0.2);

    grid1 -> getGrid();
    //grid2 -> getGrid();

    grid1 -> getNextGen();

    grid1 -> resetNextGen();

    grid1 -> getNextGen();



    // if (ans = classic) {
    //     mode = new classic();
    // } else if (ans = mirror) {
    //     mode = new Mirror();
    // }
    //
    // mode -> setGrid(0.5);

    delete grid1;
    //delete grid2;
    return 0;
}
