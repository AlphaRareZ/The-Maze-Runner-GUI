#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include <utility>

class Maze {
public:
    Maze(int N);

    // Get the maze grid
    std::vector<std::vector<char>>& getMaze();

    // Get the grid size
    int getGridSize();

    // Print the maze
    void print_maze();

    // Check if player can move in the specified directions
    bool canMoveUp();
    bool canMoveDown();
    bool canMoveRight();
    bool canMoveLeft();

private:
    // Initialize the maze with spaces
    void initialize_maze();

    // Generate the maze using depth-first search
    void generate_maze();

    // Format the maze for output
    void format_maze();

    // Validate if a cell is within maze boundaries
    bool validDecision(int r, int c);

    // Check if movement to a cell is valid
    bool validMovement(int x, int y);

    // Convert node to row and column
    std::pair<int, int> get_row_column(int &node);

    // Maze dimensions and player position
    int dxCell[4] = {-2, +0, +0, +2};
    int dyCell[4] = {+0, +2, -2, +0};
    int dx_wall[4] = {-1, +0, +0, +1};
    int dy_wall[4] = {+0, +1, -1, +0};
    int gridSize, N{0}, secondsLimit{0}, playerRow{1}, playerCol{1};
    std::vector<std::vector<char>> mazeGrid;
    bool visited[41][41]{0};
};

#endif // MAZE_H
