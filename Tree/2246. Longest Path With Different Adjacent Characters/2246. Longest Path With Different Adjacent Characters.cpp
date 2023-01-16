class Solution
{
    unordered_map<int, vector<int>> adj;
    vector<int> paths; // longest path of each node with not turnover
    int res = 1;
    string s;

public:
    int longestPath(vector<int> &parent,
                    string s)
    {
        this->s = s;
        int n = s.size();
        for (int i = 0; i < parent.size(); ++i)
        {
            if (parent[i] == -1)
                continue;
            adj[parent[i]].push_back(i);
        }

        paths = vector<int>(n, 1);

        dfs(0);

        return res;
    }

    void dfs(int curr)
    {
        if (adj[curr].size() == 0)
        {
            paths[curr] = 1;
            return;
        }

        // find longest no turnover path of curr node
        vector<int> pool;
        for (int next : adj[curr])
        {
            dfs(next);
            if (s[curr] != s[next])
            {
                paths[curr] = max(paths[curr], paths[next] + 1);
                pool.push_back(paths[next]);
            }
            else
            {
                paths[curr] = max(paths[curr], 1);
            }
        }

        sort(pool.rbegin(), pool.rend());

        if (pool.size() >= 2)
        {
            res = max(res, pool[0] + pool[1] + 1);
        }
        else if (pool.size() == 1)
        {
            res = max(res, pool[0] + 1);
        }
    }
};
