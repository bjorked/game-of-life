#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include "src/logic/headers/cell.h"
#include <vector>

typedef std::vector<std::vector<Cell>> Matrix;

class GameOfLife
{
    public:
        GameOfLife(void);
        void pass_generation(void);
        Matrix game_matrix;

    private:
        int matrix_width;
        int matrix_height;

        int count_living_neighbours(Cell cell);
};

#endif // GAMEOFLIFE_H
