# 516. Longest Palindromic Subsequence

典型的区间型dp: 大区简的最优，取决于小区间的最优。定义：dp[i][j] <- longest palindromic subsequence of s[i:j]
### 状态转移方程
注意：
- 如果 s[i] == s[j], 那 dp[i][j] = dp[i+1][j-1]+2 这一步是很好想到的
- 如果 s[i] != s[j]，很多人会直觉 dp[i][j] = dp[i+1][j-1]。但是这是错的！！！ 因为如果 s[i] != s[j]，s[i] 和 s[j] 两个中必然有一个不是最长回文子序列的成员（否则如果这两个都是的话，会造成最长回文子序列的两端不对称），于是我们就可以排除一个。所以 dp[i][j] = max(dp[i][j-1],dp[i+1][j]

```
        example:s = "b b b a b"
                    0 1 2 3 4
        这里 dp[1][3] = max(dp[1][2], dp[2][3]) = dp[1][2] = 2
```
所以状态转移方程就是
```cpp
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    // missed this
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
```

返回整个s的longest palindromic subsequence, return dp[0][n-1]
