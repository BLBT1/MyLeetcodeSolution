class Solution
{
public:
    int bestTeamScore(vector<int> &scores,
                      vector<int> &ages)
    {
        // after soring by age => find largest sum subsequence
        int n = ages.size();
        vector<pair<int, int>> age2score;
        for (int i = 0; i < n; ++i)
            age2score.push_back({ages[i], scores[i]});
        sort(age2score.begin(), age2score.end());

        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i)
        {
            dp[i] = age2score[i].second;
            for (int j = 0; j < i; ++j)
            {
                if (age2score[j].first < age2score[i].first && age2score[j].second <= age2score[i].second)
                    dp[i] = max(dp[j] + age2score[i].second, dp[i]);
                else if (age2score[j].first == age2score[i].first)
                    dp[i] = max(dp[j] + age2score[i].second, dp[i]);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

// dp[i]: largest sum by using first i element
// dp[i] = max{dp[j]+age2score.second, dp[i]} for 0 < j < i;