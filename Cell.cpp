#include "Cell.h"

Cell::Cell(void) : state(false) {}

Cell::Cell(bool cell_state) : state(cell_state) {}

bool Cell::Status(void)
{
    return state;
}

void Cell::ToggleCell(void)
{
    state = !state;
}

