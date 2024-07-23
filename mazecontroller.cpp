
#include "mazecontroller.h"
#include <vector>
#include <QMediaPlayer>
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

int MazeController::getGridSize()
{
    return maze->getGridSize();
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

    bool can = maze->canMoveUp();
    if(can)sounds.playMoveMusic();
    return can;
}

bool MazeController::canMoveDown()
{
    bool can = maze->canMoveDown();
    if(can)sounds.playMoveMusic();
    return can;
}

bool MazeController::canMoveRight()
{
    bool can = maze->canMoveRight();
    if(can)sounds.playMoveMusic();
    return can;
}

bool MazeController::canMoveLeft()
{
    bool can =  maze->canMoveLeft();
    if(can)sounds.playMoveMusic();
    return can;
}

bool MazeController::isWin()
{

    return maze->isWin();
}

void MazeController::playBGMusic()
{
    sounds.playBGMusic();
}

void MazeController::playVictoryMusic()
{
    sounds.playVictoryMusic();
}

void MazeController::playDefeatMusic()
{
    sounds.playDefeatMusic();
}

void MazeController::playMoveMusic()
{
    sounds.playMoveMusic();
}

void MazeController::stopBGMusic()
{
    sounds.stopBGMusic();
}

void MazeController::stopVictoryMusic()
{
    sounds.stopVictoryMusic();
}

void MazeController::stopDefeatMusic()
{
    sounds.stopDefeatMusic();
}

void MazeController::stopMoveMusic()
{
    sounds.stopMoveMusic();
}
