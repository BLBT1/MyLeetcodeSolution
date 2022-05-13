# 560. Subarray Sum Equals K

- Brute force: 先用 prefix sum， 再用双指针遍历所有 subarray， 这样是 O(N^2)

- 用类似 2sum 的思路： Hashmap + prefix sum

  - 核心是， 如果 presum[j+1] - presum[i] = k, 那 sum(nums[i:j]) = k；也可以说，如果 presum[j+1] - k == presum[i], 那就符合条件。
  - 所以我们 用 map 记录在 j+1 前有多少个 presum[i] 满足条件
