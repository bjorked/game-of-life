#include "Cell.h"

Cell::Cell(void)
{
    state = false;
}

Cell::Cell(bool state)
{
    this->state = state;
}

bool Cell::Status(void)
{
    return this->state;
}

void Cell::ToggleCell(void)
{
    state = !state;
}

