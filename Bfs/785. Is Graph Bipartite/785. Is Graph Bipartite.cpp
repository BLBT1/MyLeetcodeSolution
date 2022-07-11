class Solution
{
    int n = 0; // num of nodes in G
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        n = graph.size();
        vector<int> grp(n, -1); // grp[i] => node i in what grp? -1 mean not visited
        for (int i = 0; i < n; ++i)
        {
            if (grp[i] == -1)
            {
                bool conflict = bfs(i, grp, graph);
                if (conflict == true)
                    return false;
            }
        }
        return true;
    }

    bool bfs(int node, vector<int> &grp, vector<vector<int>> &graph)
    {
        queue<pair<int, int>> q; // {node, grp in}
        q.push({node, 0});
        while (!q.empty())
        {
            int len = q.size();
            for (int w = 0; w < len; ++w)
            {
                auto curr = q.front().first;
                auto currGrp = q.front().second;
                q.pop();
                for (auto next : graph[curr])
                {
                    if (grp[next] == -1)
                    {
                        grp[next] = 1 - currGrp; // 0->1 && 1->0
                        q.push({next, 1 - currGrp});
                    }
                    else
                    {
                        if (currGrp == grp[next])
                            return true;
                    }
                }
            }
        }
        return false;
    }
};