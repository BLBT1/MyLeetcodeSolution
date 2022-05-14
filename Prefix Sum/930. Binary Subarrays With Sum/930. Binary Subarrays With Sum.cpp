class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        // 如果是返回一个去区间的话， 那用滑动窗口
        // 如果是返回有几种， 那用前缀和
        int res = 0;
        int sum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            if (mp.find(sum - goal) != mp.end())
            {
                res += mp[sum - goal];
            }
            mp[sum]++;
        }
        return res;
    }
};