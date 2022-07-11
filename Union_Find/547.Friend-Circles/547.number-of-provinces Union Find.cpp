/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 */

// @lc code=start
class Solution
{
    // 各自的爸爸
    unordered_map<int, int> father; // {son i, father of i}
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        //* 此题是 union find 中最经典的应用
        //* 务必多复习

        const int n = isConnected.size();

        // 1. initialze each to be the father of their own
        for (int i = 0; i < n; ++i)
            father[i] = i;

        //2. 遍历 adj matrix 中每个相连关系
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                // if i, j connected
                if (i != j && isConnected[i][j])
                    if (findFather(i) != findFather(j))
                        union2Grps(i, j);
            } //for
        }     //for

        unordered_set<int> ancestors;
        for (int i = 0; i < n; ++i)
        {
            father[i] = findFather(i);
            ancestors.insert(father[i]);
        }

        return ancestors.size();
    }

    //* find the ancestor of x + path compression
    int findFather(int x)
    {
        if (father[x] == x)
            return father[x];

        // 如果我自己不是我自己的祖先
        // 我爸爸祖先就是我的祖先
        // * path compression
        father[x] = findFather(father[x]);
        return father[x];
    }

    //* union two group together via edge(i,j)
    void union2Grps(int i, int j)
    {
        i = findFather(i);
        j = findFather(j);
        if (i <= j)
            father[j] = i;
        else
            father[i] = j;
    }
};
// @lc code=end
