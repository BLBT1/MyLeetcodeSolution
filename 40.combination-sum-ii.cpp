/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
class Solution
{
    vector<int> currList;

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        int n = candidates.size();
        int curr = 0;
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, curr, target, res);
        return res;
    }

    void dfs(vector<int> &candidates,
             int curr,
             int target,
             vector<vector<int>> &res)
    {
        if (0 == target)
        {
            res.push_back(currList);
            return;
        }
        if (target < 0)
            return;

        for (int i = curr; i < candidates.size(); ++i)
        {
            // 精髓： disallow samw number in the same depth
            if (i > curr && candidates[i] == candidates[i - 1])
                continue;

            currList.push_back(candidates[i]);
            dfs(candidates, i + 1,
                target - candidates[i], res);
            currList.pop_back();
        } //for
    }
};
// @lc code=end
