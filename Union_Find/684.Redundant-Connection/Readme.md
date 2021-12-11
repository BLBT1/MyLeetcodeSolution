# 684 Redundant Connection

这题十分直接用union find的套路走流程就可以做出， 是对加强union find 套路掌握很好的练习，union find的基本模板可以参考 ```lc547```

## 基本思路：

每看到一个edge，如果两个点不是在同一个 ```connected component```， 就把他们用union合并成在一个 connected componen； 如果两个点已经在同一个 connected component 了， 则当前的 edge e 为多余，直接 return 他就好了

```cpp
        for (int i = 0; i < n; ++i)
        {
            auto &e = edges[i];
            if (findFather(e[0]) != findFather(e[1]))
            {
                unionfy(e[0], e[1]);
            }
            else
            {
                return e;
            }
        }
```


