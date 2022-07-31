class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        // switch from indegree to outdegree?
        int n = graph.size();
        vector<int> outdeg(n, 0);
        vector<vector<int>> mp(n);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < graph[i].size(); ++j)
            {
                mp[graph[i][j]].push_back(i);
                outdeg[i]++;
            }
        }

        vector<int> res;
        queue<int> q;
        for (int i = 0; i < n; ++i)
        {
            if (outdeg[i] == 0)
            {
                res.push_back(i);
                q.push(i);
            }
        }

        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();
            for (auto next : mp[curr])
            {
                outdeg[next]--;
                if (outdeg[next] == 0)
                {
                    res.push_back(next);
                    q.push(next);
                }
            }
        }

        sort(res.begin(), res.end());
        return res;
    }
};