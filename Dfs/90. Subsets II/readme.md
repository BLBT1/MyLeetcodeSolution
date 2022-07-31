# 90. Subsets II

难点在去重: sort 后 我们只希望每个 val 第一次遇到时被加入list

```cpp
    if(i != curr && nums[i] == nums[i-1]) continue;
```

看这例：

```
[1, 2, 2]
 0  1  2
```

- [1, 2] 只会来自于 (0, 1) 这两个数字。 (0, 2) 被上面的代码给删掉了

- 但是，[1, 2, 2] 这个subset还是被保留， 因为当 curr == 2 时， indx 2 位置上的 2 就被加进 List 里去了
