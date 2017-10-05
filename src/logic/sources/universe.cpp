#include <utility>
#include "src/logic/headers/universe.h"
#include <iostream>


Universe::Universe(int width, int height)
    : universe(width, std::vector<Cell>(height, false)),
      nextUniverse(width, std::vector<Cell>(height, false)),
      universePtr(&universe), nextUniversePtr(&nextUniverse),
      matrixWidth(width), matrixHeight(height), generationCounter(0) {}

void Universe::nextGeneration(void)
{
    updateMatrices();
    std::swap(universePtr, nextUniversePtr);
    generationCounter++;
}

void Universe::reset(void)
{
    for (int row = 0; row < matrixWidth; row++) {
        for (int col = 0; col < matrixHeight; col++) {
            universe[row][col].setState(false);
            nextUniverse[row][col].setState(false);
        }
    }

    generationCounter = 0;
}

int Universe::countLivingNeighbours(int row, int col) const
{
    int livingNeighbours = 0;

    for (int x = row - 1; x <= row + 1; ++x) {
        for (int y = col - 1; y <= col + 1; ++y) {
            if (x == row && y == col) {					// Skip the cell itself
                continue;
            } else if ((*universePtr)[x][y].getState()) {
                livingNeighbours++;
            }
        }
    }

    return livingNeighbours;
}

bool Universe::liveOrDie(int row, int col) const
{
    if (row == 0 || col == 0 || row == matrixWidth-1 || col == matrixHeight-1)
        return false;

    int livingNeighbours = countLivingNeighbours(row, col);
    bool state = (*universePtr)[row][col].getState();

    if (livingNeighbours < 2 && state) {
        return false;
    } else if (livingNeighbours > 3 && state) {
        return false;
    } else if ((livingNeighbours == 3) && (state == false)) {
        return true;
    }

    return state;
}

void Universe::updateMatrices(void)
{
    for (int row = 0; row < matrixWidth; ++row) {
        for (int col = 0; col < matrixHeight; ++col) {
            (*nextUniversePtr)[row][col] = liveOrDie(row, col);
        }
    }
}
