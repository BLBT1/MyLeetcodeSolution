class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0 || s[0] == '0')
            return 0;
        
        const int n = s.size();
        // dp[i+1] <- s[0: i] has how many combos
        vector<int> dp(n+1, 0);

        dp[0] =  dp[1] = 1;
        
        for(int i = 1; i < s.size(); ++i)
        {
            if(s[i] != '0')
                dp[i+1] += dp[i];
            int val = stoi(s.substr(i-1, 2));
            if(val >= 10 && val <= 26)
                dp[i+1] += dp[i-1];
        }
        
        return dp[n];
    }
};