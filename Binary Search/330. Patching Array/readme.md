# 330. Patching Array

- greedy: try ours best to use the num in nums to expand - the range we can reach by our sum
- if nums[i] <= miss, miss = miss+nums[i]
- else added+1, miss+1

### ex

- nums = [1, 2, 4, 13, 43], n = 100
- [0, 1) missing: 1, nums[i] <= missing
- [0, 2) missing: 2
- [0, 4) missing: 4
- [0, 8) missing: 8 nums[i] <= 8? do need to add a 8
- [0, 16) missing: 16 nums[i] < 16
- [0, 29) missing: 29, need to add 29
- [0, 58] missing 58
- [0, 101) missing 101 > n, we are all good
