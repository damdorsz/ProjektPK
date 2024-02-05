#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow m;
    m.show();
    m.setWindowTitle("Table Manager Login Portal");
    return a.exec();
}
