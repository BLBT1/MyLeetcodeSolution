// TIME: 4^(n*m)
// space: n*m
class Solution {
    int m, n;
    int sx, sy; // the pos of start point
    int ex, ey; // the pos of the end point
    vector<vector<int>> grid;
    int canWalk = 1; // num of points that we need to go over, 1 for the start point
    vector<pair<int, int>> dirs ={{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    int uniquePathsIII(vector<vector<int>>& grid) 
    {
        this->m = grid.size();
        this->n = grid[0].size();
        this->grid = grid;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] == 0)
                    canWalk += 1;
                if(grid[i][j] == 1)
                {
                    sx = i;
                    sy = j;
                }
                if(grid[i][j] == 2)
                {
                    ex = i;
                    ey = j;
                }
            }
        }
        return dfs(sx, sy, 0);
    }
    
    // return num of path to the end that visited all walkable points
    int dfs(int x, int y, int visited)
    {
        if(x == ex && y == ey)
        {
            if(visited == canWalk)
                return 1; // this path is valid
            else
                return 0;
        }
        int path = 0; // path from this point
        grid[x][y] = -1;
        for(auto d: dirs)
        {
            int x_ = x + d.first;
            int y_ = y + d.second;
            if(x_ < 0 || x_ >= m || y_ < 0 || y_ >= n)
                continue;
            if(grid[x_][y_] == -1)
                continue;
            path += dfs(x_, y_, visited+1);
        }
        grid[x][y] = 0;
        return path;
    }
};