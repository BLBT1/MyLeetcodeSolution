# 325. Maximum Size Subarray Sum Equals k

这个题有点像 前缀和 与 2 ptr 的结合

看例子：

```cpp

nums = [1,-1,5,-2,3], k = 3

在头上加一个0之后

// idx   -1 0  1  2  3  4
presum: [0, 1, 0, 5, 3, 6]

```

那如果我们能在 mp 里找到 一个 x， 而且 x + k = presum[i]， 那假设 x 对应的位置为 j， 那当前的长度就是 i-j

同时，因为我们要找到最长的长度，所以我们 j 要越靠前越好，我们用map<int, vector<int>>, 每次就和 mp[nums[i]-k][0] 对比
