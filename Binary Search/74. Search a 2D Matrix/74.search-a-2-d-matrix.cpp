/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        // range: [l:r] = [0:m*n-1]
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0;
        int r = m * n - 1;
        int mid;
        while (l < r)
        {
            mid = l + (r - l) / 2;
            // smash 2d array into 1d
            int x = mid / n; // which row
            int y = mid % n; // which col
            if (matrix[x][y] < target)
            {
                l = mid + 1;
            }
            else if (matrix[x][y] > target)
            {
                r = mid - 1;
            }
            else
            {
                return true;
            }
        }
        if (l == r && matrix[l / n][l % n] == target)
        {
            return true;
        }
        return false;
    }
};
// @lc code=end
