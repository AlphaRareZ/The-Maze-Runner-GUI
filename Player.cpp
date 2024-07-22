#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <iostream>
using namespace std;
class Player:public QGraphicsPixmapItem{
public:
    Player(int x,int y,int cellSize){
        this->x = x;
        this->y = y;
        this->cellSize= cellSize;

        QPixmap image("D:/Projects/QT-Projects/GridGPT/assets/player.png");
        image = image.scaled(cellSize,cellSize,Qt::KeepAspectRatio);
        setPixmap(image);
        setPos(x,y);
        setFlag(ItemIsFocusable);
        setFocus();
    }
    void moveUp(){
        x-=cellSize;
        setPos(y,x);
        cout<<x<<' '<<y<<" After Up\n";
    }

    void moveDown(){
        x+=cellSize;
        setPos(y,x);        cout<<x<<' '<<y<<" After Down\n";

    }

    void moveLeft(){
        y-=cellSize;
        setPos(y,x);        cout<<x<<' '<<y<<" After Left\n";

    }

    void moveRight(){
        y+=cellSize;
        setPos(y,x);        cout<<x<<' '<<y<<" After Right\n";

    }
private:

    int cellSize,x,y;
protected:


    // QGraphicsItem interface
protected:
    void keyPressEvent(QKeyEvent *event){
        if(event->key()== Qt::Key_Up){
            moveUp();
        }
        if(event->key()== Qt::Key_Down){
            moveDown();
        }
        if(event->key()== Qt::Key_Left){
            moveLeft();
        }
        if(event->key()== Qt::Key_Right){
            moveRight();
        }
    }
};
