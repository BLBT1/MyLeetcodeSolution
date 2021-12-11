/*
 * @lc app=leetcode id=363 lang=cpp
 *
 * [363] Max Sum of Rectangle No Larger Than K
 */

// @lc code=start
class Solution
{
public:
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k)
    {
        const int m = matrix.size();
        if (m == 0)
            return 0;
        int res = INT_MIN;
        const int n = matrix[0].size();

        // time is O(m^2 n^2 logn)
        // logn is extra for n
        if (m > n)
        {
            vector<vector<int>> matrix2(n, vector<int>(m, 0));
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    matrix2[j][i] = matrix[i][j];
            return maxSumSubmatrix(matrix2, k);
        }

        // determine a upper bound and a lower bound
        for (int i = 0; i < m; i++)
        {
            vector<int> row(n, 0);
            for (int j = i; j < m; j++)
            {
                for (int k = 0; k < n; k++)
                    row[k] += matrix[j][k];
                res = max(res, findClosestSumVec(row, k));
            }
        }
        return res;
    }

    //用前缀和思想
    int findClosestSumVec(vector<int> &sums, int k)
    {
        set<int> Set({0});
        int preSum = 0;
        int res = INT_MIN;
        for (int i = 0; i < sums.size(); i++)
        {
            preSum += sums[i];
            auto iter = Set.lower_bound(preSum - k);
            if (iter != Set.end())
                res = max(res, preSum - *iter);
            Set.insert(preSum);
        }
        return res;
    }
};
// @lc code=end
