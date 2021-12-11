/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution
{
    // my dfs solution
    // 同样也可以使用插板法（guan神）
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<int> currList;
        vector<vector<int>> res;
        helper(nums, currList, res);
        return res;
    }

    void helper(vector<int> &nums,
                vector<int> &currList,
                vector<vector<int>> &res)
    {
        if (currList.size() == nums.size())
            res.push_back(vector<int>(currList.begin(), currList.end()));

        for (int i = 0; i < nums.size(); ++i)
        {
            int j = 0;
            for (; j < currList.size() && currList[j] != nums[i]; ++j)
                ;
            if (j == currList.size())
            {
                currList.push_back(nums[i]);
                helper(nums, currList, res);
                currList.pop_back();
            }
        } //for
    }
};
// @lc code=end
