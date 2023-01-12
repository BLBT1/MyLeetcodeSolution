class Solution
{
    unordered_map<int, vector<int>> adj;
    vector<int> depths;
    int n;
    vector<bool> hasApple;
    vector<bool> visited;

public:
    int minTime(int n,
                vector<vector<int>> &edges,
                vector<bool> &hasApple)
    {
        this->hasApple = hasApple;
        this->n = n;
        visited = vector<bool>(n, false);
        visited[0] = true;
        for (auto e : edges)
        {
            adj[e[1]].push_back(e[0]);
            adj[e[0]].push_back(e[1]);
        }
        int res = dfs(0);
        return res;
    }

    // idea: each node that we must go over has a cost of 2
    // we need to visited 2 types of node
    // 1. it self has an apple
    // 2. its subtree has an apple
    //      => use postorder traversal
    //      =>  if cost >= 2, then a subtree has at least an apple
    int dfs(int curr)
    {
        int res = 0;
        for (auto next : adj[curr])
        {
            if (visited[next])
                continue;
            visited[next] = true;
            int cost = dfs(next);
            if (cost >= 2)
                res += cost;
        }

        if (hasApple[curr] || res > 0)
            if (curr != 0) // started from 0 index, no need to move
                res += 2;

        return res;
    }
};
