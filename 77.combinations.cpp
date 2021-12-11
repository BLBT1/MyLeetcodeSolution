/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start

class Solution
{
    vector<vector<int>> res;

public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> comb;
        comb.reserve(k);
        DFS(n, k, 1, comb);
        return res;
    }

    void DFS(int n, int k, int cur, vector<int> &comb)
    {
        if (comb.size() == k)
        {
            res.push_back(comb);
            return;
        }

        for (int i = cur; i <= n; i++)
        {
            comb.push_back(i);
            DFS(n, k, i + 1, comb);
            comb.pop_back();
        }
    }
};
// @lc code=end
