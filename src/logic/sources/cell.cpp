#include "src/logic/headers/cell.h"

Cell::Cell(bool state) : state(state) {}

void Cell::toggleCell(void)
{
    state = !state;
}
