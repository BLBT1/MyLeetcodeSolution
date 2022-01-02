# 416. Partition Equal Subset Sum

### 第一想法
暴力搜索， 用 ```dfs``` 搜索所有可能的 subset, 然后 either 对比所有的 sum 看是否有两个相同， or 直接看是否有一个送是 total sum 的一半。这样， 如果input 的 size 是N， 那总共有 2^N 个subset， 所以time 是 2^N。这样太慢了。这个想法的思考的切入点是从有几个 subset。但是其实我们不难发现这个办法的重复， 假设有{1，2，7}，{2，3，5}，{4，2，4} 这三个subset 同时存在， 那他们的 ```subset sum``` 就都等于10， 而我们正在需要考虑的是 ```subset sum``` ! 所以说我们需要从有几个不同的 subset sum 做切入点来思考 ！

### 更优解
```背包问题dp```这里我们需要思考的是有多少不同的 subset sum， 看一眼题目给的数据规模， 是
```
1 <= nums.length <= 200
1 <= nums[i] <= 100
```
那他的最大subset sum 是 100 * 200 = 2* 10 ^ 4， 那我们可以把 subset sum 设为 背包问题中的capacity，而 每个 nums 里的数字看作 背包问题里的 item， 那就可以用背包问题的套路来更新 【0，2* 10 ^ 4】中的每个数字是否是 由 nums 可得的 ```subset sum```。 因为我们正在care的是sum/2 是不是可得的subset sum， 所以设dp为：
```cpp
        vector<bool> dp(sum / 2, false);
```

那接着就是背包问题的套路了：第一个循环遍历所有的items， 第二个循环遍历所有的capacity。而当我们每次看到一个新的 nums 中的 x， 那我们就遍历所有的 subset sum（capacity）看是不是有可能可以由 之前的dp状态+x来得到 ！所以需要```先保存一下上一个dp的状态```：
```cpp
        for (auto x : nums) // traverse over every given items
        {
            vector<bool> dp_temp = dp;
            for (int s = 0; s <= sum / 2; ++s) // traverse over all possible capacity
            {
                if (s - x >= 0 && dp_temp[s - x])
                {
                    dp[s] = true;
                }
            }
        }
```
