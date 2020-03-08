# include <iostream>

using namespace std;

class classic{
    public:
        classic();
        classic(int num1, int num2);
        classic(classic *grid);
        ~classic();


        int checkN();
        void setGrid(double d);
        void getGrid();
        void changeStat();
        void getNextGrid(classic *grid);

        char **myGrid;
        int row, column, currRow, currCol, Ntotal;


};
