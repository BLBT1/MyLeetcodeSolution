# 456. 132 Pattern

- 假设 132 pattern存在，那假设每个可能的点都是 3 个位置， 那 用greedy的思想， 左边的 1 是左边 最小的， 而右边的2是 右边小于当前element中最大的

We use the mid (the largest point to check), if a 1-3-2 pattern could exist:
- the left one is the smallest one, so for each element, store an array of the smallest element from left
- the right one is less than the mid one, but need to be greater than the left one --> greedy: we need to store the greatest samller element from right

- 而要找到右边小于当前element中最大的，就要用一个单调递减栈, 从右往左， 如图

```
//           |
// |         |
// |         |
// |       | |
// |   |   | |
// | | | | | |
    
    // s decreasing stack 
    //6 3 2 1 5 => the last one to be popped in the stack is 右边小于当前element中最大
```


```c++
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        vector<int> smallestLeft(n, INT_MAX);
        int smallest = INT_MAX;
        for(int i = 0; i < nums.size(); ++i){
            smallestLeft[i] = smallest;
            smallest = min(smallest, nums[i]);
        }

        stack<int> s; // monotonic decreasing order
        vector<int> nextSmaller(n, INT_MIN);
        for(int i = nums.size()-1; i >= 0; --i)
        {
            while(!s.empty() && s.top() < nums[i])
            {
                nextSmaller[i] = s.top();
                s.pop();
            }
            s.push(nums[i]);
        }
        
        for (int i = 1; i < nums.size()-1; ++i){
            if(nextSmaller[i] > smallestLeft[i])
                return true;
        }
        return false;
    }
};


// 4,3,4,2,0
// monotonic decreasing

```