# 1060. Missing Element in Sorted Array

- 因为是找连续的数 missing, 所以要对数值做二分搜索，　而不是对index

- 假设这个第 k个missing的元素是 mid，那么假设在从nums[0]到　m-1总共有M个连续的自然数，并且我们可以知道数组里面有多少个小于 mid 的数　T。

- 所以，我们可以计算出从nums[0]到m-1里面有多少个数是在数组里missing的。理论上我们需要missing = k-1. 这是一个必要条件。missing　= M-T

- 如何计算　Ｍ　和　Ｔ？　M　是在 [nums[0], mid)中有多少个连续的自然数, M = mid-nums[0]. 而　Ｔ　是在(nums[0], mid)有几个在 array nums 中的：T = lower_bound(nums.begin(), nums.end(), mid)-nums.begin();

```cpp
// think about a concrete example
// [1 2 3 7]
// if mid = 5
// M = 4
// T = 3
// missing is 1
```

- 如果数组中missing > k-1，那么说明 mid猜得太大。如果missing < k-1，说明m猜得太小。如果missing = k-1，说明mid可能是答案，但也有可能mid也存在于数组中从而并不是一个missing number，所以m也得继续往大猜。综上就有这样的转移：

```cpp
        if(missing < k-1)
        {
            l = mid+1;
        }
        else if(missing >k-1)
        {
            r = mid-1;
        }
        else
        {
            l = mid;
        }
```
