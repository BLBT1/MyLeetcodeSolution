# 395. Longest Substring with At Least K Repeating Characters

要求的是最长的substr such that 里面每个char至少出现k次

- 滑动窗口的最大问题是： 每次r探索到一个新出现的char，我们就得不断向下探索知道那个char出现了k次，不过我们也不知道那个新的char是不是会出现k次，所以滑动窗口的解法就看似不可行了

- 我们需要自己增加一个规则：每个 window must contains m different characters。加了这个条件之后滑窗就可以确定了

- 固定左指针，我们想把右指针移动到越远越好，这样windows中的char就越多, 也越可能满足每个char的频次 >= k

- 所以我们遍历所有可能的 m，做滑动窗口， 因为是 lowercase，所以总共是有 26 个不同的 m
