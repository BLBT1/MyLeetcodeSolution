/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        const int m = matrix.size();
        const int n = matrix[0].size();
        // if we cannot set 0 right away,
        // this will flip more unnecessary node in the matrix
        // so instead, if mat[x][y] is a 0, we set mat[0][y] and mat[x][0] to be 0
        bool havefirstRowZero = false;
        bool havefirstColZero = false;
        for (int i = 0; i < m; ++i)
            if (matrix[i][0] == 0)
                havefirstColZero = true;

        for (int j = 0; j < n; ++j)
            if (matrix[0][j] == 0)
                havefirstRowZero = true;

        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                if (matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }

        for (int i = 1; i < m; ++i)
            if (matrix[i][0] == 0)
            {
                for (int row = 1; row < n; ++row)
                {
                    matrix[i][row] = 0;
                }
            }
        // for (int i = 0; i < m; ++i)
        // {
        //     for (int j = 0; j < n; ++j)
        //         cout << matrix[i][j] << " ";
        //     cout << endl;
        // }

        for (int j = 1; j < n; ++j)
            if (matrix[0][j] == 0)
            {
                for (int col = 1; col < m; ++col)
                {
                    matrix[col][j] = 0;
                }
            }

        if (havefirstColZero)
            for (int i = 0; i < m; ++i)
            {
                matrix[i][0] = 0;
            }

        if (havefirstRowZero)
            for (int j = 0; j < n; ++j)
            {
                matrix[0][j] = 0;
            }
    }
};
// @lc code=end

// [0,1,2,0],
// [0,4,5,0],
// [0,3,1,0]
//
// hasrow = true
// hascol = true
//