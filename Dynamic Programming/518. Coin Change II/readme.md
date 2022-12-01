# 518. Coin Change II

// 0-1 knapsack

// dp[i][c] 在用了i种硬币的情况下， amount 为 c 有几种可能

// amount = 14, coins = [1, 2, 5]

// c = 4, [1, 2] => 3

// consider: ```1*5? 2*5?``` ... (amount/coins[i]) * 5

// 这样写为什么不是重复的？ 因为我们某位考虑的都是 k * i, 所以这个是unique的

```cpp
 for i in objs:
     for c in capacity:
         for k in range(1, amount/coins[i]):
             dp[i][c] += dp[i-1][c-k*coins[i]]
```

### 优化

dp[i][c] => dp[i-1][c-k*coins[i]]

but

because dp[c] > dp[c-coins[i],

when we consider dp[c], dp[c-coins[i]] has already been finalized

dp[c] += dp[c-coins[i]]
