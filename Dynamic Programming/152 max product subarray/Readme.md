# 152. Maximum Product Subarray

此题是 lc53 的变形，但是是product 而非 sum。 所以这里nums[i] 的符号就很关键了。

### 核心思想：

我们定义：
```cpp
        // dp[i] <- 以i为结尾的 max subarray product
        const int n = nums.size();
        vector<int> maxP(n);
```

1 . 如果 nums[i] 是个非负数，则 maxP = max(nums[i] * maxP[i], nums[i]);  这个和 lc53 是很类似的

2 . 如果 nums[i] 是个负数怎么办？这是此题的难点！ 作为一个负数， 其实要找到的是以 i-1 为结尾的 min subarray product， 再与之相乘！

举个栗子，
```
        nums [1, -1, -2]
              0   1   2
```
那当我们设置有边界 i = 2 时：
- i-1 的 max subarray product 是 1 
- i-1 的 min subarray product 是 -1

此时， i 结尾的max subarray product 则为 -2 * -1 = 2

所以，这种情况下， maxP = max(nums[i] * min subarray product(i), nums[i]); 那min subarray product怎么找呢? 我们需要维护另一个dp 记录！
```cpp
        vector<int> minP(n);
```

综上，此题的状态转移方程是：

```cpp
        maxP[i] = max(max(maxP[i - 1] * nums[i], minP[i - 1] * nums[i]), nums[i]);
```
且每一步都需要更新：
```cpp
        minP[i] = min(min(maxP[i - 1] * nums[i], minP[i - 1] * nums[i]), nums[i]);
```

以上就是此题的核心，还是很难的，需要细细品味一下！