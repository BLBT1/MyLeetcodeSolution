class Solution
{
    vector<int> nums;

public:
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        vector<vector<int>> res;
        this->nums = nums;
        int curr = 0;
        vector<int> currList;
        dfs(curr, currList, res);
        return res;
    }

    void dfs(int curr, vector<int> &currList, vector<vector<int>> &res)
    {
        if (currList.size() >= 2)
            res.push_back(currList);
        if (curr == nums.size())
            return;
        unordered_set<int> visited; // 每一层一个visited

        for (int i = curr; i < nums.size(); ++i)
        {
            if (visited.find(nums[i]) != visited.end())
                continue;
            if (currList.size() > 0 && currList.back() > nums[i])
                continue;

            visited.insert(nums[i]);
            currList.push_back(nums[i]);
            dfs(i + 1, currList, res);
            currList.pop_back();
        }
    }
};
