# include "life.h"
# include "grid.h"
# include "classic.h"
#include <iostream>
#include <fstream>

using namespace std;

int main (int argc, char **argv){
    //grid *grid1 = new grid();
    //grid1 -> getGrid();
    //grid *grid2 = new grid(6, 7);
    //grid2 -> getGrid();
    grid *grid3 = new grid(8, 5);
    grid3 -> setGrid(0.2);
    grid3 -> getGrid();
    grid3 -> getNextGrid();

    delete grid3;
    return 0;
}
