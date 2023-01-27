class Solution
{
    int dp[105][105][105];

public:
    int profitableSchemes(int n,
                          int minProfit,
                          vector<int> &group,
                          vector<int> &profit)
    {
        // 知道现在，改变将来
        int Mod = 1e9 + 7;
        int m = group.size();
        group.insert(group.begin(), 0);
        profit.insert(profit.begin(), 0);
        dp[0][0][0] = 1;
        for (int i = 0; i < m; i++)
            for (int j = 0; j <= n; j++)
                for (int p = 0; p <= minProfit; p++)
                {
                    dp[i + 1][j][p] += dp[i][j][p];
                    dp[i + 1][j][p] %= Mod;

                    if (j + group[i + 1] <= n)
                    {
                        dp[i + 1][j + group[i + 1]][min(minProfit, p + profit[i + 1])] += dp[i][j][p];
                        dp[i + 1][j + group[i + 1]][min(minProfit, p + profit[i + 1])] %= Mod;
                    }
                }

        int res = 0;
        for (int j = 0; j <= n; ++j)
        {
            res = (res + dp[m][j][minProfit]) % Mod;
        }
        return res;
    }
};

// dp[i][person][profit] => num of scheme to be profit use first i projects, we person and profit
//   100 100     100*100

// define profit to have 100 demensions,
// dp[i][person][minProfit] =>  num of scheme to be profit use first i projects, we person with minProfit