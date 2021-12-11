/*
 * @lc app=leetcode id=797 lang=cpp
 *
 * [797] All Paths From Source to Target
 */

// @lc code=start
class Solution
{
    vector<vector<int>> res;
    int n = 0;

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        this->n = graph.size();
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < graph[i].size(); ++j)
            {
                adj[i].push_back(graph[i][j]);
            }
        }

        vector<int> currList;
        currList.push_back(0);
        dfs(0, currList, adj);
        return res;
    }

    void dfs(int curr, vector<int> &currList,
             unordered_map<int, vector<int>> &adj)
    {
        if (curr == n - 1)
        {
            res.push_back(currList);
        }

        for (auto v2 : adj[curr])
        {
            currList.push_back(v2);
            dfs(v2, currList, adj);
            currList.pop_back();
        }
    }
};
// @lc code=end
