/*
 * @lc app=leetcode id=684 lang=cpp
 *
 * [684] Redundant Connection
 */

// @lc code=start
class Solution
{
    unordered_map<int, int> father;

public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        const int n = edges.size();

        for (int i = 0; i < n; ++i)
        {
            father[i + 1] = i + 1;
        }

        for (int i = 0; i < n; ++i)
        {
            auto &e = edges[i];
            if (findFather(e[0]) != findFather(e[1]))
            {
                unionfy(e[0], e[1]);
            }
            else
            {
                return e;
            }
        }
        return {0, 0};
    }

    int findFather(int x)
    {
        if (x != father[x])
            father[x] = findFather(father[x]);

        return father[x];
    }

    void unionfy(int i, int j)
    {
        int x = findFather(i);
        int y = findFather(j);
        father[x] = y;
    }
};
// @lc code=end
