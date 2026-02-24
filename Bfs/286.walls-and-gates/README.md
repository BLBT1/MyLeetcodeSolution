// multi-source bfs, same as rotten orange.
// start by pushing all gates into q at once.
// because start from each gate at the same time, so dist from gate is shared

```cpp
class Solution {
    vector<pair<int, int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};

public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int n = rooms.size();
        int m = rooms[0].size();
        queue<pair<int, int>> q;


        vector<vector<int>> visited(n, vector<int>(m, 0));

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j) {
                if (rooms[i][j] == 0) {
                    q.push({i,j});
                    visited[i][j] = 1;
                }
            }
        }
        
        //1. if a room has been visited previously, because all gates start at the same time, 
        // so dst can be shared.
        int dst = 0;
        while(!q.empty()) {
            int len = q.size();
            for(int i = 0; i < len; ++i){
                auto curr = q.front();
                q.pop();
                
                rooms[curr.first][curr.second] = min(rooms[curr.first][curr.second], dst);
                
                for(auto d: this->directions){
                    int _x = curr.first+d.first;
                    int _y = curr.second+d.second;

                    if(_x >=0 && _x < n && _y >=0 && _y < m 
                        && rooms[_x][_y] != -1 && 
                        visited[_x][_y] != 1) {
                        
                        visited[_x][_y] = 1;
                        q.push({_x, _y});
                    }
                }
            }
            ++dst;
        }
    }
};
```