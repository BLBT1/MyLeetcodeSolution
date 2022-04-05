# 259. 3Sum Smaller

- 基本思路和 3 sum 一样

- 注意，如果 sum = nums[i]+nums[l]+nums[r] < target, 那 res += j-i 我们可以看以下例子：

```cpp
nums = [-2,0,1,3], target = 2
        i  l     r
```

- 此时 sum  = 1 < 2, 如果我们直接 ++l，那 {-1， 0， 1} 的情况就被忽略了， r 可以是 1， 所以要 res += j-i
