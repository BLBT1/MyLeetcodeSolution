# 525. Contiguous Array

- 找相同数量的0和1，常见的技巧是把 0 都变成 -1， 这样只要sum是0就可以

- if presum[j+1] == presum[i], 那 sum(nums[i:j]) == 0
