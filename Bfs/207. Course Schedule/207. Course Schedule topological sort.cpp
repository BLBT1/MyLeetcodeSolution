class Solution
{
public:
    bool canFinish(int num, vector<vector<int>> &pre)
    {
        unordered_map<int, vector<int>> mp;
        vector<int> indegree(num, 0);
        for (auto p : pre)
        {
            mp[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }

        int cnt = 0;
        queue<int> q;
        for (int i = 0; i < num; ++i)
        {
            if (indegree[i] == 0)
            {
                indegree[i] = -1;
                q.push(i);
                cnt++;
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
                    indegree[next] = -1;
                    q.push(next);
                    cnt++;
                }
            }
        }

        return cnt == num;
    }
};