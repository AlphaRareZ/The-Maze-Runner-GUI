#include <bits/stdc++.h>
using namespace std;

class Maze{
private:
    // up down left right
    //this for walls directions
    int dxCell[4] = {-2, +0, +0, +2};
    int dyCell[4] = {+0, +2, -2, +0};

    //this for valid cells
    int dx_wall[4] = {-1, +0, +0, +1};
    int dy_wall[4] = {+0, +1, -1, +0};

    int gridSize,N{0},secondsLimit{0},//the initial position row and column
    playerRow{1}, playerCol{1};;

    //the 2d character array represents the maze.
    vector<vector<char>> mazeGrid; // Initialize with spaces
    bool visited[41][41]{0};


    //check if the given row and column valid or not
    bool validDecision(int r, int c) {
        return (r > -1) and (r < 2 * N + 1) and (c > -1) and (c < 2 * N + 1);
    }
    /*
- Used only 1 time.
- You can replace it in the generate maze function.
*/

    //takes a random node and returns its row and column.
    pair<int, int> get_row_column(int &node) {
        int r = (node + N - 1) / N;
        int c = node - (r - 1) * N;

        return {r + r, c + c};
    }


    //initialize the maze with spaces.
    void initialize_maze() {
        for (int i = 0; i < 2 * N + 1; i++) {
            for (int j = 0; j < 2 * N + 1; j++) {
                if (i % 2 == 0) {
                    mazeGrid[i][j] = j % 2 ? '-' : ' ';
                } else {
                    mazeGrid[i][j] = j % 2 ? ' ' : '!';
                }
            }
        }

        //The initial position of the player, mark it as 'S'
        mazeGrid[1][1] = 'S';
    }


    //display the maze



    /*
- Here I used a randomized depth first search algorithm.
- I used the iterative way to optimize the memory usage.
*/
    void generate_maze() {
        stack<pair<int, int>> st;

        srand(time(0));

        //the initial node to start the algorithm with.
        int node = rand() % (N * N) + 1;
        pair<int, int> rc = get_row_column(node);
        rc.first--, rc.second--;    //Just to be zero base.

        visited[rc.first][rc.second] = true;
        st.push(rc);

        while (!st.empty()) {
            pair<int, int> curr = st.top();

            //to store the indexes of the unvisited neighbors of the current node.
            vector<int> neighbors;

            for (int i = 0; i < 4; i++) {
                int new_r = curr.first, new_c = curr.second;
                new_r += dxCell[i];
                new_c += dyCell[i];

                if (validDecision(new_r, new_c) and !visited[new_r][new_c]) {
                    neighbors.push_back(i);
                }
            }

            //if the node has no unvisited valid neighbors, then pop the current node from the stack,
            //otherwise let it and push a randomly selected neighbor.
            if ((int) neighbors.size() == 0) {
                st.pop();
                continue;
            }


            //chose a random neighbor
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

    

    void format_maze(){
        for (int i = 0; i < getGridSize(); ++i)
        {
            for (int j = 0; j < getGridSize(); ++j)
            {
                if(mazeGrid[i][j]=='S') continue;

                bool condition = j % 2 == 0 && i % 2 == 0 && mazeGrid[i][j] == ' ';
                if (condition || i % (getGridSize() - 1) == 0 || j % (getGridSize() - 1) == 0 || mazeGrid[i][j] != ' ')
                {
                    getMaze()[i][j] = '.';
                }
            }
        }
    }
public:
    Maze(int N){
        this->N = N;
        mazeGrid.resize(41);
        for(auto&i:mazeGrid){
            i.resize(41);
        }
        this->gridSize = 2*N+1;
        initialize_maze();
        generate_maze();
        format_maze();
    }
    vector<vector<char>>& getMaze(){
        return mazeGrid;
    }
    int getGridSize(){
        return gridSize;
    }
    void print_maze() {
        for (int i = 0; i < 2 * N + 1; i++) {
            for (int j = 0; j < 2 * N + 1; j++)
                cout << mazeGrid[i][j];
            cout << '\n';
        }
    }
    void change_dir(char c) {
        if (c == 'w' and validDecision(playerRow - 2, playerCol) and mazeGrid[playerRow - 1][playerCol] == ' ') {
            mazeGrid[playerRow][playerCol] = ' ';
            playerRow -= 2;
            mazeGrid[playerRow][playerCol] = 'S';
        } else if (c == 's' and validDecision(playerRow + 2, playerCol) and mazeGrid[playerRow + 1][playerCol] == ' ') {
            mazeGrid[playerRow][playerCol] = ' ';
            playerRow += 2;
            mazeGrid[playerRow][playerCol] = 'S';
        } else if (c == 'a' and validDecision(playerRow, playerCol - 2) and mazeGrid[playerRow][playerCol - 1] == ' ') {
            mazeGrid[playerRow][playerCol] = ' ';
            playerCol -= 2;
            mazeGrid[playerRow][playerCol] = 'S';
        } else if (c == 'd' and validDecision(playerRow, playerCol + 2) and mazeGrid[playerRow][playerCol + 1] == ' ') {
            mazeGrid[playerRow][playerCol] = ' ';
            playerCol += 2;
            mazeGrid[playerRow][playerCol] = 'S';
        }
    }
};

