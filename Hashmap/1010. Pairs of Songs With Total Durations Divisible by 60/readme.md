# 1010. Pairs of Songs With Total Durations Divisible by 60

### 直接思路（我的做法）

这个题目很想一个 2sum 问题，用hashmap(unordered_map<int, int>) 记{(x-nums[i]) % 60 == 0} 以及他的次数：

```cpp
            for (int k = 0; k < UPPER; k += 60)
            {
                if (k >= time[i])
                    map[k - time[i]]++;
            }
```
如果 nums[i] 在map里，则result里直接加上他的次数。
```cpp
            if (map.find(time[i]) != map.end())
            {
                res += map[time[i]];
            }
```

### time
O(1000/60 N), 这里1000 是nums里两个数相加可能的最大值

### space
O(1000/60 N)

### 寒神做法
t % 60 gets the remainder from 0 to 59.
We count the occurrence of each remainders in a array/hashmap c.

we want to know that, for each t,
how many x satisfy (t + x) % 60 = 0.

The straight forward idea is to take x % 60 = 60 - t % 60,
which is valid for the most cases.
But if t % 60 = 0, x % 60 = 0 instead of 60.

One solution is to use x % 60 = (60 - t % 60) % 60,
the other idea is to use x % 60 = (600 - t) % 60.
Not sure which one is more straight forward.
```cpp
        int numPairsDivisibleBy60(vector<int>& time) {
            vector<int> c(60);
            int res = 0;
            for (int t : time) {
                res += c[(600 - t) % 60];
                c[t % 60] += 1;
            }
            return res;
        }
```