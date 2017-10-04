#ifndef GUARD_CELL_H
#define GUARD_CELL_H

class Cell
{
    public:
        Cell(bool state = false);
        bool state(void) const {return state;}
        void toggleCell(void);

    private:
        bool state;             // true - alive, false - dead
};

#endif
