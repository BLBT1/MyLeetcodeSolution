# 605. Can Place Flowers

### 基本思路
这个题无非就是从左往右 scan array， 这里 greedy 的地方就是我们像把花尽可能的往左边放。每个格子有两种可能的情况：
1. 如果当前空格有花， 那直接看往后两格子，因为花不能紧挨着放
2. 如果当前无花， 则要看前面和后面有没有花
```cpp
            if (flowerbed[i] == 1)
            {
                i += 2;
            }
            else // empty grid
            {
                if (flowerbed[i - 1] != 1 && flowerbed[i+1] != 1)
                {
                    flowerbed[i] = 1;
                    n--;
                }
                ++i;
            }
```

### 一个小技巧
```cpp
        flowerbed.push_back(0);
        flowerbed.insert(flowerbed.begin(),0);
```
这样可以防止越界

### time
O(n)

### space
O(1)