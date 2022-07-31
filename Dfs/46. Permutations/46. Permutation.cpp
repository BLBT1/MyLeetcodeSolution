class Solution
{
    int n;
    vector<vector<int>> res;
    vector<int> list;
    unordered_set<int> visited;

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        n = nums.size();
        dfs(nums, 0);
        return res;
    }

    void dfs(vector<int> &nums, int curr)
    {
        if (list.size() == n)
        {
            res.push_back(list);
            return;
        }
        for (int i = 0; i < n; ++i)
        {
            if (visited.find(nums[i]) != visited.end())
                continue;

            list.push_back(nums[i]);
            visited.insert(nums[i]);
            dfs(nums, i + 1);
            list.pop_back();
            visited.erase(nums[i]);
        }
    }
};