/*
 * @lc app=leetcode id=1905 lang=cpp
 *
 * [1905] Count Sub Islands
 */

// @lc code=start
class Solution
{
    int res = 0;
    int m = 0;
    int n = 0;

    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

public:
    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        //* 这道题的难点是： 即便遇到了点在grid1中不为 1，我们也要把grid2的岛走完，不然会重复计算
        // find the first 1 int grid2
        this->m = grid2.size();
        this->n = grid2[0].size();

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid2[i][j] == 1)
                    bfs(i, j, grid1, grid2);
            } //for
        }     // for

        return res;
    }

    void bfs(int i, int j, vector<vector<int>> &grid1,
             vector<vector<int>> &grid2)
    {
        queue<pair<int, int>> q;
        grid2[i][j] = -1;
        q.push({i, j});
        bool flag = grid1[i][j] == 1;
        while (!q.empty())
        {
            int curr_x = q.front().first;
            int curr_y = q.front().second;
            q.pop();

            for (auto &dir : dirs)
            {
                int next_x = curr_x + dir.first;
                int next_y = curr_y + dir.second;
                if (next_x < 0 || next_y < 0 || next_x >= m || next_y >= n)
                    continue;
                if (grid2[next_x][next_y] == -1)
                    continue;
                if (grid2[next_x][next_y] == 1)
                {
                    if (grid1[next_x][next_y] != 1)
                    {
                        flag = false;
                    }
                    grid2[next_x][next_y] = -1;
                    q.push({next_x, next_y});
                }
            } //for
        }     //while
        if (flag)
            res++;
    }
};
// @lc code=end
//
// bfs to find islands in grid2