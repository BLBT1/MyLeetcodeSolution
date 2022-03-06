# 162. Find Peak Element

- 使用二分搜索
- 考虑使用 mid的斜率，搜索方向朝向元素增大的一侧。

- 如果 nums[mid-1] < nums[mid], 如下，那 mid本身是有可能的index， 所以不能排除。 因此， l = mid

```
 1    2   3
mid-1 mid
```

- 如果 nums[mid-1] > nums[mid]，如下，那 mid-1本身是有可能的index， 所以不能排除。 因此， r = mid - 1

```
 4     2   3
mid-1 mid
```
