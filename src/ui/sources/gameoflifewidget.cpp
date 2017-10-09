#include <QTimer>
#include <QPainter>
#include <QMouseEvent>
#include <QColorDialog>
#include <qmath.h>
#include "src/ui/headers/gameoflifewidget.h"

GameOfLifeWidget::GameOfLifeWidget(QWidget *parent)
    : QWidget(parent), game(new Universe), timer(new QTimer(this)),
      liveColor(Qt::green), cellSize(10)	// Default grid size is 60x60, so default pixel size is 600/60
{
    timer->setInterval(250);
    connect(timer, &QTimer::timeout, this, &GameOfLifeWidget::newGeneration);
}

GameOfLifeWidget::~GameOfLifeWidget(void)
{
    delete game;
    delete timer;
}

void GameOfLifeWidget::start(void)
{
    timer->start();
}

void GameOfLifeWidget::reset(void)
{
    timer->stop();
    game->reset();
    emit matrixChanged(true);
    update();
}

void GameOfLifeWidget::selectColor(void)
{
    liveColor = QColorDialog::getColor();
}

void GameOfLifeWidget::pause(void)
{
    timer->stop();
}

void GameOfLifeWidget::setSize(int size)
{
    game->reset();
    game->setSize(size, size);
    cellSize = WINDOWSIZE / size;
    update();
}

void GameOfLifeWidget::newGeneration(void)
{
    game->nextGeneration();
    emit matrixChanged(true);
    update();
}

void GameOfLifeWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    // Pain the grid
    for (int row = 0; row <= WINDOWSIZE; row += cellSize) {
        painter.drawLine(row, 0, row, WINDOWSIZE);
        painter.drawLine(0, row, WINDOWSIZE, row);
    }

    for (int x = 0; x < WINDOWSIZE; x += cellSize) {
        for (int y = 0; y < WINDOWSIZE; y += cellSize) {
            int row = x / cellSize;
            int col = y / cellSize;

            QBrush brush_dead(Qt::white);

            if (game->getCellState(row, col)) {
                QRect rect(x, y, cellSize-1, cellSize-1);
                painter.fillRect(rect, liveColor);
            } else {
                QRect rect(x, y, cellSize-1, cellSize-1);
                painter.fillRect(rect, brush_dead);
            }
        }
    }
}

// Toggles the pressed cell by finding the QMouseEven coordinates
void GameOfLifeWidget::mousePressEvent(QMouseEvent *event)
{
    int row = floor(event->x() / cellSize);
    int col = floor(event->y() / cellSize);

    game->toggleCell(row, col);
    emit matrixChanged(true);
    update();
}
