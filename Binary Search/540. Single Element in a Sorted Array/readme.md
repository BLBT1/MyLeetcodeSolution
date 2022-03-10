# 540. Single Element in a Sorted Array

- 非常有意思的一个题，　如果第一次做可能确实没有思路，但此题的思路十分巧妙

- 因为所有的数都有出现两次，唯独有且唯一一个数出现一次，所以此题的突破口是在位置的奇偶上

- 首先，我们要对比的是　nums[mid] 和 nums[mid+1],
  - 因为我们的 mid = left + (right-left)/2
  - 假设　nums:[1,2], 那 left = 0, right = 1, mid = 0
  - 如果我们比较　nums[mid-1] 和 nums[mid]，就越界了

- 接下来，我们可以看一个concrete 的例子

```cpp
nums : [1, 1, 2, 3, 3, 4, 4, 8, 8]
index : 0  1  2  3  4  5  6  7  8
```

- 假设 nums[mid] == nums[mid+1]

- if mid is odd
  - mid = 3, mid+1 = 4, 3 == 3
  - 此时我们已经经过了　single number
  - 收敛右边　right = mid-1 (mid 所咋位置不可能是　single number)

  - if mid is even:
    - 我们看 mid = 0,mid+1 = 1 上的, 所以我们还没遇到想要的数字
    - left = mid+1, mid也不可能是我们想要的数

- 假设 nums[mid] != nums[mid+1]
  - if mid is odd:
    - 我们看　if mid = 1, mid+1 = 2 , 1 != 2, 所以我们还没遇到想要的数字,　且 mid 不可能是　single number (mid+1 有可能是 single number)
    - left = mid+1
  - if mid is even:
    - 我们看一个极端例子， mid = 1,　收敛左边， mid+1 = 2

    -此时我们已经过了我们 single number,　收敛右边，　并且 mid 本身可能是 single number (like in this case)
    - right = mid
