class Solution
{
public:
    int treeDiameter(vector<vector<int>> &edges)
    {
        unordered_map<int, vector<int>> adj;
        for (auto &e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // find longest Path from A to B
        auto t1 = bfs(adj, 0);
        // find longest path from B to C
        auto t2 = bfs(adj, t1.first);
        return t2.second;
    }

    // return pair: {end Node, max dist}
    pair<int, int> bfs(unordered_map<int, vector<int>> adj, int u)
    {
        set<int> visited;
        unordered_map<int, int> dis; // dis of each node, -1 if not visited
        queue<int> q;
        q.push(u);
        visited.insert(u);

        int height = 1;
        while (!q.empty())
        {
            int level = q.size();
            for (int i = 0; i < level; ++i)
            {
                int t = q.front();
                q.pop();
                for (auto &x : adj[t])
                {
                    if (visited.find(x) == visited.end())
                    {
                        q.push(x);
                        visited.insert(x);
                        dis[x] = height;
                    }
                }
            }
            height++;
        }

        int maxDis = 0;
        int nodeIdx;

        for (auto p : dis)
        {
            if (p.second > maxDis)
            {
                maxDis = p.second;
                nodeIdx = p.first;
            }
        }
        return make_pair(nodeIdx, maxDis);
    }
};