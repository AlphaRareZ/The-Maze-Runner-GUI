#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QPixmap>
#include <bits/stdc++.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void createGrid(QPixmap &texture,const int &cellSize);

private:
    Ui::MainWindow *ui;

    QGraphicsScene *scene;
    QGraphicsView *graphicsView;
};

#endif // MAINWINDOW_H
