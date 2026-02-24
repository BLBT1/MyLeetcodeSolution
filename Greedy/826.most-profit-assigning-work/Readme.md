1. brute force, we want to first to first most profit job - O(J*W + JlogJ)

```c++
class Solution {

public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        vector<vector<int>> works; // {profit, difficulty}
        for(int i = 0; i < n; ++i){
            works.push_back({profit[i],difficulty[i]});
        }
        sort(works.begin(), works.end(), greater());

        int res = 0;
        for(int i = 0; i < worker.size(); ++i){
            for(int j = 0; j < n; ++j){
                if (works[j][1] <= worker[i]){
                    res += works[j][0];
                    break;
                }
            }
        }

        return res;
    }
};
// sort + greedy
// O(J*W + JlogJ)
```

2. two pointer + greedy
sort worker, sort jobs by difficulty
for all jobs what the worker can do so far, maintain the max profit - O(JlogJ + WlogW)

```c++
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        int m = worker.size();
        vector<vector<int>> works; // {difficulty -> profit}
        for(int i = 0; i < n; ++i){
            works.push_back({difficulty[i], profit[i]});
        }
        sort(works.begin(), works.end());
        sort(worker.begin(), worker.end());

        int res = 0;
        int currMax = 0;
        int i = 0; // for works
        int j = 0; // for worker 
        int k = -1; // last checkpoint for worker
        while (i < n && j < m){
            if(worker[j] >= works[i][0]){
                currMax = max(currMax, works[i][1]);
                i++;
            } else {
                res += (j-k) * currMax;
                k = j;
                ++j;
            }
        }

        if (i == n){
            res += (m-j)*currMax;
        }
        return res;
    }
};
```