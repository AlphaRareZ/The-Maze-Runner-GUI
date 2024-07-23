#ifndef WALL_H
#define WALL_H

#include <QGraphicsPixmapItem>

class Wall : public QGraphicsPixmapItem {
public:
    Wall(int x, int y, int cellSize);
    ~Wall();
private:

};

#endif // WALL_H
