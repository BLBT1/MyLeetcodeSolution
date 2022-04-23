# 204. Count Primes

使用筛子法，核心思想是， 一个质数的倍数一定不是质数

算法如下：

1. 从 [2:n], 初始都是unmarked， 找到第一个unmarked 数 a，

2. mark所有 a*2， a*3 ... a*j, where a*j <= n

3. 反复以上过程，直到 a > sqrt(n)

4. 统计 [2:n] 中所有 unmarked 的 数

Time ：O(N)

 Space : O(N)
