/*
 * @lc app=leetcode id=778 lang=cpp
 *
 * [778] Swim in Rising Water
 */

// @lc code=start
using VI = vector<int>;
class Solution
{
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    int swimInWater(vector<vector<int>> &grid)
    {
        const int n = grid.size();
        int res = 0;

        priority_queue<VI, vector<VI>, greater<>> pq;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        pq.push({grid[0][0], 0, 0});

        while (!pq.empty())
        {

            int h = pq.top()[0];
            int x = pq.top()[1];
            int y = pq.top()[2];
            res = max(res, h);
            pq.pop();

            if (visited[x][y])
                continue;
            visited[x][y] = 1;

            if (x == n - 1 && y == n - 1)
                return res;

            for (int k = 0; k < 4; k++)
            {
                int xx = x + dirs[k].first;
                int yy = y + dirs[k].second;
                if (xx < 0 || xx >= n || yy < 0 || yy >= n)
                    continue;
                if (visited[xx][yy] == 1)
                    continue;
                pq.push({grid[xx][yy], xx, yy});
            }
        } //while

        return -1;
    }
};
// @lc code=end
