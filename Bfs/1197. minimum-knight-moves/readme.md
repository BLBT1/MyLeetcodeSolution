此题的核心是要运用到棋盘的对称性， 无论target在棋盘的哪个方位，我们都可以映射到棋盘的 first quadrant 来搜索。 这样可以省去 3/4 个 棋盘的搜索空间。
注意，
1. 尽管 答案映射在 first quadrant，还是有可能会到 (-2,-2)的位置的， 比如说 (0,0) -> (2, -1) -> (3, 1).
2. 因为可能跳到-2，我们用一个 长度为2 的offset for visited array

```c++
class Solution {
    vector<pair<int, int>> directions = {
        {2, 1}, {1, 2},{-1, 2}, {-2, 1}, {1, -2}, {2, -1}, {-1, -2}, {-2, -1}
    };
    
public:
    int minKnightMoves(int x, int y) {
        x = abs(x), y = abs(y);
        vector<vector<int>> visited(600, vector<int>(600, 0));
        int offset = 2;
        queue<pair<int, int>> q;
        visited[offset][offset] = 1;
        q.push({0,0});
        int steps = 0;
        while(!q.empty()){
            int len = q.size();
            for(int i = 0; i < len; ++i){
                auto curr = q.front();
                if (curr.first == x && curr.second == y)
                    return steps;
                q.pop();
                for(auto d: directions){
                    int next_x = curr.first+d.first;
                    int next_y = curr.second+d.second;
                    // using symetric, we only search in first quad
                    if (next_x < -2 || next_y < -2)
                        continue;
                    if(visited[next_x+offset][next_y+offset] == 1){
                        continue;
                    }
                    visited[next_x+offset][next_y+offset] = 1;
                    q.push({next_x, next_y});
                }
            }
            steps += 1;
        }
        return 0; // should never be here.
    }
};
```