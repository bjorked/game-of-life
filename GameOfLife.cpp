#include "GameOfLife.h"


GameOfLife::GameOfLife(void) : width(50), height(50) {}

GameOfLife::GameOfLife(int width, height) : matrix_width(width), matrix_heigh(height) {}

GameOfLife::count_alive_neighbours(int x, int y)
{
    int alive_neighbours = 0;

    for (int i = x-1, i != x+2, i++) {
        for (int j = y-1, j != y+2, j++) {
            if (i == x && j == y) {
                continue;
            } else if (game_matrix[i][j].Status()) {
                alive_neighbours++;
            }
        }
    }

    return alive_neighbours;
}
