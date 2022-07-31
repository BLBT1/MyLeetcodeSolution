class Solution
{
    int n, k;
    vector<vector<int>> res;
    vector<int> list;

public:
    vector<vector<int>> combine(int n, int k)
    {
        this->n = n, this->k = k;
        vector<bool> visited(n + 1, false);
        dfs(1, visited);
        return res;
    }

    void dfs(int curr, vector<bool> &visited)
    {
        if (list.size() == k)
        {
            res.push_back(list);
            return;
        }
        for (int i = curr; i < n + 1; ++i)
        {
            if (visited[i])
                continue;
            visited[i] = true;
            list.push_back(i);
            dfs(i + 1, visited);
            visited[i] = false;
            list.pop_back();
        }
    }
};