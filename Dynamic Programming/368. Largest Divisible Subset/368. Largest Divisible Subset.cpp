class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> pos(n, -1);
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[i] % nums[j] == 0)
                {
                    if (dp[j] + 1 > dp[i])
                    {
                        pos[i] = j;
                        dp[i] = dp[j] + 1;
                    }
                }
            }
        }

        // 回溯逆推
        vector<int> res;
        int mx = max_element(dp.begin(), dp.end()) - dp.begin();
        int i = mx;
        while (i != -1)
        {
            res.push_back(nums[i]);
            i = pos[i];
        }
        return res;
    }
};