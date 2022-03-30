# 992. Subarrays with K Different Integers

### 为什么不能直接用滑动窗口？

- 如果我们直接用滑动窗口的话，无非就是正常移动快指针，移动到有 k个不同的数字了，再移动l，这样有问题

- 我们看一个例子：

```cpp
nums = [1, 2, 1, 2, 3]
        0  1  2  3  4
           l  r
k = 2
```

- 我们先移动 r， r到 idx 1 的位置，记录 {1，2}

- 我们再移动l到 indx 1

- 我们继续移动 r到idx 2 的位置，记录 {2，1}

- 我们再移动 l

- 这样我们已经可以发现问题了

- 因为 l是不能往左的，所以{1，2，1} 这个符合条件的case被遗漏了

### 解法

- 关键是需要联想到我们做过的 lc340，at most k char

- exact k 是 atMost(k) - atMost(k-1)

- 想到这一步之后还需要 modified code from 340
