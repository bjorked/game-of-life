#include "gameoflife.h"


GameOfLife::GameOfLife(void) : matrix_width(50), matrix_height(50) {
    for (int i = 0; i < 50; i++) {
        game_matrix.push_back(std::vector<Cell>());
        for (int j = 0; j < 50; j++) {
            game_matrix[i].push_back(Cell(i, j, false));
        }
    }
}

void GameOfLife::pass_generation(void)
{
    int living_neighbours = 0;
    bool status = false;

    for (auto& row : game_matrix) {
        for (auto& cell : row) {
            if (cell.getX() == 0 || cell.getY() == 0 ||cell.getX() == matrix_width-1 || cell.getY() == matrix_height-1) {
                continue;
            } else {
                living_neighbours = count_living_neighbours(cell);
                status = cell.Status();

                if (living_neighbours < 2 && status) {
                    cell.ToggleCell();
                } else if (living_neighbours > 3 && status) {
                    cell.ToggleCell();
                } else if (living_neighbours == 3 && !status) {
                    cell.ToggleCell();
                }
            }
        }
    }
}

int GameOfLife::count_living_neighbours(Cell cell)
{
    int living_neighbours = 0;
    int x = cell.getX();
    int y = cell.getY();

    for (int row = x-1; row <= x+1; row++) {
        for (int col = y-1; col <= y+1; col++) {
            if (row == x && col == y) {
                continue;
            } else if (game_matrix[row][col].Status()) {
                living_neighbours++;
            }
        }
    }

    return living_neighbours;
}
