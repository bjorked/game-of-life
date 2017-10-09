#include <utility>
#include "src/logic/headers/universe.h"

Universe::Universe(int width, int height)
    : universe(width, std::vector<Cell>(height, false)),
      nextUniverse(width, std::vector<Cell>(height, false)),
      universePtr(&universe), nextUniversePtr(&nextUniverse),
      universeWidth(width), universeHeight(height), generationCounter(1) {}


// After updating the nextUniverse we swap its and universe's pointers
// This allows us to avoid copying nextUniverse's contents into universe
// in later generations
void Universe::nextGeneration(void)
{
    updateNextUniverse();
    std::swap(universePtr, nextUniversePtr);
    generationCounter++;
}

void Universe::reset(void)
{
    for (int row = 0; row < universeWidth; row++) {
        for (int col = 0; col < universeHeight; col++) {
            universe[row][col].setState(false);
            nextUniverse[row][col].setState(false);
        }
    }

    generationCounter = 1;
}

// Check the status of 8 surrounding cells
// X X X
// X O X
// X X X
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

// Decide whether cell lives or dies based on the amount of living neighbours
// Any live cell with fewer than two live neighbours dies, as if caused by underpopulation.
// Any live cell with two or three live neighbours lives on to the next generation.
// Any live cell with more than three live neighbours dies, as if by overpopulation.
// Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
bool Universe::liveOrDie(int row, int col) const
{
    // Border cells are ignored
    if (row == 0 || col == 0 || row == universeWidth-1 || col == universeHeight-1)
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

void Universe::updateNextUniverse(void)
{
    for (int row = 0; row < universeWidth; ++row) {
        for (int col = 0; col < universeHeight; ++col) {
            (*nextUniversePtr)[row][col] = liveOrDie(row, col);
        }
    }
}
