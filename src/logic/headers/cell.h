#ifndef GUARD_CELL_H
#define GUARD_CELL_H

class Cell
{
    public:
        Cell(bool state = false);
        bool getState(void) const {return state;}
        void setState(bool newState) {state = newState;}
        void toggleCell(void);

    private:
        bool state;             // true - alive, false - dead
};

#endif
