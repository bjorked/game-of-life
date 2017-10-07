#ifndef GUARD_UNIVERSE_H
#define GUARD_UNIVERSE_H

#include <vector>
#include "src/logic/headers/cell.h"

typedef std::vector<std::vector<Cell>> Matrix;

class Universe
{
    public:
        Universe(int width = 50, int height = 50);

        int getWidth(void) const {return matrixWidth;}
        int getHeight(void) const {return matrixHeight;}
        int getGeneration(void) const {return generationCounter;}

        bool getCellState(int row, int col) const {return (*universePtr)[row][col].getState();}
        void toggleCell(int row, int col) {(*universePtr)[row][col].toggleCell();}

        void setSize(int width, int height) {matrixWidth = width; matrixHeight = height;}

        void nextGeneration(void);
        void reset(void);

    private:
        Matrix universe;
        Matrix nextUniverse;
        Matrix* universePtr;
        Matrix* nextUniversePtr;
        int matrixWidth;
        int matrixHeight;
        int generationCounter;

        int countLivingNeighbours(int row, int col) const;
        bool liveOrDie(int row, int col) const;
        void updateMatrices(void);
};

#endif
