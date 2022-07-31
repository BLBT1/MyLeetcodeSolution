class Solution
{
    int n;
    vector<vector<string>> res;

public:
    vector<vector<string>> solveNQueens(int n)
    {
        this->n = n;
        string temp = "";
        for (int i = 0; i < n; ++i)
            temp.push_back('.');
        vector<string> board;
        for (int i = 0; i < n; ++i)
            board.push_back(temp);

        dfs(board, 0);
        return res;
    }

    void dfs(vector<string> &board, int row)
    {
        if (row == n)
        {
            res.push_back(board);
            return;
        }
        for (int col = 0; col < n; ++col)
        {
            if (isValid(board, row, col))
            {
                board[row][col] = 'Q';
                dfs(board, row + 1);
                board[row][col] = '.';
            }
        }
    }

    bool isValid(vector<string> &board, int row, int col)
    {
        for (int i = 0; i < n; ++i)
            if (board[i][col] == 'Q')
                return false;
        for (int j = 0; j < n; ++j)
            if (board[row][j] == 'Q')
                return false;

        // check left top
        int k = 1;
        while (row - k >= 0 && col - k >= 0)
        {
            if (board[row - k][col - k] == 'Q')
                return false;
            ++k;
        }

        k = 1;
        while (row - k >= 0 && col + k < n)
        {
            if (board[row - k][col + k] == 'Q')
                return false;
            ++k;
        }

        return true;
    }
};