class Solution {
    vector<pair<int, int>> dir = {{-1, 0}, {-1, -1}, {-1, 1}};
public:
    int minFallingPathSum(vector<vector<int>>& mat) 
    {
        const int m = mat.size();
        const int n = mat[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for(int j = 0; j < n; ++j)
        {
            dp[0][j] = mat[0][j];
        }
        
        for(int i = 1; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                int last_min = INT_MAX;
                for(auto p: dir)
                {
                    if(i+p.first >= 0 && i+p.first < m && j + p.second >= 0 && j+p.second < n)
                        last_min = min(dp[i+p.first][j+p.second], last_min);
                }
                dp[i][j] = last_min + mat[i][j]; 
            }
        }
        
        int res = *min_element(dp[m-1].begin(), dp[m-1].end());
        return res;
    }
};

// time: O(m*n)
// space: O(m*n)