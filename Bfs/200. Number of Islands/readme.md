class Solution {
    vector<pair<int, int>> dir = {{1,0},{-1,0},{0,1}, {0,-1}};
    int m = 0;
    int n = 0;
public:
    int numIslands(vector<vector<char>>& grid)
    {
        m = grid.size();
        n = grid[0].size();
        int cnt = 0;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] == '1')
                {
                    bfs(grid, i , j);
                    cnt++;
                }
            }
        }

        return cnt;
    }
    
    void bfs(vector<vector<char>> &grid, int i , int j)
    {
        queue<pair<int, int>> q;
        grid[i][j] = '0';
        q.push({i, j});
        while(!q.empty())
        {
            auto curr = q.front();
            q.pop();
            for(auto d : dir)
            {
                int x = curr.first + d.first;
                int y = curr.second + d.second;
                if(x >= 0 && y >= 0 && x < m && y < n)
                    if(grid[x][y] == '1')
                    {
                        grid[x][y] = '0';
                        q.push({x,y});
                    }
            }
        }
    }
};
