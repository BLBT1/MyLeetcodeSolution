# 15. 3Sum

- 经典双指针， 难点在去重，有多种可能重复，要仔细想清楚所有的情况

- 要求，i != l!= r, 所以我们 先设 i 从小到大， 这样 l，r 一定在 nums[i+1 : nums.size()] 这个区间里，避免了重复

- 要求没有重复的 triplet， 有两个情况

```cpp
    [-1, -1 -1, 0, 1, 2, -1, -4]
      i   l  l1       r             
```

1. {nums[i], nums[l], nums[r]} 和 {nums[i], nums[l1], nums[r]} 都是 {-1, -1, 2}, 所以要用以下代码去重

```cpp
                    while (l < r && nums[l] == nums[l - 1])
                        l++;
                    while (l < r && nums[r] == nums[r + 1])
                        r--;
```

2. 下一个 i+1 和 i 都是 -1， 这样也会有重复， 所以在每个 iteration 开头需要

 ```cpp
             if(i != 0 && nums[i] == nums[i-1])
                continue; 
 ```
