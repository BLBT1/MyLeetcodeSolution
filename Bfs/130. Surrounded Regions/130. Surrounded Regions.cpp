class Solution
{
    int m = 0;
    int n = 0;
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    void solve(vector<vector<char>> &board)
    {
        m = board.size();
        n = board[0].size();

        // starting from 4 borders
        for (int i = 0; i < m; ++i)
        {
            if (board[i][0] == 'O')
                bfs(board, i, 0);
            if (board[i][n - 1] == 'O')
                bfs(board, i, n - 1);
        }

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
                if (board[i][j] == 'A')
                {
                    board[i][j] = 'O';
                }
                else if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void bfs(vector<vector<char>> &board, int i, int j)
    {
        queue<pair<int, int>> q;
        board[i][j] = 'A';
        q.push({i, j});
        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();
            int a = curr.first;
            int b = curr.second;
            for (auto d : dir)
            {
                int x = a + d.first;
                int y = b + d.second;
                if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'O')
                {
                    q.push({x, y});
                    board[x][y] = 'A';
                }
            }
        }
    }
};