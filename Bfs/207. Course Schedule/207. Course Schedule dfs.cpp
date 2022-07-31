class Solution
{
public:
    bool canFinish(int num, vector<vector<int>> &pre)
    {
        // dfs, 如果我们遇见在当前支线中已经访问过的
        unordered_map<int, vector<int>> mp;
        for (auto p : pre)
        {
            mp[p[1]].push_back(p[0]);
        }

        vector<int> visited(num, 0);
        for (int i = 0; i < num; ++i)
        {
            if (visited[i] != 1)
            {
                bool isCycle = dfs(i, visited, mp);
                if (isCycle)
                    return false;
            }
        }

        return true;
    }

    bool dfs(int i, vector<int> &visited, unordered_map<int, vector<int>> &mp)
    {
        if (visited[i] == 1)
            return false;
        visited[i] = 2;
        for (int next : mp[i])
        {
            if (visited[next] == 2)
                return true;
            if (dfs(next, visited, mp) == true)
                return true;
        }
        visited[i] = 1;

        return false;
    }
};