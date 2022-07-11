class Solution
{
    vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

public:
    int shortestPath(vector<vector<int>> &grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(m * n, false)));
        queue<vector<int>> q; // {i, j, used}
        q.push({0, 0, 0});
        int step = 0;
        while (!q.empty())
        {
            int len = q.size();
            for (int w = 0; w < len; ++w)
            {
                auto i = q.front()[0];
                auto j = q.front()[1];
                auto used = q.front()[2];
                q.pop();
                if (i == m - 1 && j == n - 1)
                {
                    return step;
                }

                for (auto d : dir)
                {
                    int x = i + d.first;
                    int y = j + d.second;

                    if (x < 0 || y < 0 || x >= m || y >= n)
                        continue;

                    if (grid[x][y] == 1)
                    {
                        if (used < k && visited[x][y][used + 1] == false)
                        {
                            visited[x][y][used + 1] = true;
                            q.push({x, y, used + 1});
                        }
                    }
                    else
                    {
                        if (visited[x][y][used] == false)
                        {
                            visited[x][y][used] = true;
                            q.push({x, y, used});
                        }
                    }
                }
            }
            step++;
        }
        return -1;
    }
};