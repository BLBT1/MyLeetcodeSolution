# 790. Domino and Tromino Tiling

这题很难想到如何定义状态，但是基本是一个时间序列dp。 这题花花酱讲的很好，直接redirect:

states:
 0 -> 完全填充完
 1 -> 上面突出来一格
 2 -> 下面突出来一格

 dp[i][0] = dp[i-1][0]+dp[i-2][0] + dp[i-1][1] + dp[i-1][2]
 dp[i][1] = dp[i-2][0] + dp[i-1][2]
 dp[i][2] = dp[i-2][0] + dp[i-2][1]

[huahua solution](http://zxi.mytechroad.com/blog/dynamic-programming/leetcode-790-domino-and-tromino-tiling/)
