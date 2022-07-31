class Solution
{
    vector<vector<int>> res;
    vector<int> currList;
    int currSum = 0;
    int target;

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        // sort 去重
        sort(candidates.begin(), candidates.end());
        this->target = target;

        int curr = 0;
        dfs(curr, candidates);
        return res;
    }

    void dfs(int curr, vector<int> &nums)
    {
        if (currSum == target)
        {
            res.push_back(currList);
            return;
        }
        else if (currSum > target)
        {
            return;
        }

        for (int i = curr; i < nums.size(); ++i)
        {
            currList.push_back(nums[i]);
            currSum += nums[i];
            dfs(i, nums);
            currSum -= nums[i];
            currList.pop_back();
        }
    }
};

// 2, 3, 6, 7   tar = 7
// [2, 2, 2]
// [2,2,3][7]
