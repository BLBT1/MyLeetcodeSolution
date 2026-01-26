# 46. Permutations

- permutation 可以确定的是list的长度肯定要是 nums 的长度， 所以这是 base case

- 此外，每个数字都要出现在任何位置， 所以 dfs 中 的 for loop 要从 0 开始

- 每个数字在list中只能出现一次， 所以要用个 set来记录是不是有用过当前的数字

- time: O(N!), space: O(N)


example walk through -
[1,2,3]
 
in () is number options to select

(1,2,3) - 1 (2,3) - 2 (3) - 3 [1,2,3]
                  - 3 (2) - 2 [1,3,2]
        - 2 (1,3) - 1 (3) - 3 [2,1,3]
                  - 3 (1) - 1 [2,3,1]
        - 3 (1,2) - 1 (2) - 2 [3,1,2]
                  - 2 (1) - 1 [3,2,1]

How do we know () from code? 
- we define a vector of visited(0) and start from index of 0, visited has not been marked to 1, we can select it

Algorithm

each recursion we do: 

1. if curr == nums.size()-1, base case, push to res.
2. select from avaiable numbers (numbers that not been visited)
3. make selection (mark number as visited, add number to currList)
4. dfs(curr+1)
5. revert selection (mark number unvisited, pop number from currList)

```c++
class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> currList;
        vector<int> visited(nums.size(), 0);
        dfs(nums, visited, 0, currList);
        return res;
    }

    void dfs(vector<int> &nums, vector<int> &visited, int curr, vector<int> &currList) {
        // base case
        if (curr == nums.size()) res.push_back(currList);

        // make selection
        for(int i = 0; i < nums.size(); ++i) {
            if (visited[i]) continue;
            
            visited[i]=1;
            currList.push_back(nums[i]);
            dfs(nums, visited, curr+1, currList);
            visited[i]=0;
            currList.pop_back();
        }
    }
};
```

