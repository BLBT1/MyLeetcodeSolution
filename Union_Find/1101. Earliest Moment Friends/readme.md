
```c++
class Solution {
    vector<int> fathers;
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        // sort by timestamps
        sort(logs.begin(), logs.end());

        int count = n;
        fathers = vector(n,0);
        for(int i = 0; i < n; ++i){
            fathers[i] = i; // mark each person as their own father
        }

        for(auto l : logs){
            int x = l[1];
            int y = l[2];

            if(findFather(x) != findFather(y)){
                count -= 1;
                unionSet(x, y);
            }

            if(count == 1)
                return l[0];
        }

        return -1;
    }

    int findFather(int x){
        if(fathers[x] == x)
            return x;
        
        return findFather(fathers[x]);
    }

    void unionSet(int x, int y){
        int xFather = findFather(x);
        int yFather = findFather(y);
        
        fathers[xFather] = yFather;
    }
};

// this problem is like when all disconnected graphes become one

```