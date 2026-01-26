# 47. Permutations II

去重： 如果当前数字与前面一个数字相等，那我们像保证当数字和前面数字的组合只出现一次

- 所以如果当前数字已经使用过

- 或者前面数字没使用过， 且当前数字与之相等

这两种情况，当前数字都不能取 (记得要sort下nums先)

```cpp
            if(used[i] || i > 0 && nums[i-1] == nums[i] && !used[i-1])
                continue;
```



```c++
class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> currList;
        vector<int> visited (nums.size(), 0);
        dfs(nums, visited, 0, currList);
        return res;
    }

    void dfs(vector<int> &nums, vector<int> &visited, int curr, vector<int> &currList) {
        if (currList.size() == nums.size()) {
            res.push_back(currList);
            return;
        }

        // what we can add number into selection if
        // 1. curr number has not been used from before
        // 2. curr if curr number is dup, previous dup number had been selected
        for(int i = 0; i < nums.size(); ++i) {
            if(visited[i] == 1) continue;
            if(i > 0 && nums[i] == nums[i-1] 
                && visited[i-1] == 1 // the previous dup has not been selected
            )
                continue;

            visited[i] = 1;
            currList.push_back(nums[i]);
            dfs(nums, visited, curr+1, currList);
            currList.pop_back();
            visited[i] = 0;
        }
    }
};

// permute with duplicate numbers 
// again, only select a duplicated number into currList 
// if and only if the same dup number previous to curr number has been in the currList
```
