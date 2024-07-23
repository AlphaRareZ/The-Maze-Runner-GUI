
#include "mazecontroller.h"
#include <vector>
using namespace std;
MazeController::MazeController(int mazeGridSize)
{
    maze = new Maze(mazeGridSize);
}

void MazeController::setPlayer(Player *player)
{
    this->player = player;
}

Player *MazeController::getPlayer()
{
    return player;
}

Maze *MazeController::getMaze()
{
    return maze;
}

vector<vector<char>>&MazeController::getMazeGrid()
{
    return maze->getMaze();
}

bool MazeController::canMoveUp()
{
    return maze->canMoveUp();
}

bool MazeController::canMoveDown()
{
    return maze->canMoveDown();
}

bool MazeController::canMoveRight()
{
    return maze->canMoveRight();
}

bool MazeController::canMoveLeft()
{
    return maze->canMoveLeft();
}
