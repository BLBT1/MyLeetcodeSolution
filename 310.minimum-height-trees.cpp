/*
 * @lc app=leetcode id=310 lang=cpp
 *
 * [310] Minimum Height Trees
 */

// @lc code=start
class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        // 类似于拓扑排序的做法
        // 选叶子节点， 从外网里面拨洋葱

        if (n == 1)
            return {0};
        if (n == 2)
            return {0, 1};

        vector<int> res;
        // adj list and 出度
        unordered_map<int, int> Degree;
        unordered_map<int, vector<int>> Up;
        for (auto &edge : edges)
        {
            Degree[edge[0]]++;
            Degree[edge[1]]++;
            Up[edge[1]].push_back(edge[0]);
            Up[edge[0]].push_back(edge[1]);
        }

        queue<int> q;
        for (auto &a : Degree)
            if (a.second == 1)
                q.push(a.first);

        int count = 0;
        while (!q.empty())
        {
            int k = q.size();
            for (int i = 0; i < k; i++)
            {
                int node = q.front();
                q.pop();
                count++;

                for (auto upNode : Up[node])
                {
                    Degree[upNode]--;
                    if (Degree[upNode] == 1)
                        q.push(upNode);
                }
            }

            if (count + q.size() == n)
            {
                while (!q.empty())
                {
                    res.push_back(q.front());
                    q.pop();
                }
                return res;
            }
        }
        return res;
    }
};
// @lc code=end
