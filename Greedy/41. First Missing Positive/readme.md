# 41. First Missing Positive

- index sort的贪心思想是： 我尽可能在看到的值放到他对应的位置上

- 在 [0:n) 为大小的 array里， indexing sort 能实现 O(n) 的时间来排序

### 例子

nums = [2, 3, 1, 5, 4， 0]

- idx = 0, nums[0] = 2, swap() => [1, 3, 2, 5, 4, 0]

- 因为 当前 nums[i] != i, 所以我们继续 swap => [3, 1, 2, 5,4, 0]

- swap => [5, 1, 2, 3, 4, 0]

- swap => [0, 1, 2, 3, 4, 5]

- 发现idx 0上 nums[i] == i, 继续看下一位， idx = 1, 知道 idx = n-1

### 注意一

有相同的数字， 那就会出现无线循环，这情况我们需要continue， 比如所 idx = 1; [0, 2, 2]. 两个 2 之间会无线跳转

### 注意二

负数和 >= n 的数字都会越界， 也要continue
