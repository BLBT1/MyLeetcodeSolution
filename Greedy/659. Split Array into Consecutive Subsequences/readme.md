# 659. Split Array into Consecutive Subsequences

- 首先，如果过一个数字能找到之前存在的seq， 那就要他加入之前的seq。为了快速查找到是否存在这样的队列。我们可以用mp存{end of seq, num of seq}.

- 如果之前合法的队列不存在，那就需要自己当seq的头头，且看x+1和x+2是不是有。把他们用了

- 如果nums[i]都用完了，就需要continue
