class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> res(numRows);
        for (int i = 0; i < numRows; ++i)
        {
            res[i].resize(i + 1);
            if (i == 0)
                res[i][0] = 1;
            else if (i == 1)
                res[i][0] = res[i][1] = 1;
            else
            {
                res[i][0] = 1;
                for (int j = 1; j < i; ++j)
                {
                    res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
                }
                res[i][i] = 1;
            }
        }
        return res;
    }
};