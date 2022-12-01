class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < coins.size(); ++i)
        {
            vector<int> dp_temp(dp.begin(), dp.end());
            for (int c = 1; c <= amount; ++c)
            {
                dp[c] = 0;
                // amount = 1 ... amount = amount
                for (int k = 0; k <= amount / coins[i]; ++k)
                {
                    if (c - k * coins[i] >= 0)
                        dp[c] += dp_temp[c - k * coins[i]];
                }
            }
        }
        return dp[amount];
    }
};

// 0-1 knapsack

// dp[i][c] 在用了i种硬币的情况下， amount 为 c 有几种可能

// amount = 14, coins = [1, 2, 5]

// c = 4, [1, 2] => 3

// consider: 1*5? 2*5? ... (amount/coins[i]) * 5

// 这样写为什么不是重复的？ 因为我们某位考虑的都是 k * i, 所以这个是unique的

// for i in objs:
//     for c in capacity:
//         for k in range(1, amount/coins[i]):
//             dp[i][c] += dp[i-1][c-k*coins[i]]