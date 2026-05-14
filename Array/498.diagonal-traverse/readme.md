key of this problem is to find the pattern:
    1. when the traversal is going up
or  2. when the traversal is going down


for col+1 -> row+1 -> col+1 
    for (row+1, col+1) or (col-1, row-1) --> need a flag on flipping

isUp = true/false

if isUp
    (row+1, col+1)
    then col+1/row+1 at the end base on if col is at n-1 or row is at m-1

if !isUP
    (row-1, col-1)
    then row+1/col+1 at the end


```c++
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int row = 0, col = 0;
        bool isUp = true;

        vector<int> res;
        while(row >= 0 && col >= 0 && row < m && col < n){
            if(isUp){
                while(row >= 0 && col < n){
                    res.push_back(mat[row][col]);
                    row -= 1;
                    col += 1;
                }
                row+=1, col-=1;

                // check which side to increase
                if(col == n-1)
                    row+=1;
                else
                    col+=1;
            } else {
                while(row < m && col >= 0){
                    res.push_back(mat[row][col]);
                    row += 1;
                    col -= 1;
                }
                row-=1, col+=1;
                if(row == m-1)
                    col+=1;
                else
                    row+=1;
            }

            isUp = !isUp;
        }

        return res;
    }
};

// for col+1 -> row+1 -> col+1 
//     for (row+1, col+1) or (col-1, row-1) --> need a flag on flipping

// isUp = true/false

// if isUp
//     (row+1, col+1)
//     then col+1 at the end

// if !isUP
//     (row-1, col-1)
//     then row+1 at the end

```