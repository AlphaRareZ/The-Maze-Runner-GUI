#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>

class MazeController; // Forward declaration

class Player : public QGraphicsPixmapItem {
public:
    Player(int x, int y, int cellSize, MazeController* controller);

    // Movement functions
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    int cellSize, x, y;
    MazeController *controller;
};

#endif // PLAYER_H
