#ifndef MAZECONTROLLER_H
#define MAZECONTROLLER_H

#include "Maze.h"
#include "Player.h"

#include <GameSounds.h>

using namespace std;
class MazeController
{
public:
    MazeController(int mazeGridSize);
    void setPlayer(Player *player);
    Player* getPlayer();
    int getGridSize();
    Maze* getMaze();
    vector<vector<char>>& getMazeGrid();
    bool canMoveUp();
    bool canMoveDown();
    bool canMoveRight();
    bool canMoveLeft();
    bool isWin();

    void playBGMusic();
    void playVictoryMusic();
    void playDefeatMusic();
    void playMoveMusic();

    void stopBGMusic();
    void stopVictoryMusic();
    void stopDefeatMusic();
    void stopMoveMusic();
private:
    Maze *maze;
    Player *player;
    GameSounds sounds;
};

#endif // MAZECONTROLLER_H
