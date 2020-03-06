# include <iostream>
using namespace std;

class grid{
    public:
        grid(); // default constructor
        grid(int rows, int column); // overloaded constructor
        ~grid(); // destructor

        // core functions
        void setGrid(double d);
        void getGrid();
        void getNextGrid();
        void changeStat(char **cell);

        // aux/helper functions


        // variables
        char **myGrid;
        int row, column, currRow, currCol, Ntotal;
};
