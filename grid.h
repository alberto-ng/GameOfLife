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
        int checkNclassic();
        void changeStat();
        void getNextGen();
        void resetNextGen();
        void setFileGrid(ifstream& x);
        bool isStable();
        bool isEmpty();

        // aux/helper functions


        // variables
        char **currGrid, **nextGrid;
        int row, column, currRow, currCol;
        int trueCounter;
};
