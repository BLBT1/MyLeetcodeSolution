/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        int up = 0, down = n - 1;    // up to down
        int left = 0, right = n - 1; // left to right
        int val = 1;
        vector<vector<int>> res(n, vector<int>(n, 0));

        while (up <= down && left <= right)
        {
            for (int i = left; i <= right; ++i)
            {
                res[up][i] = val++;
            }

            for (int j = up + 1; j <= down; ++j)
            {
                res[j][right] = val++;
            }

            for (int i = right - 1; i >= left; --i)
            {
                res[down][i] = val++;
            }
            for (int j = down - 1; j >= up + 1; --j)
            {
                res[j][left] = val++;
            }
            left++;
            right--;
            up++;
            down--;
        }
        return res;
    }
};
// @lc code=end
