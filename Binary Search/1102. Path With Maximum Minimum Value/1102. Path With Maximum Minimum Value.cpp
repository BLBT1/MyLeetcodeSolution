class Solution
{
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

public:
    int maximumMinimumPath(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int mx = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                mx = max(grid[i][j], mx);
        int l = 0;
        int r = mx;
        while (l < r)
        {
            int mid = l + (r - l + 1) / 2;
            if (grid[0][0] >= mid && canWalk(grid, mid))
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }

    // k is the min elt we can walk over
    bool canWalk(vector<vector<int>> &grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        return dfs(grid, 0, 0, k, visited);
    }

    bool dfs(vector<vector<int>> &grid, int x, int y, int k, vector<vector<int>> &visited)
    {
        int m = grid.size();
        int n = grid[0].size();
        if (x == m - 1 && y == n - 1)
            return true;
        visited[x][y] = 1;
        for (auto d : dirs)
        {
            int i = x + d.first;
            int j = y + d.second;
            if (i < 0 || i >= m || j < 0 || j >= n)
                continue;
            if (visited[i][j] == 1)
                continue;
            if (grid[i][j] < k)
                continue;
            bool res = dfs(grid, i, j, k, visited);
            if (res)
                return true;
        }
        return false;
    }
};

// [[0,1,0,0,0,1],
//  [0,1,1,0,0,0],
//  [0,0,1,1,0,1],
//  [0,1,1,1,1,0],
//  [1,1,1,1,1,1]]
