#include <QTimer>
#include <QPainter>
#include <QMouseEvent>
#include <QColorDialog>
#include <qmath.h>
#include "src/ui/headers/gameoflifewidget.h"

GameOfLifeWidget::GameOfLifeWidget(QWidget *parent)
    : QWidget(parent), game(new Universe), timer(new QTimer(this)),
      liveColor(Qt::green), cellSize(12)	// Default grid size is 50x50, so default pixel size is 600/50
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
    game->setSize(size);
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
    int universeSize = game->getSize();

    // Pain the grid
    for (int row = 0; row < universeSize; ++row) {
        painter.drawLine(row * cellSize, 0, row * cellSize, universeSize * cellSize);
        painter.drawLine(0, row * cellSize, universeSize * cellSize, row * cellSize);
    }

    for (int row = 0; row < universeSize; ++row) {
        for (int col = 0; col < universeSize; ++col) {
            QBrush brush_dead(Qt::white);

            if (game->getCellState(row, col)) {
                QRect rect(row * cellSize, col * cellSize, cellSize-1, cellSize-1);
                painter.fillRect(rect, liveColor);
            } else {
                QRect rect(row * cellSize, col * cellSize, cellSize-1, cellSize-1);
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
