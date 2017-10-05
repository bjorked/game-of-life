#ifndef GUARD_MAINWINDOW_H
#define GUARD_MAINWINDOW_H

#include <QMainWindow>
#include "src/ui/headers/gameoflifewidget.h"

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
    void updateGenerationLabel(void);

    Ui::MainWindow *ui;
    GameOfLifeWidget *gameWidget;
};

#endif
