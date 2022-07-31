class Solution
{
    int n;
    vector<int> list;
    vector<vector<int>> res;

public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        n = nums.size();
        vector<bool> used(n, false);
        dfs(nums, used, 0);
        return res;
    }

    void dfs(vector<int> &nums, vector<bool> &used, int curr)
    {
        if (list.size() == n)
        {
            res.push_back(list);
        }

        for (int i = 0; i < n; ++i)
        {
            if (used[i] || i > 0 && nums[i - 1] == nums[i] && !used[i - 1])
                continue;
            used[i] = true;
            list.push_back(nums[i]);
            dfs(nums, used, i + 1);
            list.pop_back();
            used[i] = false;
        }
    }
};