```c++
 class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> q;
        for (int i =0; i < nums.size(); ++i){
            while (!q.empty() && nums[i]> nums[q.back()]){
                q.pop_back();
            }

            q.push_back(i);
            
            // pop elements that are too old
            if(!q.empty() && q.front() <= i-k)
                q.pop_front();
            
            if(i-k+1 >= 0)  
                res.push_back(nums[q.front()]);
        }

        return res;
    }
};



// we only care about the max from windows
// 5 will be the largest element for future k windows
// but if we have a 3 after 5, we do care about the 3 because 5 might be pop after sometime
/// 1,3,[-1,-3,5,3]..

//1. mantain a monotonic decreasing queue
//2. push the curr element, pop old elements out of window
//3. use the front() as the max elements
//4. we want to store the idx of nums, otherwise, we don't know if the element had been out of window

```