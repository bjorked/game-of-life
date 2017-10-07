#include <QTimer>
#include <QPainter>
#include <QMouseEvent>
#include <QColorDialog>
#include <qmath.h>
#include "src/ui/headers/gameoflifewidget.h"

GameOfLifeWidget::GameOfLifeWidget(QWidget *parent)
    : QWidget(parent), game(new Universe), timer(new QTimer(this)),
      liveColor(Qt::green), cellSize(12)
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
    game->setSize(size, size);
    cellSize = 600 / size;
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

    for (int row = 0; row <= 600; row += cellSize) {
        painter.drawLine(row, 0, row, 600);
        painter.drawLine(0, row, 600, row);
    }

    for (int x = 0; x < 600; x += cellSize) {
        for (int y = 0; y < 600; y += cellSize) {
            int i = x / cellSize;
            int j = y / cellSize;

            QBrush brush_dead(Qt::white);

            if (game->getCellState(i, j)) {
                QRect rect(x, y, cellSize-1, cellSize-1);
                painter.fillRect(rect, liveColor);
            } else {
                QRect rect(x, y, cellSize-1, cellSize-1);
                painter.fillRect(rect, brush_dead);
            }
        }
    }
}

void GameOfLifeWidget::mousePressEvent(QMouseEvent *event)
{
    int row = floor(event->x() / cellSize);
    int col = floor(event->y() / cellSize);

    game->toggleCell(row, col);
    emit matrixChanged(true);
    update();
}
