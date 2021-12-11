/*
 * @lc app=leetcode id=407 lang=cpp
 *
 * [407] Trapping Rain Water II
 */

// @lc code=start
using VI = vector<int>;
class Solution
{
    vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

public:
    int trapRainWater(vector<vector<int>> &heightMap)
    {
        const int m = heightMap.size();
        const int n = heightMap[0].size();
        //用 Dijktra 想成海水从四周溢进来
        priority_queue<VI, vector<VI>, greater<>> pq; // min heap
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int res = 0;

        // add 4 borders
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1)
                {
                    pq.push({heightMap[i][j], i, j});
                    visited[i][j] = true;
                }
            } //for
        }     //for

        int curr = INT_MIN;
        while (!pq.empty())
        {
            int h = pq.top()[0];
            int x = pq.top()[1];
            int y = pq.top()[2];
            pq.pop();

            if (h > curr)
                curr = h;
            res += curr - h;
            for (int k = 0; k < 4; k++)
            {
                int i = x + dirs[k].first;
                int j = y + dirs[k].second;
                if (i < 0 || i >= m || j < 0 || j >= n)
                    continue;
                if (visited[i][j])
                    continue;
                visited[i][j] = 1;
                pq.push({heightMap[i][j], i, j});
            }
        }

        return res;
    }
};
// @lc code=end
