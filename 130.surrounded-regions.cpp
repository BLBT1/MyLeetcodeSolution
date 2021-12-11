/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

// @lc code=start
class Solution
{

    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

public:
    void solve(vector<vector<char>> &board)
    {
        // reverse logic:
        // instead to find the Os that are surrounded
        // we try to find the Os that are not surrounded
        // but start bfs from the border
        // use a temp char to locate those and later change them back to O

        const int m = board.size();
        if (m == 0)
            return;
        const int n = board[0].size();

        // bfs for left most col and right most col
        for (int i = 0; i < m; ++i)
        {
            if (board[i][0] == 'O')
                bfs(board, i, 0);
            if (board[i][n - 1] == 'O')
                bfs(board, i, n - 1);
        }

        // do for the upper and lower border
        for (int j = 0; j < n; ++j)
        {
            if (board[0][j] == 'O')
                bfs(board, 0, j);
            if (board[m - 1][j] == 'O')
                bfs(board, m - 1, j);
        }

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (board[i][j] == '$')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }

    void bfs(vector<vector<char>> &board, int x, int y)
    {

        const int m = board.size();
        const int n = board[0].size();

        // bfs from the given pt
        queue<pair<int, int>> q;
        q.push({x, y});
        board[x][y] = '$'; // the temp char

        while (!q.empty())
        {
            auto [curr_x, curr_y] = q.front();
            q.pop();

            // try out 4 direction
            for (auto &dir : dirs)
            {
                int d_x = dir.first;
                int d_y = dir.second;

                int next_x = curr_x + d_x;
                int next_y = curr_y + d_y;

                if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n)
                    continue;
                if (board[next_x][next_y] != 'O')
                    continue;
                board[next_x][next_y] = '$';
                q.push({next_x, next_y});
            }

        } //while
    }
};
// @lc code=end
