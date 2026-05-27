```c++
class Solution {
    vector<pair<int, int>> dir = {
        {1,0},{0,1},{-1,0}, {0,-1}
    };
    bool res;
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j)
                if(word[0] == board[i][j]){
                    string curr;
                    auto visited = vector<vector<bool>>(m, vector<bool>(n, false));
                    curr.push_back(word[0]);
                    visited[i][j] = true;
                    dfs(board, visited, word, curr, i, j);
                    if(res == true) return true;
                }
        }
        return res;
    }

    void dfs(vector<vector<char>>& board, vector<vector<bool>> &visited, string word, string curr, int x, int y){
        if(word.substr(0, curr.size()) != curr)
            return;

        if(curr == word){
            res = true;
            return;
        }

        if(curr.size() >= word.size())
            return;

        int m = board.size(), n = board[0].size();
        for(auto d: dir){
            int _x = x+d.first;
            int _y = y+d.second;
            if(_x < 0 || _x >= m || _y < 0 || _y >= n)
                continue;
            
            if(!visited[_x][_y]){
                visited[_x][_y] = true;
                curr.push_back(board[_x][_y]);
                dfs(board, visited, word, curr, _x, _y);
                visited[_x][_y] = false;
                curr.pop_back();
            }
        }
    }
};
```