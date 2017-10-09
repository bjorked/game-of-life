#ifndef GUARD_UNIVERSE_H
#define GUARD_UNIVERSE_H

#include <vector>
#include "src/logic/headers/cell.h"

/*
    Universe class encapsulates the game of life grid and everything that
    happens inside it.
    Cells are stored inside a 2D vector, there's also another vector that
    that is used to find the next grid state.The pointers to these vectors
    help avoid unnecessary copying.
*/

typedef std::vector<std::vector<Cell>> Matrix;

class Universe
{
public:
    Universe(int width = 60, int height = 60);

    int getWidth(void) const {return universeWidth;}
    int getHeight(void) const {return universeHeight;}
    void setSize(int width, int height) {universeWidth = width; universeHeight = height;}

    int getGeneration(void) const {return generationCounter;}

    bool getCellState(int row, int col) const {return (*universePtr)[row][col].getState();}
    void toggleCell(int row, int col) {(*universePtr)[row][col].toggleCell();}

    void nextGeneration(void);
    void reset(void);

private:
    int countLivingNeighbours(int row, int col) const;
    bool liveOrDie(int row, int col) const;
    void updateNextUniverse(void);

    Matrix universe;
    Matrix nextUniverse;
    Matrix *universePtr;
    Matrix *nextUniversePtr;

    int universeWidth;
    int universeHeight;
    int generationCounter;
};

#endif
