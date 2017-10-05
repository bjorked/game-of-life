#ifndef GUARD_GAMEOFLIFEWIDGET_H
#define GUARD_GAMEOFLIFEWIDGET_H

#include <QWidget>
#include <QTimer>
#include "src/logic/headers/universe.h"

class GameOfLifeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GameOfLifeWidget(QWidget *parent = 0);
    ~GameOfLifeWidget(void);
    void start(void);
    void reset(void);
    void pause(void);

public slots:
    void newGeneration(void);

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);

private:
    Universe *game;
    QTimer *timer;
};

#endif
