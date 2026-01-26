# 90. Subsets II

难点在去重: sort 后 我们只希望每个 val 第一次遇到时被加入list

```cpp
    if(i != curr && nums[i] == nums[i-1]) continue;
```

- 但是，[1, 2, 2] 这个subset还是被保留， 因为当 curr == 2 时， indx 2 位置上的 2 就被加进 List 里去了

- 保持当curr是 0 的时候，currList 是 {}, curr是1的时候 currList 是{1}, 这样做去重的时候不用担心开头越界

- only take if nums[j] != nums[j-1] and nums[j] is not the first time we have chance to select this number

什么时候会出现重复？ 
- 当我们取了 后一个重复的数字 但是 没有取 前一个重复的数字的时候
也就是 [1,2,2']， 当我们选了 [2'] 但是没有选 [2] 的时候
