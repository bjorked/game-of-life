#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include "cell.h"
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

#endif // GAMEOFLIFE_H
