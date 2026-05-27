滑动窗口 - 右指针尽量移动，左指针伺机而动

[XXXXXXX]XXXXXX 
i
      j

核心难点就是在i，j窗口中如何快速的找出其中最大和最小差

Solution#1 - multiset (set that is sorted but allowed duplications)

Time - O(NlogN)

multiset的优点是能用 O(logN) 的时间移除最 nums[i] 的元素, 而且是可以同时找到最大和最小的。 这些事pq最不到的

```c++
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        multiset<int> ms;
        ms.insert(nums[0]);
        int i = 0; // 
        int j = 0; // right of the window
        int res = INT_MIN;
        for(;i < n; ++i){

            while(!ms.empty() && *ms.rbegin() - *ms.begin() <= limit){
                // only the element that is in the multiset is valid, 
                // j now is pointing to the last valid pos
                res = max(res, j-i+1);                
                
                ++j;                

                if (j>=nums.size()) break;
                ms.insert(nums[j]);
            }

            ms.erase(ms.find(nums[i]));
        }

        return res;
    }
};

// //
// [8, 2, 4, 7]
//  i
//     j
```

solution #2 单调队列 （利用 deque）

类似于 239，这里我们可同时维护最大队列和最小队列 这样可以用 O(1)时间找到最大和最小

```c++
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        deque<int> max_q; // front is max -> monotonic decreasing
        deque<int> min_q; // front is min -> monotonic increasing
        max_q.push_back(0);
        min_q.push_back(0);
        
        int i = 0; // 
        int j = 0; // right of the window
        int res = INT_MIN;
        
        for(;i < n; ++i){

            while(nums[max_q.front()] - nums[min_q.front()] <= limit){
                
                // only the element that is in the multiset is valid, 
                // j now is pointing to the last valid pos
                res = max(res, j-i+1);                
                ++j;                
                if (j>=nums.size()) break;

                // update max_q and min_q with new j
                while(!max_q.empty() && nums[max_q.back()] < nums[j]){
                    max_q.pop_back();
                }
                max_q.push_back(j);

                while(!min_q.empty() && nums[min_q.back()] > nums[j]){
                    min_q.pop_back();
                }
                min_q.push_back(j);
            }

            // pop out the elt that is out bound, should be i
            if(!max_q.empty() && max_q.front() <= i)
                max_q.pop_front();
            if(!min_q.empty() && min_q.front() <= i)
                min_q.pop_front();
        }

        return res;
    }
};

// //
// [8, 2, 4, 7]
//  i
//     j
```
