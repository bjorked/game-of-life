#ifndef GUARD_MAINWINDOW_H
#define GUARD_MAINWINDOW_H

#include <QMainWindow>
#include "src/logic/headers/universe.h"
#include <QtWidgets>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Universe *game;
    QTimer *timer;

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);

public slots:
    void new_generation(void);
};

#endif
