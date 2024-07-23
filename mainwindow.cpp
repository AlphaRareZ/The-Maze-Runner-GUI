#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QPixmap>
#include <QVBoxLayout>
#include <QDebug> // For debug output
#include <QMediaPlayer>
#include <QAudioOutput>
#include <GameSounds.h>
#include "Wall.h"
#include "MazeController.h"

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


    // CONTROLLER THAT MANAGES THE SIZE OF MAZE
    this->controller = new MazeController(7);
    controller->playBGMusic();


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


    for (int i = 0; i < controller->getGridSize(); ++i)
    {
        for (int j = 0; j < controller->getGridSize(); ++j)
        {
            int x = j * cellSize;
            int y = i * cellSize;
            if(i==1 and j==1){
                Player *player = new Player(x,y,cellSize,controller);
                scene->addItem(player);
            }
            bool condition = controller->getMazeGrid()[i][j]=='.';
            if (condition)
            {
                Wall *wall = new Wall(x,y,cellSize);
                scene->addItem(wall);
            }
        }
    }
    controller->getMaze()->print_maze();
}
