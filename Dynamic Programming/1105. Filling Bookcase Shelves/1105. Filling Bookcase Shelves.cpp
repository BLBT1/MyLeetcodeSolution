class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books,
                         int shelfWidth)
    {
        int n = books.size();
        books.insert(books.begin(), {0, 0});
        vector<int> dp(n+1, INT_MAX/2);
        dp[0] = 0;
        for(int i = 1; i <= n; ++i)
        {
            int maxHeight = books[i][1]; // the maxHegith of the last level
            int totalWidth = books[i][0]; // the total width of this level
            dp[i] = dp[i-1] + maxHeight;
            for(int j = i-1; j > 0; --j)
            {
                totalWidth += books[j][0];
                if(totalWidth > shelfWidth)
                    break;
                maxHeight = max(maxHeight, books[j][1]);
                dp[i] = min(dp[i], maxHeight + dp[j-1]);
            }
        }
        
        return dp[n];
    }
};

// dp[i] => the min height for books[0: i]. we search for j which is the first book of the last level;