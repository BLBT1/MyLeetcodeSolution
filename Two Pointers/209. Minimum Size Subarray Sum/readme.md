# 209. Minimum Size Subarray Sum

- 最经典的滑动窗口

- 右指针整体移动，左指针伺机而动


```c++
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int l = 0;
        int curr_len = INT_MAX;
        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            
            while (sum >= target) {
                if(i-l+1 < curr_len){
                    curr_len = i-l+1;
                }
                sum -= nums[l];
                ++l;
            }
        }     
        if (curr_len == INT_MAX) 
            return 0;

        return curr_len;
    }
};

// curr_sum = 8;
// // [2,3,1,2,4,3] 7
//       l
//                r
```