class Solution {
public:
    bool isValidPalindrome(string s, int k) 
    {
        string s1 = s, s2 = s;
        reverse(s2.begin(), s2.end());
        // 把s反过来， named s2， 找s2 和 s的lcs
        // 注意：要要删的字符不一定evenly分布， 所以不能对半切来对比
        int m = s1.size();
        int n = s2.size();
        s1 = "#"+s1;
        s2 = "#"+s2;
        auto dp = vector<vector<int>>(m+1, vector<int>(n+1, 0));
        for(int i = 1; i <= m; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                if(s1[i] == s2[j])
                    dp[i][j] = dp[i-1][j-1]+1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return s.size()-dp[m][n]<= k;
    }
};
// XX XXX
// 01 23