1. find the number of island in the metrix (like lc 200 number of island)
2. mark each island is a id, calculate the size of each island
3. *key step* for each 0 cells, for all unique adjacent island, add on the size (as if flip this 0 cell)

```c++
class Solution {
    vector<pair<int, int>> directions = {{1,0}, {0,1}, {-1, 0}, {0, -1}};
    int n;
public:
    int largestIsland(vector<vector<int>>& grid) {
        this->n = grid.size();
        int id = 2; // starting from 2
        unordered_map<int, int> islandSize;
        for(int i = 0; i < n; ++i){
            for (int j = 0; j < n ; ++j){
                if (grid[i][j] == 1){
                    grid[i][j] = id;
                    int size = dfs(grid, i, j, id);
                    islandSize[id] = size;
                    id += 1;
                }
            }
        }

        int res = 0;
        for(int i = 0; i < n; ++i){
            for (int j = 0; j < n ; ++j){
                if (grid[i][j] == 0){
                    int localRes = 0;
                    // check how many adjacent islands around if and count the max area
                    unordered_set<int> islandSet;
                    for(auto d: directions){
                        int x = i+d.first;
                        int y = j+d.second;
                        if (x < 0 || x >= n || y < 0 || y >= n) continue;
                        
                        // check if the island have been seen
                        if (islandSet.find(grid[x][y]) != islandSet.end()) continue;

                        islandSet.insert(grid[x][y]);
                        localRes += islandSize[grid[x][y]];
                    }
                    res = max(res, localRes+1); // +1 for flip
                }
            }
        }
        
        // check if any single island is larger
        for(auto p: islandSize){
            res = max(p.second, res);
        }
        return res;
    }

    // starting from i, j to find the size of this island
    // also mark the map with color
    int dfs(vector<vector<int>>& grid, int i, int j, int id){
        int localSize = 0;
        for(auto &d: directions) {
            int x = i+d.first;
            int y = j+d.second;
            if (x < 0 || x >= n || y < 0 || y >= n) continue;
            if (grid[x][y] != 1) continue;

            grid[x][y] = id;
            localSize += dfs(grid, x, y, id);
        }
        
        return localSize+1;
    }
};

// what if we have 2 disconnected large island that can be connected by a flip?
// 1. like 200.number-of-island, we can find at most how many union (island)
// 2. mark each union with a different id (like color on map), also remember the size of each island
// 3. check all 0s, whose surrounding has most unique IDs.
```