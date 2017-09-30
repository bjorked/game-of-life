#include <iostream>
#include "Cell.h"

int main(void)
{
    Cell test = Cell(true);

    std::cout << test.Status() << std::endl;

}
