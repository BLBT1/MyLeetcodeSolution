/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution
{
    vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

public:
    int numIslands(vector<vector<char>> &grid)
    {
        // either bfs ad dfs works
        // this is the bfs solution

        const int m = grid.size();
        if (m == 0)
            return 0;
        const int n = grid[0].size();

        int count = 0;

        // find the next 1
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == '1')
                {
                    count += 1;

                    //do bfs here
                    queue<pair<int, int>> q; //{pos}
                    q.push({i, j});
                    grid[i][j] = '#';

                    while (!q.empty())
                    {
                        auto [curr_x, curr_y] = q.front();
                        q.pop();

                        for (auto &dir : dirs)
                        {
                            int n_x = curr_x + dir.first;
                            int n_y = curr_y + dir.second;

                            if (n_x < 0 || n_y < 0 || n_x >= m || n_y >= n)
                                continue;

                            if (grid[n_x][n_y] != '1')
                                continue;

                            q.push({n_x, n_y});
                            grid[n_x][n_y] = '#';
                        } //for
                    }     //while
                }
            } //for
        }     //for

        return count;
    }
};
// @lc code=end
