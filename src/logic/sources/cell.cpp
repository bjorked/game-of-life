#include "src/logic/headers/cell.h"

Cell::Cell() : state(false) {}

void Cell::ToggleCell(void)
{
    state = !state;
}
