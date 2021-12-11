/*
 * @lc app=leetcode id=529 lang=cpp
 *
 * [529] Minesweeper
 */

// @lc code=start
class Solution
{
    vector<pair<int, int>> dirs = {{0, 1},
                                   {1, 0},
                                   {1, 1},
                                   {-1, 0},
                                   {0, -1},
                                   {-1, -1},
                                   {1, -1},
                                   {-1, 1}};

public:
    vector<vector<char>>
    updateBoard(vector<vector<char>> &board,
                vector<int> &click)
    {
        int c_x = click[0];
        int c_y = click[1];
        if (board[c_x][c_y] == 'M')
        {
            board[c_x][c_y] = 'X';
        }
        else if (board[c_x][c_y] == 'E')
        {
            bfs(board, c_x, c_y);
        }

        return board;
    }

    void bfs(vector<vector<char>> &board, int x, int y)
    {
        const int m = board.size();
        const int n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        queue<pair<int, int>> q;
        q.push({x, y});
        visited[x][y] = true;

        while (!q.empty())
        {
            auto [curr_x, curr_y] = q.front();
            q.pop();
            int count = 0;
            vector<pair<int, int>> temp;

            for (auto &dir : dirs)
            {
                int n_x = curr_x + dir.first;
                int n_y = curr_y + dir.second;

                if (n_x < 0 || n_x >= m || n_y < 0 || n_y >= n)
                    continue;

                if (board[n_x][n_y] == 'M')
                {
                    count++;
                }
                else if (!visited[n_x][n_y])
                {
                    temp.push_back({n_x, n_y});
                }
            }

            if (count != 0)
                board[curr_x][curr_y] = count + '0';
            else
            {
                board[curr_x][curr_y] = 'B';
                for (auto &p : temp)
                {
                    visited[p.first][p.second] = true;
                    q.push({p.first, p.second});
                }
            }
        } //while
    }
};
// @lc code=end
