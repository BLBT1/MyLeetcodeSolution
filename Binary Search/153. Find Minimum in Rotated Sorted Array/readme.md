# 153. Find Minimum in Rotated Sorted Array

和33 一样， 想找到的数字是lower part的第一个

## 方法 1

- 和33思想很相似，用left来标记 upper还是lower。但是需要先判断一下是否是排序数组
- 如 nums[l:r] = [11, 13, 17, 19], 这种情况需要直接返回nums[l]

```cpp
    if(nums[l] <= nums[r]) 
    {
        return nums[l];
    }
```

如果是和right比较，对于排序数组就不需要特殊考虑

## 方法 2

直接用right来标记
