# 1673. Find the Most Competitive Subsequence

- 和 402 是一模一样的题， 402是删去 k个，那这里就是删去最多 nums.size()-k 个

- 如果最后没用完所有的 nums.size()-k 的删去机会， pop stack 知道 size 是 k

- 这题的难点是在转换题意
