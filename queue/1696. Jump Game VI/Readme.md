dp[i] --> the most score we can get at i
dp[i] = for { max(dp[i-1 ... i-k] + dp[i], dp[i-1 ... i-k]) }
O(NK)

optimizing
notice
for dp[i] , we check max{dp[i-k], dp[i-k+1], dp[i-k+2] ... dp[i-1]}
for dp[i+1], we check max{dp[i-k+1], dp[i-k+2] ... dp[i-1], dp[i]}

`dp[i-k+1], dp[i-k+2] ... dp[i-1]` max had been duplicated for checking
what we care is the max from the range ==> sliding window maximun problem (monotonic queue)

==> monotonic decreasing queue (why decreasing?)
dp [8, 5, 4,], if dp[i] = 6, 
because dp[i] is after {5}, and {4} in the dp, and is greater
so for all future windows, {5}, {4} don't need to be considered


```c++
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        vector<int> dp(nums.size(), 0);
        // dp[0] = nums[0];
        deque<int> q; // monotonic decreasing
        for(int i = 0; i < nums.size(); ++i){            
            if(!q.empty() && q.front() < i-k){
                q.pop_front();
            }
            
            if(!q.empty())
                dp[i] = dp[q.front()] + nums[i];
            else
                dp[i] = nums[i];
            
            // update deque last, otherwise dp had not been updated
            while(!q.empty() && dp[q.back()] < dp[i]){
                q.pop_back();
            }

            q.push_back(i);
        }

        return dp.back();
    }
};

// dp[i] --> the most score we can get at i
// dp[i] = for { max(dp[i-1 ... i-k] + dp[i], dp[i-1 ... i-k]) }
// O(NK)

// optimizing
// notice
// for dp[i] , we check max{dp[i-k], dp[i-k+1], dp[i-k+2] ... dp[i-1]}
// for dp[i+1], we check max{dp[i-k+1], dp[i-k+2] ... dp[i-1], dp[i]}

// `dp[i-k+1], dp[i-k+2] ... dp[i-1]` max had been duplicated for checking
// what we care is the max from the range ==> sliding window maximun problem (monotonic queue)

// ==> monotonic decreasing queue (why decreasing?)
// dp [8, 5, 4,], if dp[i] = 6, 
// because dp[i] is after {5}, and {4} in the dp, and is greater
// so for all future windows, {5}, {4} don't need to be considered
```

