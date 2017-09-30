#ifndef GUARD_CELL_H
#define GUARD_CELL_H

class Cell {

    public:
        Cell(void);
        Cell(bool);
        bool Status(void);      // return Cell's current status
        void ToggleCell(void);

    private:
        bool state;             // true - alive, false - dead
};

#endif
