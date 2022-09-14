class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        // 基础的时间序列dp，dp[i] 的状态只取决于 dp[i-1] 的状态
        // dp[i] => 加上nums[i]后能过多组成的 等差数列
        int n = nums.size();
        vector<int> dp(n, 0);
        int res = 0;

        for (int i = 2; i < n; ++i)
        {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
                dp[i] = dp[i - 1] + 1;
            res += dp[i];
        }
        return res;
    }
};

// [1,2,3,4,5,10, 11, 12, 13]
//      1 2 3          1   2
