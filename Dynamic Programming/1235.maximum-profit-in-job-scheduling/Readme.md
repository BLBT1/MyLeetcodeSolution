### interval DP

example problem - 1235.maximum-profit-in-job-scheduling

---
 ----  j
   ------
      ------- i

dp[i] -> by i interval, the most profit we can get. The i are the time of end[i]

for interval i, we could have 2 possible options
    1. take interval i, dp[i] = dp[j]+value[i], where j is the last interval that is not overlapping with interval i
        - we can use binary search to find the j that end[j] is <= start[i]
    2. do not take interval i , dp[i] = dp[i-1]

dp[i] = max(dp[j]+value[i], dp[i-1]);

c++ binary search -> lower_bound(); first >= target
                  -> upper_bound(); first > target

```c++
class Solution {
    static bool comp(vector<int> &j1, vector<int> &j2) {
        return j1[1] < j2[1];
    }

public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        for(int i = 0; i < startTime.size(); ++i)
            jobs.push_back({startTime[i], endTime[i], profit[i]});

        // like the greedy for most number of non-overlapping interval
        // we want to take as much as interval, so sort by the ending point for endTime[i]
        sort(jobs.begin(), jobs.end(), comp);

        int res = 0;
        unordered_map<int, int> dp; //  {by end of interval i -> max profit}
        dp[jobs[0][1]] = jobs[0][2];
        for(int i = 1; i < jobs.size(); ++i) {
            // find last j that is not overlapping with i
            int j = binarySearch(jobs, jobs[i][0]);
            if(j >= 0){
                int curr = max(dp[jobs[i-1][1]], dp[jobs[j][1]]+jobs[i][2]);
                dp[jobs[i][1]] = curr;
            } else {
                int curr = max(dp[jobs[i-1][1]],jobs[i][2]);
                dp[jobs[i][1]] = curr;
            }
        }

        return dp[jobs[jobs.size()-1][1]];
    }

    // find last interval whose end[j] <= target
    int binarySearch (vector<vector<int>> &jobs, int target){
        int l = -1;
        int r = jobs.size();
        while(l < r){
            int mid = l+(r-l)/2+1;
            if (jobs[mid][1] < target){
                l = mid;
            } else if(jobs[mid][1] == target){
                return mid;
            } else {
                r = mid-1;
            }
        }
        return l;
    }
};

// 3
// {3, 4, 5, 6}
//  l 
//      r
//
// if not taking the curr interval i 
// dp[i] = dp[j]+value[i], where j is the last interval that is not overlapping with i
//  or not take the interval i, dp[i] = dp[i-1]
```

