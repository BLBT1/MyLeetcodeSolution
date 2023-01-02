class Solution
{
public:
    string minWindow(string s1, string s2)
    {
        int m = s1.size();
        int n = s2.size();
        s1 = "#" + s1;
        s2 = "#" + s2;
        auto dp = vector<vector<int>>(m + 1, vector<int>(n + 1));
        dp[0][0] = 0;
        for (int i = 1; i <= m; ++i)
            dp[i][0] = 0;
        for (int j = 1; j <= n; ++j)
            dp[0][j] = INT_MAX / 2;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (s1[i] == s2[j])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] + 1;
                }
            }
        }

        int len = INT_MAX / 2;
        int pos; // the position of the last char
        for (int i = 1; i <= m; i++)
        {
            if (dp[i][n] < len)
            {
                len = dp[i][n];
                pos = i;
            }
        }

        string res = (len >= INT_MAX / 2) ? "" : s1.substr(pos - len + 1, len);
        return res;
    }
};

// dp[i][j] =>  min window in s1[1:i] contians s2[1:j]

// XXXX i
// YY j

// if(s1[i] == s2[j])
//     dp[i][j] = dp[i-1][j-1]+1;
// else
//     dp[i][j] = dp[i-1][j]+1 // 说明s1[i] 对于包含s2[1:j]没有用，所以
//     我们需要看 s1[1:i-1], 如果 s1[1:i-1] 也没有 s2[1:j], 我们就用需要无限大来表示