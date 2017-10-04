#ifndef GUARD_UNIVERSE_H
#define GUARD_UNIVERSE_H

#include <vector>
#include "src/logic/headers/cell.h"

typedef std::vector<std::vector<Cell>> Matrix;

class Universe
{
    public:
        Universe(int width = 25, int height = 25);

        int getWidth(void) const {return matrixWidth;}
        int getHeight(void) const {return matrixHeight;}
        int getGeneration(void) const {return generationCounter;}

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
