# 154. Find Minimum in Rotated Sorted Array II

和 153 思路基本一致，问题是如何 handle 重复的数字。 比如

```cpp
nums1:[2,2,2,0,1,2,2,2,2]
nums2:[2,3,2,2,2,2,2,2,2]
```

- 以上两个nums，mid 很难判断是在upper还是lower。 那怎么办？

- 比如[2,2,0,1,2], nums[mid] == nums[l]怎么办？

- 那我们就不看 nums[l]， l++， 就能解决

- 同样的技巧 lc81也用过

## Time Complexity

- 不再是O（nlogn），而是O(n)
- worst case：[2,2,2,2,2,2]
