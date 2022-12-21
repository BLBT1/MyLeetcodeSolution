class Solution
{
    unordered_map<int, vector<int>> adj;
    vector<int> colors;

public:
    bool possibleBipartition(int n, vector<vector<int>> &dislikes)
    {
        // 要用图的思维把题目转化成 is bipartle 的题目
        // 也就是把图染色成 红色和蓝色两组，
        // 要确保所有的 dislike/edge 都是在两组之间
        colors = vector<int>(n + 1, 0);
        // 0->not colored, -1 -> red, 1 -> blue
        for (auto e : dislikes)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        for (int i = 1; i <= n; ++i)
        {
            if (colors[i] == 0 && dfs(i, 1) == false)
                return false;
        }
        return true;
    }

    bool dfs(int curr, int c)
    {
        colors[curr] = c;
        for (int next : adj[curr])
        {
            if (colors[next] == colors[curr])
                return false;
            if (colors[next] == 0 && !dfs(next, -c))
                return false;
        }
        return true;
    }
};