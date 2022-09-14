# 939. Minimum Area Rectangle

```
A---B
|   |
|   |
C---D
```

确定一个长方形需要几个点？ 需要两个点：A 和 D。如果知道了A，D 相应的C，D也固定了。所以 O(N^2)的解法如下

```
 for each pt i to be A:
    for each pt j to be D:
        find C, D
            if C and D in the mp:
                find area =  the area of A,B,C,D:
                    res = min(res, area)

```
