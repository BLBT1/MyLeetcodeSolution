# 53.Maximum Subarray

尽管这题lc上标注的是easy，但是对于第一次见到此题的小伙伴而言，自己想出来还是很困难的。此题的算法是 ```Kadane's Algorithm```

### Kadane's algorithm

核心思想是“固定有边界，探索左边界”。也就是说， 我们考虑每个以i结尾的max subarry 子问题。

所以我们定义：
```cpp
        // dp[i] <- 以i为结尾的 max subarray
        const int n = nums.size();
        vector<int> dp(n);
```

而此题的 result 就是遍历所有dp中可能的i：
```py
        //伪代码
        res = max{dp[i]}, where i = 1,2,3 ... ,n-1 
```

现在我要讨论的是他的状态转移方程，也是此题的难点。有两种情况:

1 . dp[i-1] 为正，则 nums[i] 可以直接与 dp[i-1] 求和，得到max subarray sum


2 . dp[i-1] 为负数，则 这种情况，前面的subarray反而是累赘，max subarray sum直接是 nums[i]  

dp[i] 是上面两种情况中取最大的
```cpp
        dp[i] = max(dp[i-1] + nums[i], nums[i]);
```
