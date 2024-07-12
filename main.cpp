#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.setMinimumSize(900,600);
    w.setMaximumSize(1677215,1677215);
    //w.setWindowState(Qt::WindowMaximized);




    w.setWindowTitle("QSLEEVE");
    return a.exec();
}
