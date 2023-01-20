class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &mat)
    {
        int m = mat.size();
        if (m == 0)
            return {};
        int n = mat[0].size();
        int rowBeg = 0;
        int colBeg = 0;
        int rowEnd = m - 1;
        int colEnd = n - 1;
        vector<int> res;

        while (rowBeg <= rowEnd && colBeg <= colEnd)
        {
            // from left to right
            for (int j = colBeg; j <= colEnd; ++j)
            {
                res.push_back(mat[rowBeg][j]);
            }
            rowBeg += 1;

            // from up to down
            for (int i = rowBeg; i <= rowEnd; ++i)
            {
                res.push_back(mat[i][colEnd]);
            }
            colEnd -= 1;

            // from right to left
            // to handle special case1 below:
            if (rowBeg <= rowEnd)
            {
                for (int j = colEnd; j >= colBeg; --j)
                {
                    res.push_back(mat[rowEnd][j]);
                }
            }
            rowEnd -= 1;

            // from down to up
            // handle special case2
            if (colBeg <= colEnd)
            {
                for (int i = rowEnd; i >= rowBeg; --i)
                {
                    res.push_back(mat[i][colBeg]);
                }
            }
            colBeg += 1;
        }
        return res;
    }
};

// special case 1:
// rowBeg = 1
// rowEnd = 1
// colBeg = 1
// colEnd = 2

// 1, 2, 3, 4
// 5, 6, 7, 8
// 9, 10,11,12

// special case 2:
// 1 2 3
// 4 5 6
// 7 8 9
// 10 11 12
