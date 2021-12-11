class Solution
{
    vector<vector<int>> graph;
    int n; // num of nodes
public:
    int treeDiameter(vector<vector<int>> &edges)
    {
        // randomly pick a node A
        // use bfs to find the longest node B from A
        // than find the longest path C from B
        // BC is the diameter of the given tree

        //1. construct an adjacency matrix
        n = edges.size() + 1;
        graph.resize(n);
        for (auto edge : edges)
        {
            int a = edge[0];
            int b = edge[1];

            graph[a].push_back(b);
            graph[b].push_back(a);
        } //for

        int A = 0;
        auto [B, AB] = bfs(A);
        auto [C, BC] = bfs(B);

        return BC;
    }

    // use bfs to return the furthest node from the given node u
    pair<int, int> bfs(int u)
    {
        vector<int> dis(n, -1);
        queue<int> q;
        q.push(u);

        dis[u] = 0;

        while (!q.empty())
        {
            int t = q.front();
            q.pop();

            for (auto it = graph[t].begin(); it != graph[t].end(); it++)
            {
                int v = *it;
                if (dis[v] == -1)
                {
                    q.push(v);
                    dis[v] = dis[t] + 1;
                }
            }
        }

        auto maxPath = max_element(dis.begin(), dis.end());

        int maxDis = *maxPath;
        int nodeIdx = maxPath - dis.begin();

        return make_pair(nodeIdx, maxDis);
    }
};