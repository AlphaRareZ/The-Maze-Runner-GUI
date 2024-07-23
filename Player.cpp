#include "Player.h"
#include <QPixmap>
#include <iostream>
#include "MazeController.h" // Include your MazeController header file

using namespace std;

Player::Player(int x, int y, int cellSize, MazeController* controller)
    : cellSize(cellSize), x(x), y(y), controller(controller) {
    QPixmap image("D:/Projects/QT-Projects/GridGPT/assets/player.png");
    image = image.scaled(cellSize, cellSize, Qt::KeepAspectRatio);
    setPixmap(image);
    setPos(x, y);
    setFlag(ItemIsFocusable);
    setFocus();
}

void Player::moveUp() {
    x -= cellSize;
    setPos(y, x);
    cout << x << ' ' << y << " After Up\n";
}

void Player::moveDown() {
    x += cellSize;
    setPos(y, x);
    cout << x << ' ' << y << " After Down\n";
}

void Player::moveLeft() {
    y -= cellSize;
    setPos(y, x);
    cout << x << ' ' << y << " After Left\n";
}

void Player::moveRight() {
    y += cellSize;
    setPos(y, x);
    cout << x << ' ' << y << " After Right\n";
}

void Player::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Up) {
        if(controller->canMoveUp()){
            moveUp();
        }
    } else if (event->key() == Qt::Key_Down) {
        if(controller->canMoveDown()){
            moveDown();
        }

    } else if (event->key() == Qt::Key_Left) {
        if(controller->canMoveLeft()){
            moveLeft();
        }
    } else if (event->key() == Qt::Key_Right) {
        if(controller->canMoveRight()){
            moveRight();
        }
    }
}
