#include <QTimer>
#include <QPainter>
#include <QMouseEvent>
#include <qmath.h>
#include "src/ui/headers/gameoflifewidget.h"

GameOfLifeWidget::GameOfLifeWidget(QWidget *parent)
    : QWidget(parent), game(new Universe), timer(new QTimer(this))
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
    update();
}

void GameOfLifeWidget::pause(void)
{
    timer->stop();
}

void GameOfLifeWidget::newGeneration(void)
{
    game->nextGeneration();
    update();
}

void GameOfLifeWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    for (int x = 0; x <= 450; x += 50) {
        for (int y = 0; y <= 450; y += 50) {
            int i = qFloor(x / 50);
            int j = qFloor(y / 50);

            QBrush brush_alive(Qt::green);
            QBrush brush_dead(Qt::white);

            if (game->getCellState(i, j)) {
                QRect rect(x, y, 50, 50);
                painter.fillRect(rect, brush_alive);
            } else {
                QRect rect(x, y, 50, 50);
                painter.fillRect(rect, brush_dead);
            }
        }
    }
}

void GameOfLifeWidget::mousePressEvent(QMouseEvent *event)
{
    int x = floor(event->x() / 50);
    int y = floor(event->y() / 50);

    game->toggleCell(x, y);
    update();
}
