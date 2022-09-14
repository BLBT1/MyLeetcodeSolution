class Solution
{
    int m, n;
    int res = 0;

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
                    if (i - 1 >= 0 && board[i - 1][j] == 'X')
                        continue;
                    if (j - 1 >= 0 && board[i][j - 1] == 'X')
                        continue;
                    res += 1;
                }
            }
        }
        return res;
    }
};