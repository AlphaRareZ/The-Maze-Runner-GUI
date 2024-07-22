#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QPixmap>
#include <QVBoxLayout>
#include <QDebug> // For debug output
#include "Maze.cpp"
#include "Wall.cpp"
#include "Player.cpp"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Ensure graphicsView and its scene are initialized
    QGraphicsView *graphicsView = new QGraphicsView();

    if (graphicsView == nullptr) {
        qCritical() << "Error: graphicsView is null.";
        return;
    }

    // Create a layout and add the graphicsView to it
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(graphicsView);
    ui->centralwidget->setLayout(layout);

    scene = new QGraphicsScene(this);
    graphicsView->setScene(scene);

    createGrid(50);

    // Update scene rect based on the items added
    QRectF boundingRect = scene->itemsBoundingRect();
    scene->setSceneRect(boundingRect);

    // Fit the view exactly to the content of the scene without extra space
    graphicsView->fitInView(scene->sceneRect(), Qt::KeepAspectRatioByExpanding);

    // Center the view on the top-left corner of the scene
    graphicsView->centerOn(0, 0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createGrid(const int &cellSize)
{

    Maze maze(20); // Ensure Maze class is correctly implemented

    for (int i = 0; i < maze.getGridSize(); ++i)
    {
        for (int j = 0; j < maze.getGridSize(); ++j)
        {
            int x = j * cellSize;
            int y = i * cellSize;
            if(maze.getMaze()[i][j]=='S'){
                Player *player = new Player(x,y,cellSize);
                scene->addItem(player);
            }
            bool condition = maze.getMaze()[i][j]=='.';
            if (condition)
            {
                Wall *wall = new Wall(x,y,cellSize);
                scene->addItem(wall);
            }
        }
    }
    maze.print_maze();
}
