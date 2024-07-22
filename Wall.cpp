
#include <QGraphicsPixmapItem>
class Wall:public QGraphicsPixmapItem{
public:
    Wall(int x,int y,int cellSize){
        QPixmap image("D:/Projects/QT-Projects/GridGPT/assets/wall.jpg");
        image = image.scaled(cellSize,cellSize,Qt::KeepAspectRatio);
        setPixmap(image);
        setPos(x,y);
    }
    ~Wall(){}
private:

};
