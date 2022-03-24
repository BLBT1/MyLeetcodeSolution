# 81. Search in Rotated Sorted Array II

与33唯一的不同是这题目中有重复数字，所以遇到重复的数字我们需要仔细思考，考虑以下example

```cpp
[1, 0, 1, 1, 1]
 0  1  2  3  4
target : 0

```

- 根据lc33思想， 我们像把他分成upper 和 lower 两个部分。 这里 upper是 [1], lower是[0 1 1 1]

- 如果我们再用nums[l]来判断mid的位置就会遇到问题，mid = 2, nums[mid] = 1 == nums[l]，mid 应该在upper，而mid这里其实是在lower里。

- 解决上述问题：

```cpp
        if (nums[mid] == target)
        {
            return true;
        }
        else if (nums[mid] == nums[l])
        {
            l++;
        }
        else if (nums[mid] == nums[r])
        {
            r--;
        }
```

- 把相等的情况去除了就可以了
