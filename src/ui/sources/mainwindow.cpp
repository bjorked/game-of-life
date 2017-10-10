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
    ui->generationLabel->setText("Current generation: 1");
    ui->colorButton->setText("Select color");
    ui->intervalSlider->setRange(0, 1500);
    ui->intervalSlider->setValue(250);
    ui->intervalLabel->setText("250 msec");
    ui->sizeBox->setValue(50);
    ui->sizeBox->setMaximum(60);

    connect(ui->startButton, &QPushButton::clicked, gameWidget, &GameOfLifeWidget::start);
    connect(ui->resetButton, &QPushButton::clicked, gameWidget, &GameOfLifeWidget::reset);
    connect(ui->pauseButton, &QPushButton::clicked, gameWidget, &GameOfLifeWidget::pause);
    connect(ui->colorButton, &QPushButton::clicked, gameWidget, &GameOfLifeWidget::selectColor);
    connect(ui->intervalSlider, &QSlider::valueChanged, gameWidget, &GameOfLifeWidget::setInterval);
    connect(ui->intervalSlider, &QSlider::valueChanged, this, &MainWindow::updateIntervalLabel);
    connect(ui->sizeBox, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), gameWidget, &GameOfLifeWidget::setSize);

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

void MainWindow::updateIntervalLabel(void)
{
    ui->intervalLabel->setText(QString::number(gameWidget->getInterval()) + " msec");
}
