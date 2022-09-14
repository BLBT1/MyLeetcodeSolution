# 823. Binary Trees With Factors

这个题目的核心思想是乘法原理:

假设有以下 [2,6,3,4,12],

- 我们 define dp[r] => 以 r 为 root 组成满足要求的binary tree 的个数

- 那 dp[12] = (dp[2]*dp[6]) + (dp[3]*dp[4])

generalize下，就是如果 a*b = c， 那我们对于每个c，找到所有可能的a*b， 再把我们相加就是符合条件c 的个数。

需要注意的是，因为规定了每个node的数字>=1, 所以 任何 c 都是有小于他的 a，b 相乘所得， 所以我们应该sort下，从小到大开始算 dp， 这样每个都可算到
