
### Greedy
Because we are returning number of elements for sequence, so the order doesn't really matter. 
Because we want longest subsequence, so that is the largest number of elements, so we sort from smaller to larger
upper_bound to find strictly greater element j, and number of element is j-presum.begin()

```c++
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end()); // greedy -> because we want the longest, so start from small
        vector<int> presum(nums.size(), 0);
        presum[0] = nums[0];
        for(int i =1; i < nums.size(); ++i){
            presum[i] = nums[i]+presum[i-1];
        }

        vector<int> res;
        for(int i = 0; i < queries.size(); ++i){
            auto itr = upper_bound(presum.begin(), presum.end(), queries[i]);
            res.push_back(itr-presum.begin());
        }
        return res;
    }
};
```