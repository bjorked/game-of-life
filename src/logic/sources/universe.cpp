#include <utility>
#include "src/logic/headers/universe.h"

Universe::Universe(int size)
    : universe(size, std::vector<Cell>(size, false)),
      nextUniverse(size, std::vector<Cell>(size, false)),
      universePtr(&universe), nextUniversePtr(&nextUniverse),
      universeSize(size), generationCounter(1) {}

void Universe::setSize(int size)
{
    universeSize = size;
    universe.clear();
    nextUniverse.clear();
    universe.resize(size, std::vector<Cell>(size, false));
    nextUniverse.resize(size, std::vector<Cell>(size, false));
    universePtr = &universe;
    nextUniversePtr = &nextUniverse;
}

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
    for (int row = 0; row < universeSize; row++) {
        for (int col = 0; col < universeSize; col++) {
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
    if (row == 0 || col == 0 || row == universeSize-1 || col == universeSize-1)
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
    for (int row = 0; row < universeSize; ++row) {
        for (int col = 0; col < universeSize; ++col) {
            (*nextUniversePtr)[row][col] = liveOrDie(row, col);
        }
    }
}

void Universe::resizeMatrixRows(Matrix matrix, int size)
{
    for (auto& row : matrix)
        row.resize(size, false);
}
