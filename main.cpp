#include <iostream>
#include "Cell.h"
#include "GameOfLife.h"

int main(void)
{
    GameOfLife game = GameOfLife();
    game.pass_generation();
    game.pass_generation();
    game.pass_generation();

}
