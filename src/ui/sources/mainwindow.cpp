#include <QtWidgets>
#include "src/ui/headers/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    gameWidget(new GameOfLifeWidget)
{
    ui->setupUi(this);

    ui->gameLayout->addWidget(gameWidget);
    ui->generationLabel->setText("Current generation: 0");
    connect(ui->startButton, &QPushButton::clicked, gameWidget, &GameOfLifeWidget::start);
    connect(ui->resetButton, &QPushButton::clicked, gameWidget, &GameOfLifeWidget::reset);
    connect(ui->pauseButton, &QPushButton::clicked, gameWidget, &GameOfLifeWidget::pause);
    connect(gameWidget, &GameOfLifeWidget::matrixChanged, this, &MainWindow::updateGenerationLabel);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete gameWidget;
}

void MainWindow::updateGenerationLabel(void)
{
    ui->generationLabel->setText("Current generation: " + gameWidget->getGenerationCounter());
}
