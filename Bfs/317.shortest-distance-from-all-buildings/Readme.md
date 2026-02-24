- If we want to find sum of distance to each building, we cannot do better than do bfs from each building then sum up each distance
- If we want to find shortest distance to any building, we can pushing all the buildings into queue at once

```c++
// Time : O(M*N*M*N)
class Solution {
    vector<pair<int, int>> directions = {{1,0}, {0,1}, {-1,0},{0,-1}};
    int m, n;
public:
    int shortestDistance(vector<vector<int>>& grid) {
        this->m = grid.size();
        this->n = grid[0].size();
        // -1 means starting some building cannot reach the cell
        vector<vector<long>> totalDist(m, vector<long>(n, 0L));

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if (grid[i][j] == 1) {
                    auto dist = bfs(grid, i, j);
                    accumulateDist(grid, totalDist, dist);
                }
            }
        }

        long res = INT_MAX;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if (grid[i][j] == 0) {
                    res = min(res, totalDist[i][j]);
                }
            }
        }
        
        if (res == INT_MAX) return -1;
        return res;
    }

    // we will get a map of the shortest dist starting from i, j
    // if we cannot reach from i,j, the map will have dist of INT_MAX 
    vector<vector<int>> bfs(vector<vector<int>>& grid, int i, int j){
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        vector<vector<int>> visited(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        q.push({i,j});
        int steps = 0;
        while (!q.empty()){
            int len = q.size();
            for (int i = 0; i < len; ++i){
                auto curr = q.front();
                q.pop();
                dist[curr.first][curr.second] = steps;

                for(auto &d: directions) {
                    int x = curr.first+d.first;
                    int y = curr.second+d.second;
                    if (x >= 0 && x < m && y >= 0 && y < n 
                        && grid[x][y] == 0 && visited[x][y] == 0){
                            visited[x][y] = 1;
                            q.push({x,y});
                        }
                }
            }
            steps += 1;
        }
        
        return dist;
    }

    void accumulateDist(vector<vector<int>>& grid, vector<vector<long>>& totalDist, vector<vector<int>>& d) {
        for(int i =0; i < m; ++i)
            for(int j =0; j < n; ++j)
                if (grid[i][j] == 0) {
                    totalDist[i][j] += d[i][j];
                }
    }
};

// we can find shortest distance to any building
// we can do bfs from each node, then record the sum for each 0 cell
// mark distance for each 0 cell

```
