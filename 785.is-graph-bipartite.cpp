/*
 * @lc app=leetcode id=785 lang=cpp
 *
 * [785] Is Graph Bipartite?
 */

// @lc code=start
class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        // for each node in the graph
        // if it is not visited
        // start from that node
        // and do bfs
        const int n = graph.size();
        vector<int> visited(n, -1);

        for (int i = 0; i < n; ++i)
        {
            if (visited[i] == -1)
                if (!bfs(graph, visited, i))
                    return false;
        } //for

        return true;
    }

    // bfs start from the node i
    bool bfs(vector<vector<int>> &graph,
             vector<int> &visited,
             int i)
    {
        queue<pair<int, int>> q;
        q.push({i, 0}); // {node, group}
        visited[i] = 0;

        while (!q.empty())
        {
            int node = q.front().first;
            int group = q.front().second;
            q.pop();

            for (auto next : graph[node])
            {

                if (visited[next] != -1)
                {
                    if (visited[next] != 1 - group)
                        return false;
                }
                else
                {
                    visited[next] = 1 - group;
                    q.push({next, 1 - group});
                }
            }
        }

        return true;
    }
};
// @lc code=end
