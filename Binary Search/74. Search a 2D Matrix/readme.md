# 74. Search a 2D Matrix

典型的二分搜索， 核心是如何把2d array 想成 1d array。我们知道 2d array 是 m * n 的, matrix， 所以由此可得， 如果想象成一个 1d 的 [0: m times n-1]的 array A，则如果我们考虑 ith in A， 就等同于考虑：```matrix[i/n][i%n]``` 这点理解后， 剩下的就是最基础的二分搜索

### 出while loop后

潜在的越界危险:

```
    if l = 0, r  = 1
    mid = l+(r-l)/2 = 0
    then r = mid-1 =  -1
    -1 is out of bound
    as our imagined 1d array is in range [0: m*n-1]
```

解决这个问题：

- 因为如果target 存在， 出while loop是 l一定等于r
- 所以我们用下面的代码判断就可以了

```cpp
        if (l == r && matrix[l / n][l % n] == target)
        {
            return true;
        }
        return false;
```
