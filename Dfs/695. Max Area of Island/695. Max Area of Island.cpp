class Solution
{
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    int res = 0;
    int m = 0;
    int n = 0;

public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        m = grid.size();
        n = grid[0].size();

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    res = max(dfs(grid, i, j), res);
                }
            }
        }
        return res;
    }

    int dfs(vector<vector<int>> &grid, int i, int j)
    {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0)
            return 0;
        grid[i][j] = 0;
        int area = 1;
        for (auto d : dir)
        {
            area += dfs(grid, i + d.first, j + d.second);
        }
        return area;
    }
};

// [[1,1,0,0,0],
//  [1,1,0,0,0],
//  [0,0,0,1,1],
//  [0,0,0,1,1]]