# 4. Median of Two Sorted Arrays

## 解题思路

### intuit 1

假设 nums1 nums2 是两个随机分布发 arrays

```
nums1: [1 3 5 11 15]
nums2: [0 2 7 12]
```

那他们两个的中位数出现在他们两个 sorted arrays各自的中间左右的位置左右，5， 因为 5 前面有4个数，后面也有4个数

### intuit 2

思考一个更general的问题， 给两个 sorted arrays， 找到他们的 ```Kth smallest element```。 一旦我们能解决这个问题了， 那找到他们的 median 只不过是一种特殊情况

### 关键突破口

现在我们思考怎么找到两个 sorted arrays 的```Kth smallest element```。 假设 一下两个 sorted array nums1，nums2

```
        nums1: X0 X1 X2 ... X_  ... XXX
        nums2: Y0 Y1 Y2 ... Y_  ... YYYYYY
```

- 设 X0 Y0风别为两个array的第一个数
- X_和 Y_ 风别为 k/2 nums1 和nums2 中的位置
- 如此一来，那 range [X0 ... X_] + [Y0 ... Y_] 所含数字的个数就为 k 个

### 二分搜索的理解和应用

- 二分搜索的关键思想：每次排除一部分（剩余的一半） 不可能含所需值的点的区域， 以此递减所需值的可能存在的区域
- 二分搜索在此题的运用：

```
        nums1: X0 X1 X2 ... X_  ... XXX
        nums2: Y0 Y1 Y2 ... Y_  ... YYYYYY
```

思考者两个数组，

- 已知 [X0 ... X_] + [Y0 ... Y_] 所含数字的个数就为 k 个
- 也就是:
- 如果 X_< Y_, 那比 Y_小的数字包含 X_ 至少有 k-1 个， 所以 [X0 ... X_] + [Y0 to prev(Y_)] 区间里的k-1个数 都不可能是两个 sorted arrays 的```Kth smallest element```。 因此我们能认定， [X0 ... X_] 这 k/2 个数字都为 不可能含所需值的点的区域, 所以我们可以丢掉 [X0 ... X_] 这区域

```
        nums1: X...X
        nums2: Y0 Y1 Y2 ... Y_  ... YYYYYY
```

- 在剩余区间里 recursive的重复这个步骤，直到base case

- 如果 X_>= Y_, 那比 X_小的数字包含 Y_ 至少有 k-1 个， 所以 [X0 ... X_] + [X0 to prev(X_)] 区间里的k-1个数 都不可能是两个 sorted arrays 的```Kth smallest element```。 因此我们能认定， [Y0 ... Y_] 这 k/2 个数字都为 不可能含所需值的点的区域, 所以我们可以丢掉 [Y0 ... Y_] 这区域

```
        nums1: X0 X1 X2 ... X_  ... XXX
        nums2: YY  ... YYYY
```

- 在剩余区间里 recursive的重复这个步骤，直到base case

### Base Case

1. k == 1
2. one array turn to be empty

```cpp
    if (nums1Start == m)
        return nums2[nums2Start + k - 1];
    if (k == 1)
        return min(nums1[nums1Start], nums2[nums2Start]);
```
