/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */

// @lc code=start
class Solution
{
    int m = 0;
    int n = 0;
    //bool anyFresh = false;
    int time = 0;
    int numFresh = 0;
    vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        this->m = grid.size();
        this->n = grid[0].size();
        queue<pair<int, int>> q;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                // 0-> empty
                // 1-> fresh
                // 2->rotton
                // 3-> visited
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
                else if (grid[i][j] == 1)
                    numFresh++;
            } //for
        }     //for

        while (!q.empty() && numFresh > 0)
        {
            //bool rotton = false;
            int len = q.size();
            for (int i = 0; i < len; ++i)
            {
                auto [curr_x, curr_y] = q.front();
                q.pop();

                for (auto &dir : dirs)
                {
                    int n_x = curr_x + dir.first;
                    int n_y = curr_y + dir.second;
                    if (n_x >= m || n_x < 0 || n_y < 0 || n_y >= n)
                        continue;
                    if (grid[n_x][n_y] == 1)
                    {
                        //rotton = true;
                        grid[n_x][n_y] = 3;
                        q.push({n_x, n_y});
                        numFresh--;
                    }
                } //for
            }     //for
            time++;
        } //while

        if (numFresh > 0)
            return -1;

        return this->time;
    }
};
// @lc code=end
