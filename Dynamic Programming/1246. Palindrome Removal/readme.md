# 1246. Palindrome Removal

```
xxxxxx X xxxx
i      k    j
```

dp[i][j]: min num of remove to move arr[i: j]

对于每个 arr[i:j], 我们要找到最小的remove的次数：

- 那我们可以遍历 k，在 [i:j) 的范围里
- 对于每个k，如果 arr[k] == arr[j], 那删去 k, j 的代价就是 删去 arr[k+1: j-1] 的代价

```cpp
        for(int len = 3; len <= n; ++len)
        {
            for(int i = 0; i+len-1 < n; ++i)
            {
                int j = i+len-1;
                //max cost of dp[i][j] is dp[i][j-1]+1
                dp[i][j] = dp[i][j-1]+1;              
                for (int k=i; k<j; k++)
                {
                    if (arr[k]==arr[j])
                        if(k>=1) // if some part need to be remove before k
                            dp[i][j] = min(dp[i][j], dp[i][k-1]+max(1,dp[k+1][j-1]));
                        else
                            dp[i][j] = min(dp[i][j], max(1,dp[k+1][j-1]));
                } 
            }
        }
        return dp[0][n-1];
```
