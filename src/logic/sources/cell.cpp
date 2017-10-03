#include "src/logic/headers/cell.h"

Cell::Cell(int x, int y, bool cell_state) : x(x), y(y), state(cell_state) {}

void Cell::ToggleCell(void)
{
    state = !state;
}
