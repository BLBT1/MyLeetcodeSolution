/*
 * @lc app=leetcode id=997 lang=cpp
 *
 * [997] Find the Town Judge
 */

// @lc code=start
class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        if (trust.empty())
            return (n == 1) ? 1 : -1;
        vector<int> cnt(n + 1, 0); // indegree - outdegree of i
        for (int i = 0; i < trust.size(); ++i)
        {
            cnt[trust[i][0]]--;
            cnt[trust[i][1]]++;
        }

        for (int j = 0; j < cnt.size(); ++j)
        {
            if (cnt[j] == n - 1)
            {
                return j;
            }
        }
        return -1;
    }
};
// @lc code=end
