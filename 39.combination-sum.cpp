/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution
{
    vector<int> currList;

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        const int n = candidates.size();
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
        if (target == 0)
        {
            res.push_back(currList);
            return;
        }

        for (int i = curr; i < candidates.size(); ++i)
        {
            if (candidates[i] > target)
                break;

            currList.push_back(candidates[i]);
            dfs(candidates, i, target - candidates[i], res);
            currList.pop_back();
        } //for
    }
};
// @lc code=end
