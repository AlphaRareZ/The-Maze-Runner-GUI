#include <Maze.h>
#include <Player.h>


class MazeController{
public:
    MazeController(int mazeGridSize){
        maze = new Maze(mazeGridSize);
    }
    void setPlayer(Player *player){
        this->player = player;
    }
    Player* getPlayer(){
        return player;

    }
    Maze* getMaze(){
        return maze;
    }
private:
    Maze *maze;
    Player *player;
};
