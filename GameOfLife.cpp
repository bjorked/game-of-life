#include "GameOfLife.h"


GameOfLife::GameOfLife(void) : matrix_width(50), matrix_height(50), game_matrix(50, std::vector<Cell>(50, false)) {}

GameOfLife::GameOfLife(int width, int height) : matrix_width(width), matrix_height(height) {}

void GameOfLife::pass_generation(void)
{
    int alive_neighbours = 0;

    for (int row = 0; row != matrix_width; row++) {
        for (int col = 0; col != matrix_height; col++) {
            if (row == 0 || col == 0 || row == matrix_width-1 || col == matrix_height-1) {
                continue;
            }

            alive_neighbours = count_alive_neighbours(row, col);

            if (alive_neighbours < 2 && game_matrix[row][col].Status()) {
                game_matrix[row][col].ToggleCell();
            } else if (alive_neighbours > 3 && game_matrix[row][col].Status()) {
                game_matrix[row][col].ToggleCell();
            } else if (alive_neighbours == 3 && !(game_matrix[row][col].Status())) {
                game_matrix[row][col].ToggleCell();
            }
        }
    }
}

int GameOfLife::count_alive_neighbours(int x, int y)
{
    int alive_neighbours = 0;

    for (int i = x-1; i != x+2; i++) {
        for (int j = y-1; j != y+2; j++) {
            if (i == x && j == y) {
                continue;
            } else if (game_matrix[i][j].Status()) {
                alive_neighbours++;
            }
        }
    }

    return alive_neighbours;
}
