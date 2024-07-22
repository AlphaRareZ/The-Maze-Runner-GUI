#include "mainwindow.h"

#include "Maze.cpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.resize(1250,1250);
    w.show();
    // Maze maze(7);
    // maze.print_maze();
    return a.exec();
}
