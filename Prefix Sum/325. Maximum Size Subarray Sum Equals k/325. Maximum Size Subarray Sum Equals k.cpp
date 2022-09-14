class Solution
{
public:
    int maxSubArrayLen(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<long, vector<int>> mp; // val -> idx of presum
        long sum = 0;
        mp[0].push_back(-1);
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            sum += nums[i];
            if (mp.find(sum - k) != mp.end())
            {
                res = max(res, i - mp[sum - k][0]);
            }
            mp[sum].push_back(i);
        }
        return res;
    }
};

// [1,-1,5,-2,3]
//