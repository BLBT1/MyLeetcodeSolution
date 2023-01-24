class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();
        int max_sum = 0;
        int min_sum = 0;
        for (auto i : nums)
        {
            max_sum += i;
            min_sum -= i;
        }

        if (max_sum < target || min_sum > target)
            return 0;

        int offset = max_sum;
        vector<vector<int>> dp(n + 1, vector<int>(max_sum - min_sum + 1, 0));
        dp[0][offset] = 1;
        nums.insert(nums.begin(), 0);
        for (int i = 1; i <= n; ++i)
        {
            for (int s = min_sum; s <= max_sum; ++s)
            {
                if (s - nums[i] >= min_sum)
                    dp[i][s + offset] += dp[i - 1][s - nums[i] + offset];
                if (nums[i] + s <= max_sum)
                    dp[i][s + offset] += dp[i - 1][s + nums[i] + offset];
            }
        }

        return dp[n][target + offset];
    }
};

// 每个元素只能用一次, 但是必须要用到，所以还是01背包问题
// dp[i][s] => how many expr using first i element to get sum s
