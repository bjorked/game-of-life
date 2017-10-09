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

    void setInterval(int msec) {timer->setInterval(msec);}
    int getInterval(void) {return timer->interval();}

    void setSize(int size);

    QString getGenerationCounter(void) {return QString::number(game->getGeneration());}

    void selectColor(void);

public slots:
    void newGeneration(void);

signals:
    // Emmited every time values of the universe change, such as resetting or plain spawning
    void matrixChanged(bool signal);

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);

private:
    Universe *game;
    QTimer *timer;
    QBrush liveColor;					// Color of living cells

    static const int WINDOWSIZE = 600;	// Default window size in pixels reserved for the grid
    int cellSize;						// Cell size in pixes
};

#endif
