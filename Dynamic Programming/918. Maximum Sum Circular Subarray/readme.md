# 918. Maximum Sum Circular Subarray

这题可以是 ```53 max subarray sum``` 的follow up，不同的是这里是把nums想成一个circular array。

那circular array就有额外的情况， 比如 [5, -3, 5] 这个array，作为circular array， [5 } -3, {5] => {5, 5} 是 result。

53里， 我们用 dp[i] => max subarray sum ended by i,

```cpp
    dp[i] = max(dp[i-1]+nums[i], nums[i]);
```

这个题， [5, -3, 5] 的 result其实是通过 total sum - min subarray sum 所得的。所以要同时维护一个min subarray sum， 每次用totalSum 减去他。

```cpp
        maxSum[i] = max(maxSum[i-1]+nums[i], nums[i]);
        minSum[i] = min(minSum[i-1]+nums[i], nums[i]);
        res = max(maxSum[i], res);
        res = max(totalSum - minSum[i], res);
        res = max(nums[i], res);
```

注意一个coner case， 如果所有的 element 都是负数， 那 res就会是 0， 但是最大的subarray sum是 nums里最大元素，所以return前需要特判下
