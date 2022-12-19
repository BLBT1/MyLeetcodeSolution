class Solution
{
public:
    bool validPath(int n,
                   vector<vector<int>> &edges,
                   int src,
                   int dest)
    {
        unordered_map<int, vector<int>> adj;
        vector<int> visited(n, 0);
        for (auto e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        return dfs(adj, visited, src, dest);
    }

    bool dfs(unordered_map<int, vector<int>> &adj, vector<int> &visited, int curr, int dest)
    {
        if (curr == dest)
            return true;
        for (auto next : adj[curr])
        {
            if (visited[next] == 1)
                continue;
            visited[next] = 1;
            if (dfs(adj, visited, next, dest))
                return true;
        }
        return false;
    }
};