#include "Maze.h"
#include <iostream>
#include <stack>
#include <cstdlib>
#include <ctime>

using namespace std;

Maze::Maze(int N) {
    this->N = N;
    mazeGrid.resize(100);
    for (auto &i : mazeGrid) {
        i.resize(100);
    }
    this->gridSize = 2 * N + 1;
    initialize_maze();
    generate_maze();
    format_maze();
}

std::vector<std::vector<char>>& Maze::getMaze() {
    return mazeGrid;
}

int Maze::getGridSize() {
    return gridSize;
}

void Maze::print_maze() {
    for (int i = 0; i < 2 * N + 1; i++) {
        for (int j = 0; j < 2 * N + 1; j++)
            cout << mazeGrid[i][j];
        cout << '\n';
    }
}

bool Maze::canMoveUp() {
    if (validMovement(playerRow - 1, playerCol)) {
        playerRow--;
        return true;
    }
    return false;
}

bool Maze::canMoveDown() {
    if (validMovement(playerRow + 1, playerCol)) {
        playerRow++;
        return true;
    }
    return false;
}

bool Maze::canMoveRight() {
    if (validMovement(playerRow, playerCol + 1)) {
        playerCol++;
        return true;
    }
    return false;
}

bool Maze::canMoveLeft() {
    if (validMovement(playerRow, playerCol - 1)) {
        playerCol--;
        return true;
    }
    return false;
}

bool Maze::isWin()
{
    return playerRow == gridSize-2 and playerCol==gridSize-2;
}

void Maze::initialize_maze() {
    for (int i = 0; i < 2 * N + 1; i++) {
        for (int j = 0; j < 2 * N + 1; j++) {
            if (i % 2 == 0) {
                mazeGrid[i][j] = j % 2 ? '-' : ' ';
            } else {
                mazeGrid[i][j] = j % 2 ? ' ' : '!';
            }
        }
    }
    mazeGrid[1][1] = ' ';
}

void Maze::generate_maze() {
    stack<pair<int, int>> st;
    srand(time(0));

    int node = rand() % (N * N) + 1;
    pair<int, int> rc = get_row_column(node);
    rc.first--, rc.second--;

    visited[rc.first][rc.second] = true;
    st.push(rc);

    while (!st.empty()) {
        pair<int, int> curr = st.top();
        vector<int> neighbors;

        for (int i = 0; i < 4; i++) {
            int new_r = curr.first, new_c = curr.second;
            new_r += dxCell[i];
            new_c += dyCell[i];

            if (validDecision(new_r, new_c) and !visited[new_r][new_c]) {
                neighbors.push_back(i);
            }
        }

        if (neighbors.size() == 0) {
            st.pop();
            continue;
        }

        int idx = rand() % neighbors.size();
        int dir = neighbors[idx];

        int cell_r = curr.first, cell_c = curr.second;
        int wall_r = curr.first, wall_c = curr.second;

        cell_r += dxCell[dir], cell_c += dyCell[dir];
        wall_r += dx_wall[dir], wall_c += dy_wall[dir];

        visited[cell_r][cell_c] = true;
        mazeGrid[wall_r][wall_c] = ' ';

        pair<int, int> node = {cell_r, cell_c};
        st.push(node);
    }
}

void Maze::format_maze() {
    for (int i = 0; i < getGridSize(); ++i) {
        for (int j = 0; j < getGridSize(); ++j) {
            if (mazeGrid[i][j] == 'S') continue;

            bool condition = j % 2 == 0 && i % 2 == 0 && mazeGrid[i][j] == ' ';
            if (condition || i % (getGridSize() - 1) == 0 || j % (getGridSize() - 1) == 0 || mazeGrid[i][j] != ' ') {
                mazeGrid[i][j] = '.';
            }
        }
    }
}

bool Maze::validMovement(int x, int y) {
    return x >= 0 and y >= 0 and x < gridSize and y < gridSize and mazeGrid[x][y] == ' ';
}

pair<int, int> Maze::get_row_column(int &node) {
    int r = (node + N - 1) / N;
    int c = node - (r - 1) * N;

    return {r + r, c + c};
}

bool Maze::validDecision(int r, int c) {
    return (r > -1) and (r < 2 * N + 1) and (c > -1) and (c < 2 * N + 1);
}
