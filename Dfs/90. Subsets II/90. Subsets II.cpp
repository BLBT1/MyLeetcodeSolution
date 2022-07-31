class Solution
{
    int n;
    vector<vector<int>> res;
    vector<int> currList;

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        n = nums.size();
        // sort to remove duplicate subset
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return res;
    }

    void dfs(vector<int> &nums, int curr)
    {
        res.push_back(currList);
        for (int i = curr; i < n; ++i)
        {
            if (i != curr && nums[i] == nums[i - 1])
                continue;
            currList.push_back(nums[i]);
            dfs(nums, i + 1);
            currList.pop_back();
        }
    }
};