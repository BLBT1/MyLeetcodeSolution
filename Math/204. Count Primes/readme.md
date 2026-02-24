# 204. Count Primes

使用筛子法，核心思想是， 一个质数的倍数一定不是质数

算法如下：

1. 从 [2:n], 初始都是unmarked， 找到第一个unmarked 数 a，

2. mark所有 a*2， a*3 ... a*j, where a*j <= n

3. 反复以上过程，直到 a > sqrt(n)

4. 统计 [2:n] 中所有 unmarked 的 数

Time ：O(NlogN)

```c++
class Solution {
public:
    int countPrimes(int n) {
        // idea => 所有质数 的倍数都不是质数
        // Time O(~NlogN)
        int count = 0;
        vector<bool> isPrime(n, true);
        for(int i = 2; i < n; ++i){
            if (!isPrime[i]) continue;
            count +=1;
            for(int j = i*2; j<n; j+=i){
                isPrime[j] = false;
            }
        }
        return count;
    }
};
```
