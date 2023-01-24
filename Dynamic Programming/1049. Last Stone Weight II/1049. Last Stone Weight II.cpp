class Solution
{
public:
    int lastStoneWeightII(vector<int> &nums)
    {
        int n = nums.size();
        int max_sum = accumulate(nums.begin(), nums.end(), 0);
        int min_sum = -max_sum;
        vector<vector<int>> dp(n + 1, vector<int>(max_sum - min_sum + 1, 0));
        int offset = max_sum;
        nums.insert(nums.begin(), 0);
        dp[0][offset] = 1;
        for (int i = 1; i <= n; ++i)
        {
            for (int s = min_sum; s <= max_sum; ++s)
            {
                if (s - nums[i] >= min_sum && dp[i - 1][s - nums[i] + offset] == 1)
                    dp[i][s + offset] = 1;
                if (s + nums[i] <= max_sum && dp[i - 1][s + nums[i] + offset] == 1)
                    dp[i][s + offset] = 1;
            }
        }

        // find smallest non negative
        for (int i = 0; i <= max_sum; ++i)
        {
            if (dp[n][i + offset] == 1)
                return i;
        }
        return -1;
    }
};
// can we divide all stones into two groups with min diff
// => add sign in front of each elt in nums, what is the smallest possible s?