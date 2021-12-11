/*
 * @lc app=leetcode id=1284 lang=cpp
 *
 * [1284] Minimum Number of Flips to Convert Binary Matrix to Zero Matrix
 */

// @lc code=start
class Solution
{
    int m, n;

public:
    int minFlips(vector<vector<int>> &mat)
    {
        m = mat.size();
        n = mat[0].size();
        int res = INT_MAX;

        for (int state = 0; state < (1 << (m * n)); state++)
        {
            if (check(mat, state))
                res = min(res, (int)bitset<9>(state).count());
        }
        if (res == INT_MAX)
            return -1;
        else
            return res;
    }

    bool check(vector<vector<int>> &mat, int state)
    {
        auto temp = mat;
        auto dir = vector<pair<int, int>>({{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {0, 0}});

        for (int s = 0; s < (m * n); s++)
        {
            int t = state % 2;
            state /= 2;
            if (t == 0)
                continue;

            int i = s / n;
            int j = s % n;

            for (int k = 0; k < 5; k++)
            {
                int x = i + dir[k].first;
                int y = j + dir[k].second;
                if (x < 0 || x >= m || y < 0 || y >= n)
                    continue;
                temp[x][y] = 1 - temp[x][y];
            }
        }

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (temp[i][j] != 0)
                    return false;
        return true;
    }
};
// @lc code=end
