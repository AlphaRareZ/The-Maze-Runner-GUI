#ifndef MAZECONTROLLER_H
#define MAZECONTROLLER_H

#include "Maze.h"
#include "Player.h"

using namespace std;
class MazeController
{
public:
    MazeController(int mazeGridSize);
    void setPlayer(Player *player);
    Player* getPlayer();
    Maze* getMaze();
    vector<vector<char>>& getMazeGrid();
    bool canMoveUp();
    bool canMoveDown();
    bool canMoveRight();
    bool canMoveLeft();
private:
    Maze *maze;
    Player *player;
};

#endif // MAZECONTROLLER_H
