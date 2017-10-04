#include <utility>
#include "src/logic/headers/universe.h"


Universe::Universe(int height, int width)
    : matrixWidth(width), matrixHeight(height), generationCounter(0),
      universe(width, std::vector<Cell>(height, false)),
      nextUniverse(width, std::vector<Cell>(height, false)),
      universePtr(&universe), nextUniversePtr(&nextUniverse) {}

void Universe::nextGeneration(void)
{
    updateMatrices();
    std::swap(universePtr, nextUniversePtr);
    generationCounter++;
}

void reset(void)
{
    universe.clear();
    nextUniverse.clear();
    generationCounter = 0;
}

int Universe::countLivingNeighbours(int row, int col)
{
    int livingNeighbours = 0;

    for (int x = row - 1; x <= row + 1; ++x) {
        for (int y = col - 1; y <= col + 1; ++y) {
            if (x == row && y == col) {					// Skip the cell itself
                continue;
            } else if (universe[x][y].state()) {
                livingNeighbours++;
            }
        }
    }

    return livingNeighbours;
}

bool Universe::liveOrDie(int row, int col) const
{
    int livingNeighbours = countLivingNeighbours(row, col);
    bool state = universe[x][y].state();

    if (livingNeighbours < 2 && state) {
        return false;
    } else if (livingNeighbours > 3 && state) {
        return false;
    } else if (livingNeighbours == 3 && state == false) {
        return true;
    }

    return state;
}

void updateMatrices(void)
{
    for (int row = 0; row < matrixWidth; ++row) {
        for (int col = 0; col < matrixHeight; ++col) {
            nextUniverse[row][col] = liveOrDie(row, col);
        }
    }
}
