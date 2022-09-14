class Solution
{
    int m, n;
    int res = 0;
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

public:
    int countBattleships(vector<vector<char>> &board)
    {
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (board[i][j] == 'X')
                {
                    res += 1;
                    dfs(board, i, j);
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<char>> &board, int i, int j)
    {

        board[i][j] = 'Y';

        for (auto d : dirs)
        {
            int x = i + d.first;
            int y = j + d.second;
            if (x < 0 || x >= m || y < 0 || y >= n)
                continue;
            if (board[x][y] != 'X')
                continue;
            dfs(board, x, y);
        }
    }
};