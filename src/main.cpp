#include "src/ui/headers/mainwindow.h"
#include <QApplication>
#include "src/logic/headers/gameoflife.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
