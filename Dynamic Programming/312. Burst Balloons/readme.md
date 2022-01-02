# 312. Burst Balloons


### 区间型dp ii 基本套路

- define dp[i][j]: 对 [i,j] 区间的子问题求解
- 将大区间 dp[i][j] 往小区间 dp[i'][j'] 进行转移
- ```第一层loop是区间大小```
- ```第二层loop是起始点 i```
- ans = dp[1][n]


### 此题使用套路
此题的突破口是要想到：消除所有元素的话,肯定有最后一枪k， 那么在打灭k之前,一定已经打灭了[i,k-1]和[k+1,j]，这两部分的得分可以提前算出来。所以在一个给定[i,j]区间里，找到此区间的最大得分需要遍历区间里所有可能的k：

```cpp
     for (int len = 1; len <= n; len++)
            for (int i = 1; i + len - 1 <= n; i++)
            {
                int j = i + len - 1;
                for (int k = i; k <= j; k++) // pick the position of the last burst balloon
                // more code here
            }
```
假设最后一个打的气球是k， 那当前的分数是什么呢？应该是nums[i-1]*nums[k]*nums[j+1],即涉及到[i,j]两端外的这两个元素。所以在一个给定[i,j]区间里，找到此区间最后打气球为k的总得分是：
```cpp
    dp[i][j] = max(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + nums[i - 1] * nums[k] * nums[j + 1]);
```

### 最后注意
设 n 是初始nums的大小。此题的区间最小长度可以是1，而此时的区间只剩下单独一个k，而界外的点是nums[i - 1]，nums[j + 1]。 因为已经提前加入两个1在nums的头尾，如果 i = 1，那 区间是 {1，nums[1], nums[2]}。 而 i 的最大值可以达到 n，（nums 的 最后一个element 是 nums[n+1]）, 区间是 {nums[n-1]，nums[n], 1}。所以都成立。

