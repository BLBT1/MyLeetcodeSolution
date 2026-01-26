# 37. Sudoku Solver

1. 从左往右， 从上往下作dfs， 如果row == 9， 说明我们当前的方案成功了， 即可返回 true

2. 来确定 3*3 小方格的位置， 可以用 j/3.3

```c++
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board,0, 0);
    }

    bool dfs(vector<vector<char>> &board, int i, int j){ 
        if(i == 9){
            // all finished
            return true;
        }

        if(j == 9){
            // this row had finished, starting next row
            return dfs(board, i+1, 0);
        }

        if(board[i][j] != '.') {
            return dfs(board, i, j+1); // already has a number, continue
        }
        
        // find next valid number
        for(char val = '1'; val <= '9'; ++val){
            if(isValid(board, i, j, val)){
                board[i][j] = val;
                if(dfs(board, i, j+1)){
                    return true;
                }
                board[i][j] = '.';
            }
        }
        return false;
    }

    // check if curr val is valid for here
    bool isValid(vector<vector<char>> &board, int x, int y, char val){
        for(int i=0; i < 9; ++i){
            if(board[i][y] == val) return false;
        }
        for(int j=0; j < 9; ++j){
            if(board[x][j] == val) return false;
        }

        // 8 -> 6-8 ==> (8/3)*3 ~ ((8/3)+1)*3
        // 
        for(int i = x/3*3; i < (x/3+1)*3; ++i)
            for(int j = y/3*3; j <(y/3+1)*3; ++j)
                if(board[i][j] == val) 
                    return false;

        return true;
    }
};
// for each empty, we can try a number
// check if it is a valid value,
// try next number
```

