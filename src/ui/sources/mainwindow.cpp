#include "src/ui/headers/mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    game(new Universe),
    timer(new QTimer(this))
{
    ui->setupUi(this);
    timer->setInterval(3000);
    timer->start();
    connect(timer, SIGNAL(timeout()), this, SLOT(new_generation()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete game;
    delete timer;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    for (int x = 0; x <= 500; x += 50) {
        for (int y = 0; y <= 500; y += 50) {
            int i = floor(x / 50);
            int j = floor(y / 50);

            QBrush brush_on(Qt::blue);
            QBrush brush_off(Qt::white);

            if (game->getCellState(i, j)) {
                QRect rect(x, y, 50, 50);
                painter.fillRect(rect, brush_on);
            } else {
                QRect rect(x, y, 50, 50);
                painter.fillRect(rect, brush_off);
            }
        }
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    int x = floor(event->x() / 50);
    int y = floor(event->y() / 50);

    game->toggleCell(x, y);
    update();
}

void MainWindow::new_generation(void)
{
    game->nextGeneration();
    update();
}
