class Solution
{
    vector<vector<int>> res;
    int n;

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        n = nums.size();
        vector<int> currList;
        dfs(nums, 0, currList);
        return res;
    }

    void dfs(vector<int> &nums, int curr, vector<int> &currList)
    {
        res.push_back(currList);
        for (int i = curr; i < n; ++i)
        {
            currList.push_back(nums[i]);
            dfs(nums, i + 1, currList);
            currList.pop_back();
        }
    }
};