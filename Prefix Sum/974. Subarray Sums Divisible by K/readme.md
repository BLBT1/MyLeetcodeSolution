# 974. Subarray Sums Divisible by K

- lc560 的变种

- // subarry sum%k == 0 => (sum[j] - sum[i])%k == 0 => sum[j]%k - sum[i]%k == 0 => sum[j]%k == sum[i]%k

- 同时要注意， 不能让存的 k < 0， 比如说下面这个例子：

``` cpp
in cpp -1%k = -1
res = 0
presum = 1
mp: {0, 1}, {-1, 0}, {1: 0}, {10: 0}
[-1,2,9]
```

单独一个2, 是可以整除 2 的， 但是没有算上， 因为 -1 存在 map里了。 避免这种情况， 我们要存的是 (nums[i]%k+k)%k, 也是就是 1
