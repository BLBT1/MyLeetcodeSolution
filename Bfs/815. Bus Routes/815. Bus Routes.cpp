class Solution
{
    int n = 0; // num of bus in total
public:
    int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
    {
        n = routes.size();
        if (source == target)
            return 0;
        // first use hashmap to make a adj list
        unordered_map<int, vector<int>> adj; // stop -> bus
        unordered_map<int, unordered_set<int>> same_bus;
        for (int i = 0; i < routes.size(); ++i)
        {
            for (int j = 0; j < routes[i].size(); ++j)
            {
                adj[routes[i][j]].push_back(i);
            }
            same_bus[i] = unordered_set(routes[i].begin(), routes[i].end());
        }

        int step = 1;
        vector<bool> visited(n, false);
        queue<int> q;
        // for what bus has the source, all push into q
        for (auto bs : adj[source])
        {
            q.push(bs);
            visited[bs] = true;
        }
        while (!q.empty())
        {
            int len = q.size();
            for (int w = 0; w < len; ++w)
            {
                auto curr = q.front();
                q.pop();
                if (same_bus[curr].find(target) != same_bus[curr].end())
                {
                    return step;
                }
                for (auto bus : same_bus[curr])
                {
                    for (auto next : adj[bus])
                    {
                        if (visited[next] == true)
                            continue;
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};