#ifndef GUARD_GAMEOFLIFEWIDGET_H
#define GUARD_GAMEOFLIFEWIDGET_H

#include <QWidget>
#include "src/logic/headers/universe.h"

class GameOfLifeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GameOfLifeWidget(QWidget *parent = 0);

public slots:
    void newGeneration(void);

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);

private:
    Universe *game;
};

#endif
