#include <QtWidgets>
#include "src/ui/headers/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    gameWidget(new GameOfLifeWidget)
{
    ui->setupUi(this);

    ui->gameSpace->addWidget(gameWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete gameWidget;
}
