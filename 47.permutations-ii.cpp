/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> currList;
        vector<bool> visited(nums.size(), false);
        vector<vector<int>> res;
        helper(nums, currList, visited, res);
        return res;
    }

    void helper(vector<int> &nums,
                vector<int> &currList,
                vector<bool> &visited,
                vector<vector<int>> &res)
    {
        if (currList.size() == nums.size())
            res.push_back(vector<int>(currList.begin(), currList.end()));

        for (int i = 0; i < nums.size(); ++i)
        {
            if (visited[i] ||
                i >= 1 && nums[i] == nums[i - 1] && !visited[i - 1])
                continue;
            currList.push_back(nums[i]);
            visited[i] = true;
            helper(nums, currList, visited, res);
            currList.pop_back();
            visited[i] = false;
        } //for
    }
};
// @lc code=end
