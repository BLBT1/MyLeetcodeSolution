/*
 * @lc app=leetcode id=1901 lang=cpp
 *
 * [1901] Find a Peak Element II
 */

// @lc code=start
class Solution
{
public:
    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        int lower = 0, upper = m - 1;

        while (lower <= upper)
        {
            int mid = (upper - lower) / 2 + lower;

            // XXX_max is the max element from a row
            int mid_max = *max_element(mat[mid].begin(),
                                       mat[mid].end());
            int up_max = mid_max == m - 1 ? -1 : *max_element(mat[upper].begin(), mat[upper].end());
            int low_max = mid_max == 0 ? -1 : *max_element(mat[lower].begin(), mat[lower].end());
            int mx = max(up_max, max(mid_max, low_max));
            if (mid_max == mx)
            {
                return {mid, int(max_element(mat[mid].begin(), mat[mid].end()) - mat[mid].begin())};
            }
            else if (mx == low_max)
            {
                upper = mid - 1;
            }
            else
            {
                lower = mid + 1;
            }
        }

        return {-1, -1};
    }
};

// // [[10,20,15],
// //  [21,30,14],
// //  [7,16,32]]

// l 0 u 2 mid = 1 mid_m = 30 up_m = 32 low_m = 20
// l 2 u 2 mid 2

// @lc code=end
