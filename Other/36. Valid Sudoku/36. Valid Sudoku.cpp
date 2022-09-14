class Solution
{
    int m, n;

public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (!isValid(board, i, j))
                    return false;
            }
        }
        return true;
    }

    bool isValid(vector<vector<char>> &board, int x, int y)
    {
        if (board[x][y] == '.')
            return true;
        for (int i = 0; i < m; ++i)
        {
            if (board[i][y] == board[x][y] && i != x)
                return false;
        }

        for (int j = 0; j < n; ++j)
        {
            if (board[x][j] == board[x][y] && j != y)
                return false;
        }

        int a = x / 3 * 3;
        int b = y / 3 * 3;
        for (int i = a; i < a + 3; ++i)
        {
            for (int j = b; j < b + 3; ++j)
            {
                if (board[x][y] == board[i][j] && (i != x || j != y))
                    return false;
            }
        }

        return true;
    }
};