#include <QApplication>
#include "src/ui/headers/mainwindow.h"
#include "src/logic/headers/universe.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
