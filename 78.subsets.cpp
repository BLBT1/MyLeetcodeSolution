/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        const int n = nums.size();
        vector<vector<int>> res;
        vector<int> currList;
        int currIdx = 0;
        res.reserve((int)pow(2, n));
        if (n == 0)
            return res;
        subsetHelper(nums, currList, currIdx, res);

        return res;
    }

    void subsetHelper(vector<int> &nums,
                      vector<int> &currList,
                      int currIdx,
                      vector<vector<int>> &res)
    {
        // record curr list
        res.push_back(currList);

        for (int i = currIdx; i < nums.size(); ++i)
        {
            currList.push_back(nums[i]);
            subsetHelper(nums, currList, i + 1, res);
            currList.pop_back();
        } //for
    }
};
// @lc code=end
