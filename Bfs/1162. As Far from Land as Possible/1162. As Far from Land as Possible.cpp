class Solution
{
public:
    int maxDistance(vector<vector<int>> &grid)
    {
        // like rotton orange, find last grid to be rotton
        vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
        int n = grid.size();
        queue<pair<int, int>> q;
        int flag1 = 0;
        int flag2 = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    q.push({i, j});
                    flag1 = 1;
                }
                else
                {
                    flag2 = 1;
                }
            }

        if (flag1 == 0 || flag2 == 0)
            return -1;
        int dist = -1;
        while (!q.empty())
        {
            int len = q.size();
            for (int k = 0; k < len; ++k)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                grid[x][y] = 2;
                for (auto d : dirs)
                {
                    int i = x + d.first;
                    int j = y + d.second;
                    if (i < 0 || i >= n || j < 0 || j >= n)
                        continue;
                    if (grid[i][j] == 1 || grid[i][j] == 2)
                        continue;
                    q.push({i, j});
                    grid[i][j] = 2;
                }
            }
            ++dist;
        }
        return max(dist, 0);
    }
};