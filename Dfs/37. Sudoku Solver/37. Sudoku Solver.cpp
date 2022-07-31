class Solution
{
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        dfs(board, 0, 0);
    }

    bool dfs(vector<vector<char>> &board, int i, int j)
    {
        if (i == 9)
            return true;
        else if (j == 9)
            return dfs(board, i + 1, 0);
        else if (board[i][j] != '.')
            return dfs(board, i, j + 1);

        for (char c = '1'; c <= '9'; ++c)
        {
            if (!isValid(board, i, j, c))
                continue;
            board[i][j] = c;
            if (dfs(board, i, j + 1))
                return true;
            board[i][j] = '.';
        }
        return false;
    }

    bool isValid(vector<vector<char>> &board, int x, int y, char c)
    {
        for (int i = 0; i < 9; ++i)
        {
            if (c == board[i][y])
                return false;
        }
        for (int j = 0; j < 9; ++j)
        {
            if (c == board[x][j])
                return false;
        }

        int a = x / 3 * 3;
        int b = y / 3 * 3;
        for (int i = a; i < a + 3; ++i)
        {
            for (int j = b; j < b + 3; ++j)
            {
                if (board[i][j] == c)
                    return false;
            }
        }
        return true;
    }
};