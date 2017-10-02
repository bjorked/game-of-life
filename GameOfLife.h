#ifndef GUARD_GAME_OF_LIFE_H
#define GUARD_GAME_OF_LIFE_H

#include "Cell.h"
#include <vector>

typedef std::vector<std::vector<Cell>> Matrix;

class GameOfLife
{
    public:
        GameOfLife(void);
        void pass_generation(void);

    private:
        int matrix_width;
        int matrix_height;
        Matrix game_matrix;

        int count_living_neighbours(Cell cell);
};

#endif
