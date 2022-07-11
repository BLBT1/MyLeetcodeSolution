class Solution
{
    int n = 0;

public:
    int findCircleNum(vector<vector<int>> &isCon)
    {
        // find number of connected component in the graph
        n = isCon.size();
        vector<bool> visited(n, false); // visited[i] => if ith person joined a cycle
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            if (!visited[i])
            {
                res++;
                dfs(isCon, i, visited);
            }
        }

        return res;
    }

    void dfs(vector<vector<int>> &isCon, int curr, vector<bool> &visited)
    {
        if (visited[curr])
            return;
        visited[curr] = true;
        for (int i = 0; i < n; ++i)
        {
            if (isCon[curr][i] && !visited[i])
                dfs(isCon, i, visited);
        }
    }
};