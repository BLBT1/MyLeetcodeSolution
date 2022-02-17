# 34. Find First and Last Position of Element in Sorted Array

个题目还是考验基本功的题，需要对二分搜索有一定理解的同学才能顺利解出，我一个挚友面试就遇到了这个题目的原题

## 核心要点

二分搜索的核心是：
    1. 需要返回的值绝对不能被排除
    2. 剩下的东西数量必须再减少

有了这个思想，我们来看此题，此题的核心是两个```binary search```， 第一个找到第一个target的位置， 第二个找到最后一个element的位置

### find_first_appear()

```cpp
        while (l < r)
        {
            mid = (r - l) / 2 + l;
            if (nums[mid] < target)
            {
                l = mid + 1;
            }
            else if (nums[mid] > target)
            {
                r = mid - 1;
            }
            else
            {
                r = mid;
            }
        }
```

三种情况讨论：

- 如果 nums[mid] < target, 那当前的mid肯定不是我们要的，可以直接 l = mid+1
- 如果 nums[mid] > target, 那当前的mid也肯定不是我们要的，可以直接 r = mid-1
- 如果nums[mid] == target,那我需要思考， 因为我要找到第一个 appear，所以mid是有可能我们要的，我们要缩小右边界，r，因为左边可能还有别的相同的数

```cpp
        if (l == r && nums[l] == target)
        {
            return l;
        }
        else
        {
            return -1;
        }
```

退出while loop后如果 l > r,则肯定没到target

### find_last_appear()

```cpp
        while (l < r)
        {
            mid = (r - l + 1) / 2 + l;
            if (nums[mid] < target)
            {
                l = mid + 1;
            }
            else if (nums[mid] > target)
            {
                r = mid - 1;
            }
            else
            {
                l = mid;
            }
        }
```

基本和find_first_appear相同，但是需要注意很重要的两点:

1. 如果遇到 nums[mid] == target, 因为是要找到最后一个target，所以要缩小左边界， l = mid
2. 这里会出现一个问题， 如果 l = 0， r = 1，则 mid = 0，而如果当前 nums[mid] == target, 则 l = mid。 我们会发现这种情况 l 永远 < r， 会死循环。 所以改成 mid = (r - l + 1) / 2 + l;
