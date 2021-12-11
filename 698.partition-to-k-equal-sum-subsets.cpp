/*
 * @lc app=leetcode id=698 lang=cpp
 *
 * [698] Partition to K Equal Sum Subsets
 */

// @lc code=start
class Solution
{
    int total = 0;
    int k = 0;

public:
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        total = accumulate(nums.begin(), nums.end(), 0);
        this->k = k;
        if (total % k != 0)
            return false;
        vector<bool> visited(16, false);
        int curr = 0;
        int currGrp = 0;
        int currGrpSum = 0;
        return dfs(nums, visited, curr, currGrp, currGrpSum);
    }

    bool dfs(vector<int> &nums, vector<bool> &visited,
             int curr, int currGrp, int currGrpSum)
    {
        // pruning
        if (currGrp == k)
            return true;
        if (currGrpSum > total / k)
            return false;
        if (currGrpSum == total / k)
            return dfs(nums, visited, 0, currGrp + 1, 0);

        for (int i = curr; i < nums.size(); ++i)
        {
            if (visited[i])
                continue;
            visited[i] = true;
            if (dfs(nums, visited, i + 1,
                    currGrp, currGrpSum + nums[i]))
                return true;
            visited[i] = false;
        } //for

        return false;
    }
};
// @lc code=end
