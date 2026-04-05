因为要确保整个metric和target相同， 所以要整个metric一起翻转

rotation formula
```
// new_x = y
// new_y = n-x-1
```

```c++
class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        bool canGet = checkEqualMat(mat, target);
        if (canGet) return true;
        for(int i = 0 ; i < 3; ++i) {
            mat = rotateOnce(mat);
            canGet = checkEqualMat(mat, target);
            if(canGet) return true;
        }
        return false;
    }

    vector<vector<int>> rotateOnce(vector<vector<int>> &mat){
        int n = mat.size();
        vector<vector<int>> res(n, vector<int>(n, 0));
        for (int x = 0; x < n; ++x){
            for(int y = 0; y < n; ++y){
                int new_x = y, new_y = n-x-1;
                res[new_x][new_y] = mat[x][y];
            }
        }
        return res;
    }

    bool checkEqualMat(vector<vector<int>>& mat, vector<vector<int>>& target){
        int n = mat.size();
        for (int x = 0; x < n; ++x){
            for(int y = 0; y < n; ++y){
                if(mat[x][y] != target[x][y])
                    return false;
            }   
        }
        return true;
    }  
};

// [0,0] -> [0, n-1]
// [0,n-1] -> [n-1, 0]
// [1,2] -> [2,1]
// [0, 1] -> [1, n-1]
// [1, 0] -> [0, 1]

// new_x = y
// new_y = n-x-1
```