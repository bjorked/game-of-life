#ifndef CELL_H
#define CELL_H

class Cell
{
    public:
        Cell(int x, int y, bool cell_status);

        bool Status(void) {return state;}
        int getX(void) {return x;}
        int getY(void) {return y;}

        void ToggleCell(void);

    private:
        int x;                  // coordinates
        int y;
        bool state;             // true - alive, false - dead
};

#endif // CELL_H
