class Solution
{
    vector<vector<int>> dp;
    unordered_map<int, vector<int>> adj;

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
    {
        for (auto e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dp = vector<vector<int>>(n, vector<int>(n, INT_MAX));

        for (int i = 0; i < n; ++i)
        {
            dfs(i, i, 0);
        }

        vector<int> res(n, 0);
        for (int i = 0; i < n; ++i)
        {
            int sum = 0;
            for (int j = 0; j < n; ++j)
            {
                if (dp[i][j] != INT_MAX)
                    sum += dp[i][j];
            }
            res[i] = sum;
        }

        return res;
    }

    void dfs(int src, int curr, int dist)
    {
        dp[src][curr] = dist;
        // dp[src] += dist
        for (int next : adj[curr])
        {
            if (dp[src][next] == INT_MAX)
                dfs(src, next, dist + 1);
        }
    }
};