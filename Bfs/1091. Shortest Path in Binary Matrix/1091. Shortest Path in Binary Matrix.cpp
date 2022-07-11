class Solution
{
    vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {-1, -1}, {1, -1}, {-1, 1}, {1, 1}};

public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        // not dijkstra, but the shortest dist between two pts
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        if (grid[0][0] == 1)
            return -1;

        q.push({0, 0});
        grid[0][0] = 2; // 2 is visited
        int step = 0;
        while (!q.empty())
        {
            step++;
            int len = q.size();
            for (int i = 0; i < len; ++i)
            {
                auto curr = q.front();
                q.pop();
                if (curr.first == m - 1 && curr.second == n - 1)
                    return step;

                for (auto &d : dir)
                {
                    int x = curr.first + d.first;
                    int y = curr.second + d.second;
                    if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 0)
                    {
                        grid[x][y] = 2;
                        q.push({x, y});
                    }
                }
            }
        }
        return -1;
    }
};