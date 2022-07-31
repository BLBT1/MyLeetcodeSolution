class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int tar)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (mp.find(tar - nums[i]) != mp.end())
                return {i, mp[tar - nums[i]]};
            mp[nums[i]] = i;
        }
        return {};
    }
};