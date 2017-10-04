#ifndef GUARD_CELL_H
#define GUARD_CELL_H

class Cell
{
    public:
        Cell();
        bool Status(void) const {return state;}
        void ToggleCell(void);

    private:
        bool state;             // true - alive, false - dead
};

#endif
