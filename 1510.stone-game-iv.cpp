/*
 * @lc app=leetcode id=1510 lang=cpp
 *
 * [1510] Stone Game IV
 */

// @lc code=start
class Solution
{
public:
    bool winnerSquareGame(int n)
    {
        vector<int> memo(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j * j <= i; ++j)
            {
                if (memo[i - j * j] == 0)
                {
                    memo[i] = 1;
                    break;
                }
            }
        }
        return memo[n];
    }
};
// @lc code=end

// define dp[i] <- the the win or lose for the i stones in the pile
