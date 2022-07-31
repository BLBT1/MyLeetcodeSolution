class Solution
{
public:
    vector<int> findOrder(int num, vector<vector<int>> &pre)
    {
        vector<int> res;
        vector<int> indegree(num, 0);
        unordered_map<int, vector<int>> mp;
        queue<int> q;

        for (auto p : pre)
        {
            mp[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }

        for (int i = 0; i < num; ++i)
        {
            if (indegree[i] == 0)
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
                indegree[next]--;
                if (indegree[next] == 0)
                {
                    res.push_back(next);
                    q.push(next);
                }
            }
        }

        return (res.size() == num) ? res : vector<int>();
    }
};