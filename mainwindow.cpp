#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QPixmap>
#include <QVBoxLayout>
#include <QDebug> // For debug output
#include "Maze.cpp"

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

    QPixmap texture("D:/Projects/QT-Projects/GridGPT/assets/wall.jpg"); // Use forward slashes for paths
    if (texture.isNull()) {
        qCritical() << "Error: Could not load texture image.";
        return;
    }

    createGrid(texture, 75);

    // Update scene rect based on the items added
    QRectF boundingRect = scene->itemsBoundingRect();
    scene->setSceneRect(boundingRect);

    // Fit the view exactly to the content of the scene without extra space
    graphicsView->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);

    // Center the view on the top-left corner of the scene
    graphicsView->centerOn(0, 0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createGrid(QPixmap &texture, const int &cellSize)
{
    QPixmap scaledTexture = texture.scaled(cellSize, cellSize, Qt::KeepAspectRatio);

    Maze maze(20); // Ensure Maze class is correctly implemented
    maze.print_maze();
    auto grid = maze.getMaze();
    for (int i = 0; i < maze.getGridSize(); ++i)
    {
        for (int j = 0; j < maze.getGridSize(); ++j)
        {
            int x = j * cellSize;
            int y = i * cellSize;
            if(grid[i][j]=='S') continue;
            bool condition = j % 2 == 0 && i % 2 == 0 && grid[i][j] == ' ';
            if (condition || i % (maze.getGridSize() - 1) == 0 || j % (maze.getGridSize() - 1) == 0 || grid[i][j] != ' ')
            {
                QGraphicsPixmapItem *pixmapItem = scene->addPixmap(scaledTexture);
                pixmapItem->setPos(x, y);
            }
        }
    }
}
