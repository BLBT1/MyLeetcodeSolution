/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start
class Solution
{

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        // 和 078 很类似， 但是需要注意怎么规避重复
        // sort + a visited list
        const int n = nums.size();
        vector<vector<int>> res;
        if (n == 0)
            return res;

        vector<bool> visited(n, false);

        res.reserve((int)pow(2, n));

        sort(nums.begin(), nums.end(), less<int>());

        vector<int> currList;
        int currIdx = 0;

        dfs(nums, currIdx, currList, visited, res);

        return res;
    }

    void dfs(vector<int> &nums,
             int currIdx,
             vector<int> &currList,
             vector<bool> &visited,
             vector<vector<int>> &res)
    {
        res.push_back(currList);

        for (int i = currIdx; i < nums.size(); ++i)
        {
            // remove duplicates, like 3 sum problem
            if ((i >= 1 && nums[i] == nums[i - 1]) &&
                visited[i - 1] == false)
                continue;

            visited[i] = true;
            currList.push_back(nums[i]);
            dfs(nums, i + 1, currList, visited, res);
            currList.pop_back();
            visited[i] = false;

        } //for
    }
};
// @lc code=end
