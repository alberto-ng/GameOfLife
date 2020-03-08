# include <iostream>
using namespace std;

class header{
    public:
        // core functions
        void setDoor();
        void setMode();
        void setOut();
        void setRow();
        void setCol();
        void setDen();

        string getOut();
        string getMode();
        string getDoor();
        int getRow();
        int getCol();
        double getDen();

        // aux/helper functions


        // variables
        string door, mode, out;
        int row, col;
        double den;
};
