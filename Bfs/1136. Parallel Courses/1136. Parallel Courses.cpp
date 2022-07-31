class Solution
{
public:
    int minimumSemesters(int n, vector<vector<int>> &relations)
    {
        unordered_map<int, vector<int>> mp;
        vector<int> indeg(n + 1, 0);
        for (auto rel : relations)
        {
            mp[rel[0]].push_back(rel[1]);
            indeg[rel[1]]++;
        }

        queue<int> q;
        int cnt = 0;
        int res = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (indeg[i] == 0)
            {
                q.push(i);
                cnt++;
            }
        }

        while (!q.empty())
        {
            int len = q.size();
            for (int i = 0; i < len; ++i)
            {
                auto curr = q.front();
                q.pop();
                for (auto next : mp[curr])
                {
                    indeg[next]--;
                    if (indeg[next] == 0)
                    {
                        cnt++;
                        q.push(next);
                    }
                }
            }
            ++res;
        }

        return cnt == n ? res : -1;
    }
};