# 34. Find First and Last Position of Element in Sorted Array

此题好想但是难写。核心无非是写两遍二分搜索，找元素的第一个和左后一个的位置，但是很难BugFree。所以这题用来锻炼二分搜索很好。我一个朋友面某faang的ng就遇到了这个题。

## 核心要点：

1. 找到第一个元素的位置
    - 如果 nums[mid] >= target ，则 r = mid。 else l = mid+1；
    - 这样可以使得最后的 l 所在位置是第一个元素
```cpp
        while (l < r)
        {
            mid = l + (r - l) / 2;
            if (nums[mid] >= target)
                r = mid;
            else
                l = mid + 1;
        }
```

2. 找到最后一个元素的位置
    - 如果 nums[mid] <= target, 这 l = mid， else r = mid -1
    - 这样可以使得最后的 l 所在位置是最后第一个元素
    - 我们可以观察到一定的对称性
```cpp
        while (l < r)
        {
            mid = l + (r - l) / 2 + 1;
            if (nums[mid] <= target)
                l = mid;
            else
                r = mid - 1;
        }
```